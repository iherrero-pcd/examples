#include <time.h>
#include <iostream>
#include <Eigen/Dense>
 
using Eigen::MatrixXd;
using Eigen::VectorXd;

constexpr static std::int32_t M = 1000;
constexpr static std::int32_t N = 1500;
constexpr static std::int32_t P = 1000;

static MatrixXd A = MatrixXd::Random(M, N);
static MatrixXd B = MatrixXd::Random(N, P);
static MatrixXd C(M, P);

int main()
{
    std::cout << "Eigen" << "," << "C = A * B" << "," << std::flush;
    clock_t t = clock();
    C = A * B;
    t = clock() - t;
    std::cout << t/(float)CLOCKS_PER_SEC << std::endl;
    return 0;
}