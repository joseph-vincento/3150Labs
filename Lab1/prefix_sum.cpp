#include "prefix_sum.h"

int sum(int arry[], int length) {
    int sum = 0;
    for(int i = 0; i < length; i++) {
        sum += arry[i];
    }

    return sum;
}

bool non_neg_prefix_sum(int arry[], int length) {
    // Return true if the running sum of elements in the array is always 0 or more
    // returns false otherwise, i.e. if the sum is ever < 0
    bool no_neg_prefixs_found = true;
    int sum = 0;
    for(int i = 0; i < length; i++) {
        sum += arry[i];
        if (sum < 0) {
            no_neg_prefixs_found = false;
            break;
        }
    }

    return no_neg_prefixs_found;
}

bool non_pos_prefix_sum(int arry[], int length) {
    // Returns true if the running sum of elements in the array is always 0 or less
    // returns false otherwise, i.e. if the sum in ever > 0
    bool no_pos_prefixs_found = true;
    int sum = 0;
    for(int i = 0; i < length; i++) {
        sum += arry[i];
        if (sum > 0) {
            no_pos_prefixs_found = false;
            break;
        }
    }

    return no_pos_prefixs_found;
}
