#include <iostream>
#include "prefix_sum.h"

using namespace std;

int main() {
    //int arry1[] = {1, -1, 1, -1};
    //int arry2[] = {1, -1, -1, 1};
    int arry1[] = {-5, -1, 6, -2};
    int arry2[] = {4, -3, 2, 3};
    cout << sum(arry1, sizeof(arry1)/sizeof(arry1[0])) << endl;
    cout << "non_neg_prefix_sum on arry1: " << non_neg_prefix_sum(arry1, sizeof(arry1)/sizeof(arry1[0])) << endl;
    cout << "non_pos_prefix_sum on arry1: " << non_pos_prefix_sum(arry1, sizeof(arry1)/sizeof(arry1[0])) << endl;
    cout << sum(arry2, sizeof(arry2)/sizeof(arry2[0])) << endl;
    cout << "non_neg_prefix_sum on arry2: " << non_neg_prefix_sum(arry2, sizeof(arry2)/sizeof(arry2[0])) << endl;
    cout << "non_pos_prefix_sum on arry1: " << non_pos_prefix_sum(arry2, sizeof(arry2)/sizeof(arry2[0])) << endl;
}