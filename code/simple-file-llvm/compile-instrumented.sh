#!/usr/bin/env bash

mkdir instrumented_build
cd instrumented_build

# Step 1: Compile the preprocessed file into LLVM IR
afl-clang-fast -S -emit-llvm ../main.c -o main.ll


