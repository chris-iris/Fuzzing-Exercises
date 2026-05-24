#include <stdlib.h>
#include <stdio.h>

#include "lib.h"

void main(int argc, char** argv) {

    int fibo_input = 0;
    
    printf("Please, insert fibo index: ");
    scanf("%u", &fibo_input);

    int fibo_res = fibo(fibo_input);

    printf("Fibonacci's number for %u is %u\n", fibo_input, fibo_res);

    exit(0);
}