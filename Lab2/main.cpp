#include <iostream>
#include <cstdlib>
#include <ctime>
#include <math.h>
#include "fisher_yates.h"
#include "well_formed.h"

using namespace std;

int main() {
    // seed the random number generator witht he current time
    srand(time(nullptr));

    int n;
    int iters;

    cout << "Enter a value for n: ";
    cin >> n;
    cout << "Enter a number of iterations to run: ";
    cin >> iters;

    // init a base array of size 2n and fill with alternating +1/-1
    int arr_size = 2 * n;
    int base_arr[arr_size];
    for(int i = 0; i < arr_size; i++) {
        base_arr[i] = pow(-1, i);
    }

    int num_well_formed = 0;

    for(int i = 0; i < iters; i++) {
        // make a copy of the base array
        int arr_copy[arr_size];
        copy(base_arr, base_arr + arr_size, arr_copy);

        // shuffle the array copy using the cstdlib random number generator
        fisher_yates_shuffle(arr_copy, arr_size, &rand);

        // determine if shuffled array is well formed
        //keep count of hom many arrays are well formed
        if(is_well_formed_array(arr_copy, arr_size) == true) {
            num_well_formed++;
            // cout << "Well formed array: ";
            // for(int j = 0; j < arr_size; j++) {
            //     cout << arr_copy[j] << " ";
            // }
            // cout << endl;
        } else {
            // cout << "Mismatched array: ";
            // for(int j = 0; j < arr_size; j++) {
            //     cout << arr_copy[j] << " ";
            // }
            // cout << endl;
        } 
    }

    cout << num_well_formed << " out of " << iters << " arrays were well formed, or " 
            << ((float)num_well_formed / iters) * 100 << "%" << endl;   
}