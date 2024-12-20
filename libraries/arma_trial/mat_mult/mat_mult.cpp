#include <time.h>
#include <iostream>
#include <armadillo>

using namespace arma;

constexpr static std::int32_t M = 1000;
constexpr static std::int32_t N = 1500;
constexpr static std::int32_t P = 1000;

mat A(M, N, fill::randu);
mat B(N, P, fill::randu);
mat C(M, P, fill::randu);

int main()
  {
    std::cout << "Arma" << "," << "C=A*B" << "," << std::flush;
    clock_t t = clock();
    C = A * B;
    t = clock() - t;
    std::cout << t/(float)CLOCKS_PER_SEC << std::endl;
    return 0;
}