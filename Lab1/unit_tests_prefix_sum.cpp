#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "prefix_sum.h"
#include <math.h>

using namespace std;

TEST_CASE("prefix sum") {

    SUBCASE("sum case") {
        int arry1[10];
        int arry2[10];
        int arry3[10];
        int arry4[] = {};

        for(int i = 0; i < 10; i++) {
            arry1[i] = i;
        }

        for(int i = 0; i < 10; i++) {
            arry2[i] = pow(-1, i) * i;
        }

        for(int i = 0; i < 10; i++) {
            arry3[i] = -1 * i;
        }

        // sum of positive ints only
        CHECK_EQ(sum(arry1, sizeof(arry1)/sizeof(arry1[0])), 45);
        
        // sum of positive and negative ints
        CHECK_EQ(sum(arry2, sizeof(arry2)/sizeof(arry2[0])), -5);

        // sum of negative ints only
        CHECK_EQ(sum(arry3, sizeof(arry3)/sizeof(arry3[0])), -45);
        
        // sum of empty array
        CHECK_EQ(sum(arry4, sizeof(arry4)/sizeof(arry4[0])), 0);
    };

    SUBCASE("non-neg sum case") {
        int arry1[] = {1, 1, 1, 1, 1};
        int arry2[] = {-1, -1, -1, -1, -1};
        int arry3[] = {-1, -1, 1, 1, 1};
        int arry4[] = {1, 1, -1, -1, -1};
        int arry5[] = {0, 0, 0, 0, 0};
        int arry6[] = {};

        // sum of array is always > 0
        CHECK(non_neg_prefix_sum(arry1, sizeof(arry1)/sizeof(arry1[0])));

        // sum of array is always < 0
        CHECK_FALSE(non_neg_prefix_sum(arry2, sizeof(arry2)/sizeof(arry2[0])));

        // sum of array starts < 0, becomes > 0
        CHECK_FALSE(non_neg_prefix_sum(arry3, sizeof(arry3)/sizeof(arry3[0])));

        // sum of array starts > 0, becomes < 0
        CHECK_FALSE(non_neg_prefix_sum(arry4, sizeof(arry4)/sizeof(arry4[0])));

        // sum of array is always 0
        CHECK(non_neg_prefix_sum(arry5, sizeof(arry5)/sizeof(arry5[0])));

        // sum of empty array
        CHECK(non_neg_prefix_sum(arry6, sizeof(arry6)/sizeof(arry6[0])));
    };

    SUBCASE("non-pos sum case") {
        int arry1[] = {1, 1, 1, 1, 1};
        int arry2[] = {-1, -1, -1, -1, -1};
        int arry3[] = {-1, -1, 1, 1, 1};
        int arry4[] = {1, 1, -1, -1, -1};
        int arry5[] = {0, 0, 0, 0, 0};
        int arry6[] = {};

        //sum is always > 0
        CHECK_FALSE(non_pos_prefix_sum(arry1, sizeof(arry1)/sizeof(arry1[0])));

        //sum is always < 0
        CHECK(non_pos_prefix_sum(arry2, sizeof(arry2)/sizeof(arry2[0])));

        // sum of array starts < 0, becomes > 0
        CHECK_FALSE(non_pos_prefix_sum(arry3, sizeof(arry3)/sizeof(arry3[0])));

        // sum of array starts > 0, becomes < 0
        CHECK_FALSE(non_pos_prefix_sum(arry4, sizeof(arry4)/sizeof(arry4[0])));

        // sum of array is always 0
        CHECK(non_pos_prefix_sum(arry5, sizeof(arry5)/sizeof(arry5[0])));

        // sum of empty array
        CHECK(non_pos_prefix_sum(arry6, sizeof(arry6)/sizeof(arry6[0])));
    };
}