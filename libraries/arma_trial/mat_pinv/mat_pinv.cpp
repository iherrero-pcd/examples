#include <time.h>
#include <iostream>
#include <armadillo>

using namespace arma;

constexpr static std::int32_t N = 1000;

mat A(N, N, fill::randu);
mat B;

int main()
  {
    std::cout << "Arma" << "," << "B=pinv(A)" << "," << std::flush;
    clock_t t = clock();
    B = pinv(A);
    t = clock() - t;
    std::cout << t/(float)CLOCKS_PER_SEC << std::endl;
    return 0;
}