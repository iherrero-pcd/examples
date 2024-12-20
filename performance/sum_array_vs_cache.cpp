/*
$ g++ -std=c++11 sum_array_vs_cache.cpp

M*N => 16777216
Matrix traversal by row : 0.417152 s (sum==167772160.000000)
Matrix traversal by col : 2.721725 s (sum==167772160.000000)

$ g++ -std=c++11 -O3 sum_array_vs_cache.cpp

M*N => 16777216
Matrix traversal by row : 0.163268 s (sum==167772160.000000)
Matrix traversal by col : 2.645814 s (sum==167772160.000000)

*/

#include <cstdio>
#include <cinttypes>
#include <algorithm>
#include <time.h>

constexpr static std::int32_t M = 4096;
constexpr static std::int32_t N = 4096;

double sum_array_by_rows(const double matrix[M][N]) {
    std::int32_t i, j;
    double sum = 0;
    for (i = 0; i < M; i++) {
        for (j = 0; j < N; j++) {
            sum += matrix[i][j];
        }
    }
    return sum;
}

double sum_array_by_cols(const double matrix[M][N]) {
    std::int32_t i, j;
    double sum = 0;
    for (j = 0; j < N; j++) {
        for (i = 0; i < M; i++) {
            sum += matrix[i][j];
        }
    }
    return sum;
}

static double matrix[M][N];

std::int32_t main(void) {
    printf("M*N => %d\n", M*N);
    {
        std::fill_n(&matrix[0][0], M*N, 1.0);
        double sum = 0;
        clock_t t = clock();
        for (std::int32_t j = 0; j < 10; ++j) {
            sum += sum_array_by_rows(matrix);
        }
        t = clock() - t;
        printf("Matrix traversal by row : %f s (sum==%f)\n", t/(float)CLOCKS_PER_SEC, sum);
    }
    {
        std::fill_n(&matrix[0][0], M*N, 1.0);
        double sum = 0;
        clock_t t = clock();
        for (std::int32_t j = 0; j < 10; ++j) {
            sum += sum_array_by_cols(matrix);
        }
        t = clock() - t;
        printf("Matrix traversal by col : %f s (sum==%f)\n", t/(float)CLOCKS_PER_SEC, sum);
    }
    return 0;
}
