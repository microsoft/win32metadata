const assert = require('node:assert/strict');
const { execFileSync } = require('node:child_process');
const { mkdirSync, mkdtempSync, readFileSync, rmSync, writeFileSync } = require('node:fs');
const { tmpdir } = require('node:os');
const path = require('node:path');
const { test } = require('node:test');

const workflow = readFileSync(path.join(__dirname, '..', 'workflows', 'pr-api-diff-comment.yml'), 'utf8')
  .replace(/\r\n/g, '\n');
const validationWorkflow = readFileSync(path.join(__dirname, '..', 'workflows', 'pr-validation.yml'), 'utf8')
  .replace(/\r\n/g, '\n');
const steps = workflowSteps(workflow);
const validationSteps = workflowSteps(validationWorkflow);
const AsyncFunction = Object.getPrototypeOf(async function () {}).constructor;

function workflowSteps(source) {
  return new Map(source.split(/^      - name: /m).slice(1).map(block => {
    const endOfName = block.indexOf('\n');
    return [block.slice(0, endOfName), block.slice(endOfName + 1)];
  }));
}

function validationJob(name) {
  const marker = `  ${name}:\n`;
  const start = validationWorkflow.indexOf(marker);
  assert.notEqual(start, -1, `Missing validation job: ${name}`);
  return validationWorkflow.slice(start + marker.length).split(/^  [\w-]+:\s*$/m)[0];
}

function script(name) {
  const step = steps.get(name);
  assert.ok(step, `Missing workflow step: ${name}`);
  const marker = '          script: |\n';
  const start = step.indexOf(marker);
  assert.notEqual(start, -1, `Missing inline script: ${name}`);
  return new AsyncFunction('github', 'context', 'core', 'require',
    step.slice(start + marker.length).replace(/^ {12}/gm, ''));
}

const checkArtifact = script('Check API diff artifact');
const postComment = script('Post API diff comment');
const oversizedPatch = [
  'diff --git a/bin/baseline.apidump.cs b/bin/current.apidump.cs',
  '--- a/bin/baseline.apidump.cs',
  '+++ b/bin/current.apidump.cs',
  '@@ -1,4000 +1,8000 @@',
  ...Array.from({ length: 4000 }, (_, index) => `-public const int OldValue${index} = ${index};`),
  ...Array.from({ length: 8000 }, (_, index) => `+public const int NewValue${index} = ${index};`)
].join('\r\n') + '\r\n';

function fixture(documentationOnly = false) {
  return {
    run: {
      id: 38792701013,
      run_attempt: 1,
      head_sha: 'f13cd4266f5e89a019643a89488769d57ce1a090',
      head_branch: 'documentation',
      head_repository: { owner: { login: 'contributor' } },
      html_url: 'https://github.com/microsoft/win32metadata/actions/runs/38792701013'
    },
    artifacts: documentationOnly ? [] : [{
      id: 123,
      name: 'api-diff',
      expired: false,
      created_at: '2026-10-15T19:18:11Z'
    }],
    jobs: [{
      name: 'Build, test, package',
      run_id: 38792701013,
      run_attempt: 1,
      head_sha: 'f13cd4266f5e89a019643a89488769d57ce1a090',
      status: 'completed',
      conclusion: 'success',
      started_at: '2026-10-15T19:18:06Z',
      completed_at: '2026-10-15T19:18:13Z',
      steps: [
        { name: 'Documentation-only change', status: 'completed', conclusion: documentationOnly ? 'success' : 'skipped' },
        { name: 'Generate API surface diff', status: 'completed', conclusion: documentationOnly ? 'skipped' : 'success' },
        { name: 'Upload API diff', status: 'completed', conclusion: documentationOnly ? 'skipped' : 'success' }
      ]
    }],
    patch: '+added\n-removed\n',
    existingComments: []
  };
}

