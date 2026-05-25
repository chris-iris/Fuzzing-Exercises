#!/usr/bin/env bash

# Step 1: Preprocess our source file (using clang's preprocessor)
clang -E main.c -o main.i

# Step 2: Compile the preprocessed file into LLVM IR
clang -S -emit-llvm -O0 main.i -o main.ll

# Step 3: Compile LLVM IR into assembly
llc main.ll -o main.s

# Step 4: Assemble our assembly file into an object file
as main.s -o main.o

# Step 5: Link dynamically with libc
ld -o main main.o -lc --entry main -dynamic-linker /usr/lib/x86_64-linux-gnu/ld-linux-x86-64.so.2
