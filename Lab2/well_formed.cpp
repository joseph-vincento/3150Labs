#include "well_formed.h"

bool is_well_formed_array(int* arr, int length) {
    /*
    Determines if an array is well formed by calculating its prefix sum.
    Given an array of matching symbols, represented as +1 or -1, an array if well formed
    if the running sum is always greater than or equal to 0 and if the total sum equal 0.
    [(, ), (, )] -> [1, -1, 1, -1 ] returns true, this is a well formed array
    [(, ), (, ), (] - > [1, -1, 1, -1, 1] returns false, this array contains an extra open parentheses
    [(, ), ), (] -> [1, -1, -1, 1] returns false, this array contains a closed parentheses that is not preceded by a matching open parentheses
    */

    int sum = 0;

    for(int i = 0; i < length; i++) {
        sum += arr[i];
        if(sum < 0) {
            return false;
        }
    }

    if(sum == 0) {
        return true;
    } else {
        return false;
    }
}