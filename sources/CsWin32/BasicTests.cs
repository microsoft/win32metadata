// Copyright (c) Microsoft Corporation. All rights reserved.
// Licensed under the MIT license. See LICENSE file in the project root for full license information.

using System;
using Microsoft.Windows.Sdk;

public class BasicTests
{
    public void GetTickCount_Nonzero()
    {
        uint result = PInvoke.GetTickCount();
    }
}
