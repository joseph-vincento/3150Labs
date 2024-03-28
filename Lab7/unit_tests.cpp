#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include <cmath>
#include "doctest.h"
#include "double_vector.h"

TEST_CASE("double_vector") {
    SUBCASE("square") {
        double x = 1.0;
        double y = 0.0;
        double z = 1.52;
        
        CHECK(square(x) == 1.0);
        CHECK(square(y) == 0.0);
        CHECK(square(z) == 2.3104);
    }

    SUBCASE("dot_product") {
        vector<double> zero = {0.0, 0.0, 0.0, 0.0, 0.0};
        double_vector zero_vector = double_vector(zero);
        vector<double> one = {1.0, 1.0, 1.0, 1.0, 1.0};
        double_vector one_vector = double_vector(one);
        
        CHECK(dot_product(zero_vector, zero_vector) == 0.0);
        CHECK(dot_product(zero_vector, one_vector) == 0.0);
        CHECK(dot_product(one_vector, one_vector) == 5.0);

        vector<double> test = {1.0, 2.0, 3.0, 4.0, 5.0};
        double_vector test_vector = double_vector(test);

        CHECK(dot_product(test_vector, zero_vector) == 0.0);
        CHECK(dot_product(test_vector, one_vector) == 15.0);
        CHECK(dot_product(test_vector, test_vector) == 55.0);
    }

    SUBCASE("magnitude") {
        vector<double> zero = {0.0, 0.0, 0.0, 0.0, 0.0};
        double_vector zero_vector = double_vector(zero);
        vector<double> one = {1.0, 1.0, 1.0, 1.0, 1.0};
        double_vector one_vector = double_vector(one);
        vector<double> test = {4.0, 9.0, 14.0, 19.0, 24.0};
        double_vector test_vector = double_vector(test);

        CHECK(magnitude(zero_vector) == 0.0);
        CHECK(magnitude(one_vector) == sqrt(5.0));
        CHECK(magnitude(test_vector) == sqrt(1230.0));
    }
}