#!/usr/bin/env bash

# check for build dir
if [ ! -d "./build" ]; then
    mkdir ./build
fi

cd ./build

cpp -o main.i ../main.c
cpp -o lib.i ../lib.c

cc -S main.i -o main.s
cc -S lib.i -o lib.s

as main.s -o main.o
as lib.s -o lib.o

ld -o main main.o lib.o \
    /usr/lib/x86_64-linux-gnu/crt1.o /usr/lib/x86_64-linux-gnu/crti.o \
    /usr/lib/x86_64-linux-gnu/crtn.o /usr/lib/gcc/x86_64-linux-gnu/14/crtbegin.o \
    /usr/lib/gcc/x86_64-linux-gnu/14/crtend.o  \
    -lc -dynamic-linker /usr/lib/x86_64-linux-gnu/ld-linux-x86-64.so.2