async function runWorkflow(data) {
  const outputs = {};
  const downloads = [];
  const comments = [];
  const requests = [];
  const actions = {
    listWorkflowRunArtifacts() {},
    listJobsForWorkflowRunAttempt() {}
  };
  const pulls = { list() {} };
  const issues = {
    listComments() {},
    async createComment(comment) { comments.push({ action: 'create', ...comment }); },
    async updateComment(comment) { comments.push({ action: 'update', ...comment }); }
  };
  const repo = { owner: 'microsoft', repo: 'win32metadata' };
  const github = {
    rest: { actions, pulls, issues },
    async paginate(method, parameters) {
      requests.push({ method, parameters });
      if (method === actions.listWorkflowRunArtifacts) {
        assert.deepEqual(parameters, { ...repo, run_id: data.run.id, per_page: 100 });
        if (data.artifactsError) throw data.artifactsError;
        return data.artifacts;
      }
      if (method === actions.listJobsForWorkflowRunAttempt) {
        assert.deepEqual(parameters, {
          ...repo, run_id: data.run.id, attempt_number: data.run.run_attempt, per_page: 100
        });
        if (data.jobsError) throw data.jobsError;
        return data.jobs;
      }
      if (method === pulls.list) {
        assert.deepEqual(parameters, {
          ...repo, state: 'all', head: 'contributor:documentation', per_page: 100
        });
        return [{ number: 42, head: { sha: data.run.head_sha } }];
      }
      assert.equal(method, issues.listComments);
      assert.deepEqual(parameters, { ...repo, issue_number: 42, per_page: 100 });
      return data.existingComments;
    }
  };
  const context = { repo, payload: { workflow_run: data.run } };
  const core = {
    setOutput(name, value) { outputs[name] = value; },
    info() {},
    setFailed(message) { throw new Error(message); }
  };
  const loadModule = name => {
    if (name === 'path') return path;
    assert.equal(name, 'fs');
    return {
      existsSync(file) {
        assert.equal(file, path.join('artifact', 'api-diff.patch'));
        return data.patch !== undefined;
      },
      readFileSync(file, encoding) {
        assert.equal(file, path.join('artifact', 'api-diff.patch'));
        assert.equal(encoding, 'utf8');
        return data.patch;
      }
    };
  };

  await checkArtifact(github, context, core, loadModule);
  if (outputs.available === 'true') {
    downloads.push('api-diff');
    await postComment(github, context, core, loadModule);
  }
  return { outputs, downloads, comments, requests };
}

test('download and comment both require the preflight output', () => {
  for (const name of ['Download API diff artifact', 'Post API diff comment']) {
    assert.match(steps.get(name), /^        if: steps\.artifact\.outputs\.available == 'true'$/m);
  }
  const download = steps.get('Download API diff artifact');
  assert.match(download, /^          name: api-diff$/m);
  assert.match(download, /^          path: artifact$/m);
  assert.match(download, /^          github-token: \$\{\{ secrets\.GITHUB_TOKEN \}\}$/m);
  assert.match(download, /^          run-id: \$\{\{ github\.event\.workflow_run\.id \}\}$/m);
  assert.doesNotMatch(workflow, /uses: actions\/checkout/);
});

test('both artifact uploads still include the generated patch', () => {
  const upload = validationSteps.get('Upload API diff');
  assert.match(upload, /^          name: api-diff$/m);
  assert.match(upload, /^          path: bin\/api-diff\.patch$/m);
  const winmdUpload = validationSteps.get('Upload winmd and API dump');
  assert.match(winmdUpload, /^          name: winmd$/m);
  for (const file of ['Windows.Win32.winmd', 'current.apidump.cs', 'baseline.apidump.cs', 'api-diff.patch']) {
    assert.ok(winmdUpload.includes(`            bin/${file}\n`));
  }
});

test('full SDK scrapes have a bounded two-hour budget while build and test keep one hour', () => {
  assert.match(validationJob('scrape'), /^    timeout-minutes: 120$/m);
  assert.match(validationJob('build-test'), /^    timeout-minutes: 60$/m);
});

