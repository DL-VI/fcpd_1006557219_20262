/**
 * @file ce_02_array_sum_pointers.c
 * @brief Practice logic exercises in C focusing on pointers, double pointers,
 * and pointer arithmetic
 * @author Fabiano Del Villar
 * @date 2026-09-28
 *
 * FUNCTIONALITY:
 * This program creates an array of 10 integers and computes the sum of its
 * elements inside the `sum_array()` function. Iteration over the elements
 * is performed using pointer arithmetic (*(array + index)). The final sum
 * is returned and printed to standard output.
 *
 * EXPECTED OUTPUT:
 * The sum of the array elements is: 55
 */

#include <stdio.h>

#define N 10

int sum_array(int *array)
{
    int sum = 0;
    for (int index = 0; index < N; index++)
        sum += *(array + index);

    return sum;
}

int main()
{
    int array[N] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    printf("The sum of the array elements is: %d\n", sum_array(array));
    return 0;
}