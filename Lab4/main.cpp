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

    // init a base array of size 2n + 1
    // fill elements [0...n] w/ 1
    // fill elements [n...2n+1] 2/ -1
    int arr_size = (2 * n) + 1;
    int base_arr[arr_size];
    for(int i = 0; i < n; i++) {
        base_arr[i] = 1;
    }
    for(int i = n; i < arr_size; i++) {
        base_arr[i] = -1;
    }

    int num_well_formed = 0;
    int num_thrown_out = 0;
    int print_count = 1;

    for(int i = 0; i < iters; i++) {
        // make a copy of the base array
        int arr_copy[arr_size];
        copy(base_arr, base_arr + arr_size, arr_copy);

        // shuffle the array copy using the cstdlib random number generator
        fisher_yates_shuffle(arr_copy, arr_size, &rand);

        if(arr_copy[0] == -1) {
            num_thrown_out++;
            continue;
        }
        
        int current_depth = 0;
        int lowest_depth = 0;
        int lowest_index = 0;
        for(int i = 0; i < arr_size; i++) {
            current_depth += arr_copy[i];
            if(current_depth < lowest_depth) {
                lowest_depth = current_depth;
                lowest_index = i;
            }
        }

        int p1[lowest_index];
        int p2[arr_size - (lowest_index + 1)];
        int p3[arr_size - 1];

        // fill p1 will values from arr_copy[0...lowest_index]
        // ignore trailing -1
        for(int i = 0; i < lowest_index; i++) {
            p1[i] = arr_copy[i];
        }

        //fill p2 with values from arr_copy[lowest_index...2n+1]
        for(int i = 0; i < (arr_size - (lowest_index + 1)); i++) {
            p2[i] = arr_copy[lowest_index + i + 1];
        }

        // concat p2 and p1 into p3
        for(int j = 0; j < (arr_size - (lowest_index + 1)); j++) {
            p3[j] = p2[j];
        }
        for(int j = 0; j < lowest_index; j++) {
            p3[arr_size - lowest_index - 1 + j] = p1[j];
        }
        

        // determine if shuffled array is well formed
        //keep count of hom many arrays are well formed
        if(is_well_formed_array(p3, arr_size - 1) == true) {
            num_well_formed++;
            cout << "Well formed array #" << print_count << ": ";
            for(int j = 0; j < arr_size - 1; j++) {
                cout << p3[j] << " ";
            }
            cout << endl;
            print_count++;
        } else {
            cout << "Mismatched array: #" << print_count << ": ";
            for(int j = 0; j < arr_size - 1; j++) {
                cout << p3[j] << " ";
            }
            cout << endl;
            print_count++;
        } 
    }

    cout << num_thrown_out << " out of " << iters << " shuffled arrays were immediately discarded for beginning with -1." 
            << endl;
    cout << num_well_formed << " out of " << iters << " shuffled arrays were well formed, or " 
            << ((float)num_well_formed / iters) * 100 << "%" << endl;   
}