for (const [jobName, uploadCount] of [['scrape', 1], ['build-test', 2]]) {
  test(`${jobName} always-run local uploads require a successful checkout`, () => {
    const job = validationJob(jobName);
    assert.match(job, /^      - uses: actions\/checkout@[^\n]+\n        id: checkout$/m);
    const uploads = [...workflowSteps(job).values()].filter(step =>
      /^        uses: \.\/\.github\/actions\/upload-artifact-with-retry$/m.test(step) &&
      /^        if: always\(\)/m.test(step));
    assert.equal(uploads.length, uploadCount);
    for (const upload of uploads) {
      const condition = upload.match(/^        if: (.+)$/m)[1];
      const shouldUpload = new Function('needs', 'steps', 'always', `return (${condition});`);
      const needs = { changes: { outputs: { build_needed: 'true' } } };
      for (const outcome of ['', 'skipped', 'failure', 'cancelled']) {
        assert.equal(shouldUpload(needs, { checkout: { outcome } }, () => true), false,
          `Local action must not load after checkout outcome ${JSON.stringify(outcome)}.`);
      }
      assert.equal(shouldUpload(needs, { checkout: { outcome: 'success' } }, () => true), true,
        'Diagnostics must still upload after later build or test failures.');
      if (jobName === 'build-test') {
        needs.changes.outputs.build_needed = 'false';
        assert.equal(shouldUpload(needs, { checkout: { outcome: 'success' } }, () => true), false);
      }
    }
  });
}

test('failed prerequisite scrapes still fail before checkout without masking the primary error', () => {
  const job = validationJob('build-test');
  const verify = workflowSteps(job).get('Verify scrape jobs');
  const condition = verify.match(/^        if: (.+)$/m)[1];
  const shouldFail = new Function('needs', `return (${condition});`);
  for (const result of ['failure', 'cancelled', 'skipped']) {
    assert.equal(shouldFail({
      changes: { outputs: { build_needed: 'true' } }, scrape: { result }
    }), true);
  }
  assert.equal(shouldFail({
    changes: { outputs: { build_needed: 'true' } }, scrape: { result: 'success' }
  }), false);
  assert.equal(shouldFail({
    changes: { outputs: { build_needed: 'false' } }, scrape: { result: 'skipped' }
  }), false);
  assert.ok(job.indexOf('      - name: Verify scrape jobs\n') <
    job.indexOf('      - uses: actions/checkout@'));
  assert.doesNotMatch(verify, /continue-on-error: true/);
  const command = verify.match(/^        run: (.+)$/m)[1];
  assert.throws(() => execFileSync('pwsh',
    ['-NoLogo', '-NoProfile', '-NonInteractive', '-Command', command], { windowsHide: true }),
  error => error.status !== 0 &&
    /One or more header scrape jobs did not succeed\./.test(error.stderr.toString()));
});

for (const [name, patch, expectedOutputs] of [
  ['an oversized diff', oversizedPatch, { has_diff: 'true', additions: '8000', deletions: '4000' }],
  ['an empty diff', '', { has_diff: 'false' }]
]) {
  test(`the producer preserves ${name} byte-for-byte`, () => {
    const directory = mkdtempSync(path.join(tmpdir(), 'win32metadata-api-diff-'));
    try {
      const baselineDirectory = path.join(directory, 'bin', 'baseline-artifact');
      mkdirSync(baselineDirectory, { recursive: true });
      writeFileSync(path.join(baselineDirectory, 'Windows.Win32.winmd'), '');
      writeFileSync(path.join(directory, 'expected.patch'), patch);
      const outputFile = path.join(directory, 'step-output.txt');
      const step = validationSteps.get('Generate API surface diff');
      const marker = '        run: |\n';
      const start = step.indexOf(marker);
      assert.notEqual(start, -1, 'Missing inline diff producer');
      const producer = step.slice(start + marker.length).replace(/^ {10}/gm, '');
      const commands = String.raw`
        function dotnet { $global:LASTEXITCODE = 0 }
        function cmd {
          if ($args.Count -ne 2 -or $args[0] -ne '/c' -or
              $args[1] -ne 'git diff --no-index --unified=3 bin\baseline.apidump.cs bin\current.apidump.cs > bin\api-diff.patch 2>&1') {
            throw 'Unexpected diff command'
          }
          Copy-Item -LiteralPath expected.patch -Destination bin\api-diff.patch
          $global:LASTEXITCODE = ${patch.length === 0 ? 0 : 1}
        }
      `;
      execFileSync('pwsh', ['-NoLogo', '-NoProfile', '-NonInteractive', '-Command', commands + producer], {
        cwd: directory,
        env: { ...process.env, GITHUB_OUTPUT: outputFile },
        windowsHide: true
      });
      const actual = readFileSync(path.join(directory, 'bin', 'api-diff.patch'));
      assert.ok(actual.equals(Buffer.from(patch)), `Patch changed: expected ${Buffer.byteLength(patch)} bytes, got ${actual.length}`);
      const outputs = Object.fromEntries(readFileSync(outputFile, 'utf8').trim().split(/\r?\n/).map(line => line.split('=')));
      assert.deepEqual(outputs, expectedOutputs);
    } finally {
      rmSync(directory, { recursive: true, force: true });
    }
  });
}

