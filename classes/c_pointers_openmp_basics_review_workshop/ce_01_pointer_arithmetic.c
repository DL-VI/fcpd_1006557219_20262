/**
 * @file ce_01_pointer_arithmetic.c
 * @brief Practice logic exercises in C focusing on pointers, double pointers,
 * and pointer arithmetic
 * @author Fabiano Del Villar
 * @date 2026-09-28
 *
 * FUNCTIONALITY:
 * This program initializes an array of 10 integers from 1 to 10.
 * It passes the array to `print_array()`, which iterates through
 * the elements using pointer arithmetic (*(array + i)) instead of standard
 * array indexing to print them in bracketed format.
 *
 * EXPECTED OUTPUT:
 * [1,2,3,4,5,6,7,8,9,10]
 */

#include <stdio.h>

#define N 10

void print_array(int *array)
{
    printf("[");
    for (int index = 0; index < N; index++)
    {
        if (index == N - 1)
            printf("%d", *(array + index));
        else printf("%d,", *(array + index));
    }
    printf("]\n");
}

int main()
{
    int array[N] = {1,2,3,4,5,6,7,8,9,10};
    print_array(array);

    return 0;
}