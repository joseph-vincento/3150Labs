
#include <iostream>
#include <fstream>
#include <sstream>
#include <cmath>
#include <vector>

#include "double_vector.h"


using namespace std;


double square(const double & d){
    return d*d;
}

double dot_product(const double_vector & one, const double_vector & two) {
    double dot_product = 0.0;
    for(int i = 0; i < one.elements.size(); i++) {
        dot_product += one.elements[i] * two.elements[i];
    }
    return dot_product;
}

double magnitude(const double_vector & my_vector) {
    double sum_of_squares = 0.0;
    for(auto const &elem : my_vector.elements) {
        sum_of_squares += square(elem);
    }
    return sqrt(sum_of_squares);
};


double cosine_distance(const double_vector & one, const double_vector & two) {
    double dot_prod = dot_product(one,two);
    double one_magnitude = magnitude(one);
    double two_magnitude = magnitude(two);

    double d = dot_prod/(one_magnitude*two_magnitude) ;
    if(d > 1.0) {
        d = 1.0;
    }
    else if (d < -1.0) {
        d = -1.0;
    }

    return acos(d);
}

vector<double_vector> read_vectors(const string &file_name) {
    vector<double_vector> rv;
    string current_line;
    ifstream file(file_name);

    while(getline(file, current_line)) {
        double_vector new_vector;
        stringstream line_stream(current_line);
        double elem;
        
        while(line_stream >> elem) {
            new_vector.elements.push_back(elem);
        }
        rv.push_back(new_vector);
    }
    file.close();

    return rv;
}

vector<pair<double, pair<double_vector, double_vector>>> calc_pairwise_cosine_distances(const vector<double_vector> & vectors) {
    // https://en.cppreference.com/w/cpp/utility/pair
    // create a vector of pairs
    // each pair contains a double and an inner pair
    // each inner pair contains two double_vectors
    // i.e.: cosine_distances[0] == {1.0, {dv1, dv2}}
    vector<pair<double, pair<double_vector, double_vector>>> cosine_distances;

    int n = vectors.size();
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            double pairwise_distance = cosine_distance(vectors[i], vectors[j]);
            cosine_distances.push_back({pairwise_distance, {vectors[i], vectors[j]}});
        }
    }

    return cosine_distances;
}

bool cosine_distance_comparison(
    const pair<double, pair<double_vector, double_vector>>  & dv_pair1,
    const pair<double, pair<double_vector, double_vector>>  & dv_pair2
) {
    // Compare calculated cosine distances as per documentation
    // on parameter specification for sort()
    // https://en.cppreference.com/w/cpp/algorithm/sort
    return dv_pair1.first < dv_pair2.first;
}

ostream &operator<<(ostream &out_stream, const double_vector &vec) {
    if(vec.elements.empty()) {
        out_stream << "( )";
    }
    else {
        out_stream << "(" << vec.elements[0];
        for(int i = 1; i < vec.elements.size(); i++) {
            out_stream << ", " << vec.elements[i]; 
        }
        out_stream << ")";
    }
    return out_stream;
}