test('recorded documentation-only execution skips the download and comment', async () => {
  const result = await runWorkflow(fixture(true));
  assert.deepEqual(result.outputs, { available: 'false' });
  assert.deepEqual(result.downloads, []);
  assert.deepEqual(result.comments, []);
  assert.equal(result.requests.length, 2);
});

test('a current build artifact downloads and posts the actual diff', async () => {
  const result = await runWorkflow(fixture());
  assert.deepEqual(result.outputs, { available: 'true' });
  assert.deepEqual(result.downloads, ['api-diff']);
  assert.equal(result.comments.length, 1);
  assert.equal(result.comments[0].action, 'create');
  assert.equal(result.comments[0].issue_number, 42);
  assert.match(result.comments[0].body, /\+1 additions \/ -1 deletions/);
  assert.match(result.comments[0].body, /\+added\n-removed/);
  assert.doesNotMatch(result.comments[0].body, /Diff truncated/);
});

test('an oversized diff retains full statistics and links to the complete artifact', async () => {
  const data = fixture();
  data.patch = oversizedPatch;
  const result = await runWorkflow(data);
  const body = result.comments[0].body;
  assert.match(body, /\+8000 additions \/ -4000 deletions/);
  assert.ok(body.includes('Diff truncated'));
  assert.ok(body.includes(`[api-diff artifact](${data.run.html_url}#artifacts)`));
  assert.ok(body.length <= 65536, `Comment is ${body.length} characters`);
  assert.ok(!body.includes('+public const int NewValue7999 = 7999;'));
  assert.equal(data.patch, oversizedPatch);
});

for (const [name, patch] of [
  ['wrapper and truncation notice', '+' + 'x'.repeat(65500)],
  ['long Markdown fences', '+' + '`'.repeat(34000) + '\n'],
  ['many backtick runs', '+`value`\n'.repeat(70000)]
]) {
  test(`the complete comment fits the limit including ${name}`, async () => {
    const data = fixture();
    data.patch = patch;
    const result = await runWorkflow(data);
    const body = result.comments[0].body;
    assert.ok(body.length <= 65536, `Comment is ${body.length} characters`);
    assert.ok(body.includes('Diff truncated'));
    assert.ok(body.startsWith('<!-- win32metadata-api-diff -->'));
    assert.match(body, /<\/details>\n/);
    assert.ok(body.endsWith('> This comment is automatically updated on each push.'));
  });
}

test('backticks in an untruncated diff remain inside its Markdown fence', async () => {
  const data = fixture();
  data.patch = '+```embedded fence```\n';
  const result = await runWorkflow(data);
  assert.ok(result.comments[0].body.includes('````diff\n' + data.patch + '\n````'));
  assert.doesNotMatch(result.comments[0].body, /Diff truncated/);
});

test('an empty actual patch still posts no API differences', async () => {
  const data = fixture();
  data.patch = ' \r\n';
  const result = await runWorkflow(data);
  assert.deepEqual(result.downloads, ['api-diff']);
  assert.equal(result.comments.length, 1);
  assert.match(result.comments[0].body, /No API differences vs the baseline/);
});

test('an existing API diff comment is still updated', async () => {
  const data = fixture();
  data.existingComments = [{ id: 456, body: '<!-- win32metadata-api-diff --> old diff' }];
  const result = await runWorkflow(data);
  assert.equal(result.comments.length, 1);
  assert.equal(result.comments[0].action, 'update');
  assert.equal(result.comments[0].comment_id, 456);
});

test('a later attempt uses its own producer evidence', async () => {
  const data = fixture(true);
  data.run.run_attempt = 2;
  data.jobs[0].run_attempt = 2;
  const result = await runWorkflow(data);
  assert.deepEqual(result.outputs, { available: 'false' });
  assert.deepEqual(result.comments, []);
});

