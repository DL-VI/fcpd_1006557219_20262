/**
 * @file ce_03_matrix_pointer_to_pointer.c
 * @brief Practice logic exercises in C focusing on pointers, double pointers,
 * and pointer arithmetic
 * @author Fabiano Del Villar
 * @date 2026-09-28
 *
 * FUNCTIONALITY:
 * Dynamic allocation of a 3x3 matrix using double pointers (int **matriz).
 * Memory is allocated for rows and columns using malloc. The matrix is 
 * populated with values 1 to 9, printed using pointer arithmetic 
 * (*(*(matriz + i) + j)), and then dynamically deallocated to prevent memory leaks.
 *
 * EXPECTED OUTPUT:
 * 1 2 3 
 * 4 5 6 
 * 7 8 9 
 */

#include <stdio.h>
#include <stdlib.h>

#define ROWS 3
#define COLS 3

int main()
{
    // Dynamic memory allocation for array of row pointers
    int **matriz = (int **)malloc(ROWS * sizeof(int *));
    for (int i = 0; i < ROWS; i++)
    {
        *(matriz + i) = (int *)malloc(COLS * sizeof(int));
    }

    // Populate matrix using pointer arithmetic
    int val = 1;
    for (int i = 0; i < ROWS; i++)
    {
        for (int j = 0; j < COLS; j++)
        {
            *(*(matriz + i) + j) = val++;
        }
    }

    // Print matrix using pointer arithmetic
    for (int i = 0; i < ROWS; i++)
    {
        for (int j = 0; j < COLS; j++)
        {
            printf("%d ", *(*(matriz + i) + j));
        }
        printf("\n");
    }

    // Free dynamically allocated memory
    for (int i = 0; i < ROWS; i++)
    {
        free(*(matriz + i));
    }
    free(matriz);

    return 0;
}