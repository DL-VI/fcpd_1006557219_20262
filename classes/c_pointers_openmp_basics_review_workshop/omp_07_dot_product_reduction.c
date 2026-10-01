/**
 * @file ce_07_dot_product_parallel.c
 * @brief Practice OpenMP parallelization exercises focusing on dot product
 * computation, thread management, and performance metrics.
 * @author Fabiano Del Villar
 * @date 2026-09-30
 *
 * FUNCTIONALITY:
 * Populates two dynamic integer arrays of size N = 1,000,000 with random values.
 * Computes their dot product sequentially and in parallel using 
 * `#pragma omp parallel for reduction(+:result)`.
 * Measures sequential time (Ts) and parallel time (Tp) using `omp_get_wtime()`
 * to calculate speedup (Ts / Tp). Active threads announce their participation 
 * using `omp_get_thread_num()` and `omp_get_num_threads()`.
 *
 * EXPECTED OUTPUT:
 * Thread 0 of 8 threads calculating dot product...
 * Thread 1 of 8 threads calculating dot product...
 * ...
 * --- Dot Product Performance Metrics ---
 * Sequential Result : 247501020 | Time (Ts): 0.003100sg
 * Parallel Result   : 247501020 | Time (Tp): 0.000800sg
 * Speedup           : 3.88x
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

long dot_product_sequential(int *array_one, int *array_two)
{
    long result = 0;
    for (int index = 0; index < N; index++)
    {
        result += *(array_one + index) * *(array_two + index);
    }
    return result;
}

long dot_product_parallel(int *array_one, int *array_two)
{
    long result = 0;

#pragma omp parallel for reduction(+ : result)
    for (int index = 0; index < N; index++)
    {
        result += *(array_one + index) * *(array_two + index);
        
        // Print thread details for the first chunk processed by each thread
        if (index % (N / omp_get_num_threads()) == 0)
        {
            printf("Thread %d of %d threads calculating dot product...\n",
                   omp_get_thread_num(), omp_get_num_threads());
        }
    }

    return result;
}

int main()
{
    srand(time(NULL));
    int *array_one = (int *)malloc(N * sizeof(int));
    int *array_two = (int *)malloc(N * sizeof(int));

    fill_array(array_one);
    fill_array(array_two);

    // Sequential calculation
    double start_seq = omp_get_wtime();
    long res_seq = dot_product_sequential(array_one, array_two);
    double time_seq = omp_get_wtime() - start_seq;

    // Parallel calculation
    printf("--- OpenMP Thread Execution ---\n");
    double start_par = omp_get_wtime();
    long res_par = dot_product_parallel(array_one, array_two);
    double time_par = omp_get_wtime() - start_par;

    double speedup = time_seq / time_par;

    printf("\n--- Dot Product Performance Metrics ---\n");
    printf("Sequential Result : %ld | Time (Ts): %.6fsg\n", res_seq, time_seq);
    printf("Parallel Result   : %ld | Time (Tp): %.6fsg\n", res_par, time_par);
    printf("Speedup           : %.2fx\n", speedup);

    free(array_one);
    free(array_two);

    return 0;
}