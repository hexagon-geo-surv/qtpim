# Copyright (C) 2026 The Qt Company Ltd.
# SPDX-License-Identifier: BSD-3-Clause

add_subdirectory(dummyplugin)
add_subdirectory(dummyotherplugin)
add_subdirectory(dummyplugincopy)
# dummypluginempty and dummyplugininvalid are excluded: Qt 6 QFactoryLoader deduplicates
# plugins by key, so only one plugin per key survives. These shims (managerName="" and
# managerName="invalid") would win over testdummy non-deterministically and break the test.
# Reserved-name handling is already covered by static factory tests in the test executable.
add_subdirectory(unittest)
