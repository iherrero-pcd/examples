#include <time.h>
#include <iostream>
#include <armadillo>

using namespace arma;

constexpr static std::int32_t N = 5000;

vec A(N, fill::randu);
cx_vec B;

int main()
  {
    std::cout << "Arma" << "," << "B=fft(A)" << "," << std::flush;
    clock_t t = clock();
    B = fft(A);
    t = clock() - t;
    std::cout << t/(float)CLOCKS_PER_SEC << std::endl;
    return 0;
}