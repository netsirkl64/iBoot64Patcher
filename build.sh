#!/usr/bin/env bash

set -e

mkdir -p /usr/local/include

sudo cp -R include/libinsn /usr/local/include
sudo cp -R include/libgeneral /usr/local/include
sudo cp -R include/liboffsetfinder64 /usr/local/include

clang++ -std=c++11 libinsn.a libgeneral.a liboffsetfinder64.a main.cpp -o iBoot64Patcher
