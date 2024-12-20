#include <time.h>
#include <iostream>
#include <Eigen/Dense>
 
using Eigen::MatrixXd;
using Eigen::VectorXd;

constexpr static std::int32_t N = 1000;

static MatrixXd A = MatrixXd::Random(N, N);
static MatrixXd B;

int main()
{
    std::cout << "Eigen" << "," << "B=A.inverse()" << "," << std::flush;
    clock_t t = clock();
    B = A.inverse();
    t = clock() - t;
    std::cout << t/(float)CLOCKS_PER_SEC << std::endl;
    return 0;
}