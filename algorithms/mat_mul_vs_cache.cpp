/*
$ g++ -std=c++11 mat_mul_vs_cache.cpp

N*M => 1500000
M*P => 1000000
N*P => 1500000
Computing A*B v1... 
  => 17.581356 s
Computing A*B v2... 
  => 4.570401 s
Computing A*B v3... 
  => 16.893196 s
Computing A*B v4... 
  => 3.918807 s

$ g++ -std=c++11 -O3 mat_mul_vs_cache.cpp

N*M => 1500000
M*P => 1000000
N*P => 1500000
Computing A*B v1... 
  => 16.366156 s
Computing A*B v2... 
  => 0.925153 s
Computing A*B v3... 
  => 17.428293 s
Computing A*B v4... 
  => 0.916345 s
*/

#include <cstdio>
#include <cinttypes>
#include <algorithm>
#include <time.h>

constexpr static std::int32_t M = 1000;
constexpr static std::int32_t N = 1500;
constexpr static std::int32_t P = 1000;

static double A[M][N];
static double B[N][P];
static double C[M][P];

void mult_1(double C[M][P], const double A[M][N], const double B[N][P]) {
    std::int32_t i, j, k;
    for (i = 0; i < M; i++) {
        for (j = 0; j < P; j++) {
            for (k = 0; k < N; k++) {
                C[i][j] = C[i][j] + A[i][k] * B[k][j];
            }
        }
    }
}

void mult_2(double C[M][P], const double A[M][N], const double B[N][P]) {
    std::int32_t i, j, k;
    for (i = 0; i < M; i++) {
        for (k = 0; k < N; k++) {
            for (j = 0; j < P; j++) {
                C[i][j] = C[i][j] + A[i][k] * B[k][j];
            }
        }
    }
}

void mult_3(double C[M][P], const double A[M][N], const double B[N][P]) {
    std::int32_t i, j, k;
    double temp;
    for (i = 0; i < M; i++) {
        for (j = 0; j < P; j++) {
            temp = C[i][j];
            for (k = 0; k < N; k++) {
                temp = temp + A[i][k] * B[k][j];
            }
            C[i][j] = temp;
        }
    }
}

void mult_4(double C[M][P], const double A[M][N], const double B[N][P]) {
    std::int32_t i, j, k;
    double temp;
    for (i = 0; i < M; i++) {
        for (k = 0; k < N; k++) {
            temp = A[i][k];
            for (j = 0; j < P; j++) {
                C[i][j] = C[i][j] + temp * B[k][j];
            }
        }
    }
}

std::int32_t main(void) {
    printf("N*M => %d\n", N*M);
    printf("M*P => %d\n", M*P);
    printf("N*P => %d\n", N*P);
    {
        std::fill_n(&A[0][0], N*M, 1.0);
        std::fill_n(&B[0][0], M*P, 1.0);
        printf("Computing A*B v1... \n");
        clock_t t = clock();
        mult_1(C, A, B);
        t = clock() - t;
        printf("  => %f s\n", t/(float)CLOCKS_PER_SEC);
    }
    {
        std::fill_n(&A[0][0], N*M, 1.0);
        std::fill_n(&B[0][0], M*P, 1.0);
        printf("Computing A*B v2... \n");
        clock_t t = clock();
        mult_2(C, A, B);
        t = clock() - t;
        printf("  => %f s\n", t/(float)CLOCKS_PER_SEC);
    }
    {
        std::fill_n(&A[0][0], N*M, 1.0);
        std::fill_n(&B[0][0], M*P, 1.0);
        printf("Computing A*B v3... \n");
        clock_t t = clock();
        mult_3(C, A, B);
        t = clock() - t;
        printf("  => %f s\n", t/(float)CLOCKS_PER_SEC);
    }
    {
        std::fill_n(&A[0][0], N*M, 1.0);
        std::fill_n(&B[0][0], M*P, 1.0);
        printf("Computing A*B v4... \n");
        clock_t t = clock();
        mult_4(C, A, B);
        t = clock() - t;
        printf("  => %f s\n", t/(float)CLOCKS_PER_SEC);
    }
    return 0;
}
