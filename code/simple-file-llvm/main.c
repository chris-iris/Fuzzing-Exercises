#include <stdio.h>
#include <stdlib.h>

int main(int argc, char** argv) {
    
    printf("Hello world");

    if (argc > 1) {
        printf("We have found %u args", argc);
    }
    
    /* This is required as otherwise we will segfault if 
        we manually compile everything  */
    exit(0);
}