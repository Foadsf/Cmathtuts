//Example 0 - fill two C++ vectors with random numbers
#include <iostream>
#include <vector>
#include <random>
#include <ctime>

using namespace std;

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

int main() {
    size_t N = 3;
    vector<double> A(N * N), B(N * N);

    //Fill A and B with random numbers in the range [0,1]:
    rnd_fill(A, 0.0, 1.0);
    rnd_fill(B, 0.0, 1.0);
    for(auto elem : A) cout << elem << endl;

    return 0;
}

