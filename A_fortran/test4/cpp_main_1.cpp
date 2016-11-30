//Example 1 - multiply two arrays by calling a Fortran subroutine
#include <iostream>
#include <vector>
#include <random>
#include <ctime>

using namespace std;

//Fortran subroutine definition "translated" to C++
extern "C" {
    void matrix_multiply(double *A, int *rows_A, int *cols_A, double *B, int *rows_B, int *cols_B, double *C, int *rows_C, int *cols_C);
}

//Fill a vector with random numbers in the range [lower, upper]
void rnd_fill(vector<double> &V, double lower, double upper) {

    //use system clock to create a random seed
    size_t seed (clock());

    //use the default random engine and an uniform distribution
    default_random_engine eng(seed);
    uniform_real_distribution<double> distr(lower, upper);

    for( auto &elem : V){
        elem = distr(eng);
    }
}

//Print matrix V(rows, cols) storage in column-major format
void print_matrix(vector<double> const &V, int rows, int cols) {

    for(int i = 0; i < rows; ++i){
        for(int j = 0; j < cols; ++j){
            std::cout << V[j * rows + i] << " ";
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;
}

int main() {
    size_t N = 3;
    vector<double> A(N * N), B(N * N), C(N * N);

    //Fill A and B with random numbers in the range [0,1]:
    rnd_fill(A, 0.0, 1.0);
    rnd_fill(B, 0.0, 1.0);

    //Multiply matrices A and B, save the result in C
    int sz = N;
    matrix_multiply(&A[0], &sz, &sz, &B[0], &sz, &sz, &C[0], &sz, &sz);

    //print A, B, C on the standard output
    print_matrix(A, sz, sz);
    print_matrix(B, sz, sz);
    print_matrix(C, sz, sz);

    return 0;
}

