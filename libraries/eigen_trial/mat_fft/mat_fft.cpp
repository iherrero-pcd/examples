#include <time.h>
#include <iostream>
#include <Eigen/Dense>
#include <unsupported/Eigen/FFT>

 
using Eigen::MatrixXd;
using Eigen::VectorXd;

constexpr static std::int32_t N = 1000;

Eigen::VectorXd timevec = VectorXd::Random(N);
Eigen::VectorXcd freqvec(N);

int main()
{
    std::cout << "Eigen" << "," << "fft.fwd|fft.inv" << "," << std::flush;
    clock_t t = clock();
    {
        Eigen::FFT<double> fft;
        fft.fwd(freqvec, timevec);
        fft.inv(timevec, freqvec);
    }
    t = clock() - t;
    std::cout << t/(float)CLOCKS_PER_SEC << std::endl;
    return 0;
}