const failures = [
  ['a real build missing its artifact', false, data => { data.artifacts = []; }, /not a confirmed documentation-only build/],
  ['an expired artifact', false, data => { data.artifacts[0].expired = true; }, /expired/],
  ['missing artifact expiration metadata', false, data => { delete data.artifacts[0].expired; }, /expiration status/],
  ['duplicate named artifacts', false, data => { data.artifacts.push({ ...data.artifacts[0], id: 124 }); }, /at most one api-diff artifact/],
  ['an expired artifact despite docs-only steps', true, data => { data.artifacts = [{ name: 'api-diff', expired: true }]; }, /expired/],
  ['a missing build job', true, data => { data.jobs = []; }, /Expected one build job/],
  ['ambiguous build jobs', true, data => { data.jobs.push(structuredClone(data.jobs[0])); }, /Expected one build job/],
  ['a renamed producer job', true, data => { data.jobs[0].name = 'Unexpected producer'; }, /Expected one build job/],
  ['a mismatched producer run', true, data => { data.jobs[0].run_id++; }, /mismatched execution metadata/],
  ['a mismatched producer attempt', true, data => { data.run.run_attempt = 2; }, /mismatched execution metadata/],
  ['a mismatched producer head', true, data => { data.jobs[0].head_sha = 'another-head'; }, /mismatched execution metadata/],
  ['an incomplete producer job', true, data => { data.jobs[0].status = 'in_progress'; }, /incomplete or mismatched/],
  ['an unsuccessful producer job', true, data => { data.jobs[0].conclusion = 'failure'; }, /incomplete or mismatched/],
  ['missing producer steps', true, data => { delete data.jobs[0].steps; }, /incomplete or mismatched/],
  ['a missing docs-only step', true, data => { data.jobs[0].steps.shift(); }, /not a confirmed documentation-only build/],
  ['ambiguous docs-only steps', true, data => { data.jobs[0].steps.push({ ...data.jobs[0].steps[0] }); }, /not a confirmed documentation-only build/],
  ['an incomplete docs-only step', true, data => { data.jobs[0].steps[0].status = 'in_progress'; }, /not a confirmed documentation-only build/],
  ['an unsuccessful docs-only step', true, data => { data.jobs[0].steps[0].conclusion = 'failure'; }, /not a confirmed documentation-only build/],
  ['missing generation evidence', true, data => { data.jobs[0].steps.splice(1, 1); }, /not a confirmed documentation-only build/],
  ['diff generation that was not skipped', true, data => { data.jobs[0].steps[1].conclusion = 'success'; }, /not a confirmed documentation-only build/],
  ['an upload that was not skipped', true, data => { data.jobs[0].steps[2].conclusion = 'success'; }, /not a confirmed documentation-only build/],
  ['an artifact with docs-only producer steps', true, data => { data.artifacts = fixture().artifacts; }, /expected producer steps/],
  ['a previous attempt artifact', false, data => {
    data.run.run_attempt = 2;
    data.jobs[0].run_attempt = 2;
    data.jobs[0].started_at = '2026-10-15T20:00:00Z';
    data.jobs[0].completed_at = '2026-10-15T20:01:00Z';
  }, /not created during the triggering build attempt/],
  ['a later attempt artifact', false, data => { data.artifacts[0].created_at = '2026-10-15T20:00:00Z'; }, /not created during the triggering build attempt/],
  ['an invalid artifact timestamp', false, data => { data.artifacts[0].created_at = 'invalid'; }, /not created during the triggering build attempt/],
  ['a missing build timestamp', false, data => { delete data.jobs[0].started_at; }, /not created during the triggering build attempt/],
  ['a missing run attempt', true, data => { delete data.run.run_attempt; }, /missing its ID, attempt, or head SHA/],
  ['an artifact API failure', true, data => { data.artifactsError = new Error('artifacts API unavailable'); }, /artifacts API unavailable/],
  ['a jobs API failure', true, data => { data.jobsError = new Error('jobs API unavailable'); }, /jobs API unavailable/],
  ['a downloaded artifact missing the patch', false, data => { delete data.patch; }, /API diff artifact is missing/]
];

for (const [name, documentationOnly, change, message] of failures) {
  test(`rejects ${name}`, async () => {
    const data = fixture(documentationOnly);
    change(data);
    await assert.rejects(runWorkflow(data), message);
  });
}
