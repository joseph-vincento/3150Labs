#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "fisher_yates.h"
#include "well_formed.h"

#include <cstdlib>
#include <ctime>

TEST_CASE("fisher-yates tests") {
    SUBCASE("swap") {
        int x = 1;
        int y = 2;

        // Case: swap x with itself
        swap(&x, &x);

        CHECK_EQ(x, 1);
        
        // Case: swap x with y
        swap(&x, &y);

        CHECK_EQ(x, 2);
        CHECK_EQ(y, 1);
    };

    SUBCASE("fisher-yates shuffle") {
        using namespace std;

        int arr1[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
        int arr2[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
        int expected_shuffle[10] = {0, 3, 2, 5, 9, 4, 8, 7, 6, 1};

        // Case: array is shuffled (not equal to the original)
        srand(time(nullptr));

        int arr1_copy[10];
        copy(arr1, arr1 + 10, arr1_copy);

        fisher_yates_shuffle(arr1, 10, &rand);

        CHECK_FALSE(equal(arr1_copy, arr1_copy + 10, arr1));

        // Case: shuffle with a known psuedorandom sequence
        srand(1);

        fisher_yates_shuffle(arr2, 10, &rand);

        CHECK(equal(arr2, arr2 + 10, expected_shuffle));
    };
}

TEST_CASE("well formed tests") {
    SUBCASE("well formed array") {
        int arr1[10] = {1, -1, 1, -1, 1, -1, 1, -1, 1, -1};
        int arr2[10] = {1, 1, 1, 1, 1, -1 , -1, -1, -1, -1};
        int arr3[10] = {1, 1, -1, 1, -1, 1, -1, 1, -1, -1};

        // Case: alternating symbols
        CHECK(is_well_formed_array(arr1, 10));

        // Case: 0 - n/2 = 1, n/2 - n = -1
        CHECK(is_well_formed_array(arr2, 10));

        // Case: nested matched symbols
        CHECK(is_well_formed_array(arr3, 10));
    };

    SUBCASE("not well formed array") {
        int arr1[10] = {-1, 1, -1, 1, -1, 1, -1, 1, -1, 1};
        int arr2[10] = {-1, -1, -1, -1, -1, 1, 1, 1, 1, 1};
        int arr3[10] = {1, -1, 1, -1, 1, -1, 1, -1, 1, 1};
        int arr4[10] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1};

        //Case: total prefix sum = 0, running prefix sum < 0
        CHECK_FALSE(is_well_formed_array(arr1, 10));
        CHECK_FALSE(is_well_formed_array(arr2, 10));

        // Case: total prefix sum > 0, running prefix sum >= 0
        CHECK_FALSE(is_well_formed_array(arr3, 10));
        CHECK_FALSE(is_well_formed_array(arr4, 10));
    };
}