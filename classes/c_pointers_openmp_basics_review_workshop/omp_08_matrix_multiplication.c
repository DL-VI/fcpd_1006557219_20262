/**
 * @file ce_08_matrix_multiplication_parallel.c
 * @brief Practice OpenMP parallelization exercises focusing on large matrix
 * multiplication, double pointer arithmetic, and performance metrics.
 * @author Fabiano Del Villar
 * @date 2026-09-30
 *
 * FUNCTIONALITY:
 * Dynamically allocates two 500x500 matrices using double pointers (int **) directly in main.
 * Populates them with random values and computes matrix multiplication both
 * sequentially and in parallel using `#pragma omp parallel for`.
 * Accesses elements using double pointer arithmetic (*(*(matrix + i) + j)).
 * Measures execution times with `omp_get_wtime()` to calculate Speedup and Efficiency.
 *
 * EXPECTED OUTPUT:
 * --- OpenMP Thread Execution ---
 * Thread 0 of 8 processing row i = 0
 * Thread 1 of 8 processing row i = 62
 * ...
 * --- Matrix Multiplication Performance Metrics (500x500) ---
 * Ts (Sequential) : 0.385120 s
 * Tp (Parallel)   : 0.068210 s
 * Speedup         : 5.65x
 * Efficiency      : 70.62%
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <omp.h>

#define N 500

void fill_matrix_random(int **matrix)
{
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            *(*(matrix + i) + j) = rand() % 100;
}

void matrix_multiply_sequential(int **matrix_one, int **matrix_two, int **matrix_result)
{
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            *(*(matrix_result + i) + j) = 0;
            for (int k = 0; k < N; k++)
            {
                *(*(matrix_result + i) + j) += *(*(matrix_one + i) + k) * *(*(matrix_two + k) + j);
            }
        }
    }
}

void matrix_multiply_parallel(int **matrix_one, int **matrix_two, int **matrix_result)
{
#pragma omp parallel for
    for (int i = 0; i < N; i++)
    {
        if (i % (N / omp_get_num_threads()) == 0)
        {
            printf("Thread %d of %d processing row i = %d\n",
                   omp_get_thread_num(), omp_get_num_threads(), i);
        }

        for (int j = 0; j < N; j++)
        {
            *(*(matrix_result + i) + j) = 0;
            for (int k = 0; k < N; k++)
            {
                *(*(matrix_result + i) + j) += *(*(matrix_one + i) + k) * *(*(matrix_two + k) + j);
            }
        }
    }
}

int main()
{
    srand((unsigned int)time(NULL));

    int **matrix_one = (int **)malloc(N * sizeof(int *));
    int **matrix_two = (int **)malloc(N * sizeof(int *));
    int **matrix_result_seq = (int **)malloc(N * sizeof(int *));
    int **matrix_result_par = (int **)malloc(N * sizeof(int *));

    for (int i = 0; i < N; i++)
    {
        *(matrix_one + i) = (int *)malloc(N * sizeof(int));
        *(matrix_two + i) = (int *)malloc(N * sizeof(int));
        *(matrix_result_seq + i) = (int *)malloc(N * sizeof(int));
        *(matrix_result_par + i) = (int *)malloc(N * sizeof(int));
    }

    fill_matrix_random(matrix_one);
    fill_matrix_random(matrix_two);

    // Sequential Calculation
    double start_seq = omp_get_wtime();
    matrix_multiply_sequential(matrix_one, matrix_two, matrix_result_seq);
    double elapsed_seq = omp_get_wtime() - start_seq;

    // Parallel Calculation
    printf("--- OpenMP Thread Execution ---\n");
    double start_par = omp_get_wtime();
    matrix_multiply_parallel(matrix_one, matrix_two, matrix_result_par);
    double elapsed_par = omp_get_wtime() - start_par;

    int num_threads = omp_get_max_threads();
    double speedup = elapsed_seq / elapsed_par;
    double efficiency = (speedup / num_threads) * 100.0;

    printf("\n--- Matrix Multiplication Performance Metrics (%dx%d) ---\n", N, N);
    printf("Ts (Sequential) : %.6f s\n", elapsed_seq);
    printf("Tp (Parallel)   : %.6f s\n", elapsed_par);
    printf("Speedup         : %.2fx\n", speedup);
    printf("Efficiency      : %.2f%%\n", efficiency);

    free(matrix_one);
    free(matrix_two);
    free(matrix_result_seq);
    free(matrix_result_par);

    return 0;
}