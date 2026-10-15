const assert = require('node:assert/strict');
const { readFileSync } = require('node:fs');
const path = require('node:path');
const { test } = require('node:test');

const workflow = readFileSync(path.join(__dirname, '..', 'workflows', 'pr-api-diff-comment.yml'), 'utf8')
  .replace(/\r\n/g, '\n');
const steps = new Map(workflow.split(/^      - name: /m).slice(1).map(block => {
  const endOfName = block.indexOf('\n');
  return [block.slice(0, endOfName), block.slice(endOfName + 1)];
}));
const AsyncFunction = Object.getPrototypeOf(async function () {}).constructor;

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
