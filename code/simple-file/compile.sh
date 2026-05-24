#!/usr/bin/env bash

# Preprocess our file including everything in the library
cpp main.c -o main.i

# Compile our pre-processed file into assembly with the compiler
cc -S main.i -o main.s

# Assemble our assembly file into an object file
as main.s -o main.o

# Link (dynamically) our object file with missing info from standard library (glibc)
ld -o main main.o -lc --entry main -dynamic-linker /usr/lib/x86_64-linux-gnu/ld-linux-x86-64.so.2

