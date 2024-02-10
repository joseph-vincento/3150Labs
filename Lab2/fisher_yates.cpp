#include "fisher_yates.h"

void fisher_yates_shuffle(int* arr, int length, int (*random_function)()) {
    // https://en.wikipedia.org/wiki/Fisher%E2%80%93Yates_shuffle

    for (int i = length - 1; i > 0; i--) {
        // generate a random index between 0 and length
        int swap_position = random_function() % length;
        
        // don't swap if the random swap poisiton is the same as the current index
        if (i != swap_position) {
            swap(&arr[i], &arr[swap_position]);
        }
    }
}

void swap(int* x, int* y) {
    // swap the data pointed to by x with the data pointed to by y
    int temp = *x;
    *x = *y;
    *y = temp;
}