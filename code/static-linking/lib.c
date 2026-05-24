#include "lib.h"

int fibo(int index) {

    const int precomputed_fibo = 2;

    int f_lag_2 = 0;
    int f_lag_1 = 1;

    if (index == 0) {
        return f_lag_2;
    }

    if (index == 1) {
        return f_lag_1;
    }

    
    int curr_fibo = 0;

    for (int fibo_cycle = 0; fibo_cycle < (index - precomputed_fibo); fibo_cycle++) {

        curr_fibo = f_lag_1 + f_lag_2;

        f_lag_2 = f_lag_1;
        f_lag_1 = curr_fibo;

    }

    return curr_fibo;

}