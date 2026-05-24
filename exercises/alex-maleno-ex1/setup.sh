#!/usr/bin/env bash
mkdir build

cd build

CC=afl-clang-fast CXX=afl-clang-fast++ cmake ..
make
