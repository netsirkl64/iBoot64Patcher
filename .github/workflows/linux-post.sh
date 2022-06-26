#!/usr/bin/env bash

set -e
export TMPDIR=/tmp
export WORKFLOW_ROOT=${TMPDIR}/Builder/repos/iBoot64Patcher/.github/workflows
export DEP_ROOT=${TMPDIR}/Builder/repos/iBoot64Patcher/dep_root
export BASE=${TMPDIR}/Builder/repos/iBoot64Patcher/

cd ${BASE}
export iBoot64Patcher_VERSION=$(git rev-list --count HEAD | tr -d '\n')
cd ${WORKFLOW_ROOT}
echo "iBoot64Patcher-Linux-x86_64-Build_${iBoot64Patcher_VERSION}-RELEASE.tar.xz" > name1.txt
echo "iBoot64Patcher-Linux-x86_64-Build_${iBoot64Patcher_VERSION}-DEBUG.tar.xz" > name2.txt
cp -RpP "${BASE}/cmake-build-release-x86_64/iBoot64Patcher" iBoot64Patcher
tar cpPJvf "iBoot64Patcher1.tar.xz" iBoot64Patcher
cp -RpP "${BASE}/cmake-build-debug-x86_64/iBoot64Patcher" iBoot64Patcher
tar cpPJvf "iBoot64Patcher2.tar.xz" iBoot64Patcher
