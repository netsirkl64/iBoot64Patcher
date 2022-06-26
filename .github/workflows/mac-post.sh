#!/usr/bin/env zsh

set -e
export WORKFLOW_ROOT=/Users/runner/work/iBoot64Patcher/iBoot64Patcher/.github/workflows
export DEP_ROOT=/Users/runner/work/iBoot64Patcher/iBoot64Patcher/dep_root
export BASE=/Users/runner/work/iBoot64Patcher/iBoot64Patcher/

cd ${BASE}
export iBoot64Patcher_VERSION=$(git rev-list --count HEAD | tr -d '\n')
tar cpPJf "iBoot64Patcher-macOS-x86_64-Build_${iBoot64Patcher_VERSION}-RELEASE.tar.xz" -C cmake-build-release-x86_64 iBoot64Patcher
tar cpPJf "iBoot64Patcher-macOS-x86_64-Build_${iBoot64Patcher_VERSION}-DEBUG.tar.xz" -C cmake-build-debug-x86_64 iBoot64Patcher
tar cpPJf "iBoot64Patcher-macOS-arm64-Build_${iBoot64Patcher_VERSION}-RELEASE.tar.xz" -C cmake-build-release-arm64 iBoot64Patcher
tar cpPJf "iBoot64Patcher-macOS-arm64-Build_${iBoot64Patcher_VERSION}-DEBUG.tar.xz" -C cmake-build-debug-arm64 iBoot64Patcher
