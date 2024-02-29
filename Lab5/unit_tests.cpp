#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN

#include <iostream>
#include <sstream>
#include <string>
#include <vector>

#include "doctest.h"
#include "ints_read_vector.h"
#include "ints_read_matrix.h"

TEST_CASE("ints_read_vector.h") {
  
    SUBCASE("ints_read : edge cases - istringstream") {
        istringstream istr_0("");
        vector<int> vec_0 = ints_read_vector(istr_0);
        CHECK(0 == vec_0.size());

        istringstream istr_99("-99");
        vector<int> vec_99 = ints_read_vector(istr_99);
        CHECK(-99 == vec_99[0]);
        CHECK(1 == vec_99.size());

        istringstream istr_5("5");
        vector<int> vec_5 = ints_read_vector(istr_5);
        CHECK(5 == vec_5[0]);
        CHECK(1 == vec_5.size());
    };

    SUBCASE("ints_read_one_line() : edge cases - istringstream") {
        istringstream istr_0("");
        vector<int> vec_0 = ints_read_one_line(istr_0);
        CHECK(0 == vec_0.size());

        istringstream istr_5("5");
        vector<int> vec_5 = ints_read_vector(istr_5);
        CHECK(5 == vec_5[0]);
        CHECK(1 == vec_5.size());

        istringstream istr_99("-99 1 2");
        vector<int> vec_99 = ints_read_vector(istr_99);
        CHECK(-99 == vec_99[0]);
        CHECK(3 == vec_99.size());

        istringstream istr_two_lines("-99 1 2\\n3 4 5"); // escape the new-line
        vector<int> vec_one_line = ints_read_vector(istr_two_lines);
        CHECK(-99 == vec_one_line[0]);
        CHECK(3 == vec_one_line.size()); // only 1 line of 3 elements read in
    };

    SUBCASE("ints_read : edge cases - ifstream FILE") {
        const char FILE_NAME[] = "./temp.txt";
        ofstream test_file;
        test_file.open(FILE_NAME);
        test_file << "8";
        test_file.close();

        ifstream test_same_file;
        test_same_file.open(FILE_NAME); 
        
        vector<int> vec_8 = ints_read_vector(test_same_file);
        test_same_file.close();
        CHECK(1 == vec_8.size());
        CHECK(8 == vec_8[0]);

    };
  
    SUBCASE("ints_read : small cases") {
        istringstream istr("0 1 2");
        vector<int> vec = ints_read_vector(istr);
        CHECK(0 == vec[0]);
        CHECK(1 == vec[1]);
        CHECK(2 == vec[2]);

    };
}

TEST_CASE("ints_read_matrix.h") {
  
    SUBCASE("ints_read_matrix : edge cases - istringstream") {
        istringstream istr_0("");
        vector<vector<int>> matrix_0 = ints_read_matrix(istr_0);
        CHECK(1 == matrix_0.size());
    
        istringstream istr_99("-99");
        vector<vector<int>> matrix_99 = ints_read_matrix(istr_99);
        CHECK(-99 == matrix_99[0][0]);
        CHECK(1 == matrix_99.size());
        CHECK(1 == matrix_99[0].size());
    };
  
    SUBCASE("ints_read_matrix : small cases") {
        istringstream istr("0 1 2\n4 5 6\n7 8 9");
        vector<vector<int>> matrix = ints_read_matrix(istr);
        CHECK(0 == matrix[0][0]);
        CHECK(1 == matrix[0][1]);
        CHECK(2 == matrix[0][2]);
        CHECK(3 == matrix.size());
        CHECK(3 == matrix[0].size());
        CHECK(3 == matrix[2].size());

    };
}
