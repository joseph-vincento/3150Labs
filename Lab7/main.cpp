#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
#include "double_vector.h"

using namespace std;

int main() {
    string file_name = "vectors.txt";
    vector<double_vector> vectors = read_vectors(file_name);

    vector<pair<double, pair<double_vector, double_vector>>> distances = 
        calc_pairwise_cosine_distances(vectors);
    
    sort(distances.begin(), distances.end(), cosine_distance_comparison);

    for(auto const &pair : distances) {
        cout << "Cosine distance: " << pair.first << " | ";
        cout << "Vectors: " << pair.second.first << ", " << pair.second.second << endl;
    }

    return 0;
}