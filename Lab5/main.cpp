#include <iostream>
#include <istream>
#include <fstream>
#include <algorithm>
#include <iterator>
#include <string>
#include <vector>

#include "ints_read_matrix.h"
#include "ints_write.h"

using namespace std;

// auxillary function to load ints into matricies
void set_up_matrix(vector<vector<int>> &matrix, const string file_name) {
    ifstream in_file;
    in_file.open(file_name);

    matrix = ints_read_matrix(in_file);
    in_file.close();

    return;
}

// auxillary function to run algorithm as described in lab document
void compute_expensive_digraph_exact_paths(vector<vector<int>> &zero_matrix,
                                            vector<vector<int>> &one_matrix,
                                            vector<vector<int>> &m_one_matrix) {
    // assuming all matricies are square and equal size
    int n = zero_matrix.size();
    for(int l = 2; l <= (3 * n * n + 1); l++) {
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                for(int k = 0; k < n; k++) {
                    if(m_one_matrix[i][k] + one_matrix[k][j] == 0 || 
                        one_matrix[i][k] + m_one_matrix[k][j] == 0) {
                            zero_matrix[i][j] = 0;
                        }
                    if(one_matrix[i][k] + zero_matrix[k][j] == 1 ||
                        zero_matrix[i][k] + one_matrix[k][j] == 1) {
                            one_matrix[i][j] = 1;
                        }
                    if(m_one_matrix[i][k + zero_matrix[k][j] == -1] ||
                        zero_matrix[i][k] + m_one_matrix[k][j] == -1) {
                            m_one_matrix[i][j] = -1;
                        }
                    
                }
            }
        }
    }
}

int main() {
    vector<vector<int>> zero_matrix;
    set_up_matrix(zero_matrix, "graph_0.txt");

    vector<vector<int>> one_matrix;
    set_up_matrix(one_matrix, "graph_1.txt");

    vector<vector<int>> m_one_matrix;
    set_up_matrix(m_one_matrix, "graph_m1.txt");

    compute_expensive_digraph_exact_paths(zero_matrix, one_matrix, m_one_matrix);

    cout << zero_matrix << endl;
    cout << one_matrix << endl;
    cout << m_one_matrix << endl;

    return 0;
}