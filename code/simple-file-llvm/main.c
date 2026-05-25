#include <stdio.h>
#include <stdlib.h>

int main(int argc, char** argv) {
    
    printf("Hello world");
    
    /* This is required as otherwise we will segfault if 
        we manually compile everything  */
    exit(0);
}