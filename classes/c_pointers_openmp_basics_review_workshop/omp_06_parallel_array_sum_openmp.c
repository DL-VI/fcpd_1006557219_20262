/**
 * @file ce_06_array_sum_parallel.c
 * @brief Practice OpenMP parallelization exercises focusing on array summation
 * and execution time measurement.
 * @author Fabiano Del Villar
 * @date 2026-09-30
 *
 * FUNCTIONALITY:
 * This program populates an array of 1,000,000 integers with random values.
 * It computes the sum of the array sequentially and then in parallel using
 * OpenMP's `#pragma omp parallel for reduction(+:sum)` directive. Execution
 * times are measured using `omp_get_wtime()` to calculate and display the
 * overall speedup achieved.
 *
 * EXPECTED OUTPUT:
 * Total sum sequential: 49502812
 * Sequential time: 0.003sg
 * 
 * Total sum parallel: 49502812
 * Parallel time: 0.001sg
 * Speedup: 3.00x
 * (Note: Total sums depend on random seed, and execution times vary by CPU)
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <omp.h>

#define N 1000000

void fill_array(int *array)
{
    for (int index = 0; index < N; index++)
        *(array + index) = rand() % 100;
}

long long sum_array_sequential(int *array)
{
    long long sum = 0;
    for (int index = 0; index < N; index++)
        sum += *(array + index);

    return sum;
}

long long sum_array_parallel(int *array)
{
    long long sum = 0;

    #pragma omp parallel for reduction(+:sum)
    for (int index = 0; index < N; index++)
        sum += *(array + index);

    return sum;
}

int main()
{
    srand(time(NULL));
    int *array = (int *)malloc(N * sizeof(int));
    fill_array(array);

    // Sequential Execution
    double start_sequential = omp_get_wtime();
    long long sum_sequential = sum_array_sequential(array);
    double elapsed_sequential = omp_get_wtime() - start_sequential;

    // Parallel Execution
    double start_parallel = omp_get_wtime();
    long long sum_parallel = sum_array_parallel(array);
    double elapsed_parallel = omp_get_wtime() - start_parallel;

    double speedup = elapsed_sequential / elapsed_parallel;

    printf("Total sum sequential: %lld\n", sum_sequential);
    printf("Sequential time: %.3fsg\n", elapsed_sequential);
    
    printf("\nTotal sum parallel: %lld\n", sum_parallel);
    printf("Parallel time: %.3fsg\n", elapsed_parallel);
    printf("Speedup: %.2fx\n", speedup);

    free(array);
    return 0;
}