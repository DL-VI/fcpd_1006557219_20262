/**
 * @file ce_07_matrix_diagonals_sum.c
 * @brief Creates a square matrix with random numbers and compares diagonal sums using pointers.
 * @author Fabiano Del Villar
 * @date 2026-09-09
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 2
#define COLS 2

/**
 * @brief Calculates the sum of the primary diagonal using double pointer arithmetic.
 * @param pntr_matrix Double pointer to the dynamically allocated matrix.
 * @return Sum of the main diagonal elements.
 */
int calculate_primary_diagonal(int **pntr_matrix)
{
    int diagonal_sum = 0;
    for (int row_index = 0; row_index < ROWS; row_index++)
    {
        diagonal_sum += *(*(pntr_matrix + row_index) + row_index);
    }

    return diagonal_sum;
}

/**
 * @brief Calculates the sum of the secondary diagonal using double pointer arithmetic.
 * @param pntr_matrix Double pointer to the dynamically allocated matrix.
 * @return Sum of the secondary diagonal elements.
 */
int calculate_secondary_diagonal(int **pntr_matrix)
{
    int diagonal_sum = 0;
    int col_index = COLS - 1;
    for (int row_index = 0; row_index < ROWS; row_index++, col_index--)
    {
        diagonal_sum += *(*(pntr_matrix + row_index) + col_index);
    }

    return diagonal_sum;
}

/**
 * @brief Fills the dynamic matrix with random integer values.
 * @param pntr_matrix Double pointer to the matrix.
 */
void fill_matrix(int **pntr_matrix)
{
    for (int row_index = 0; row_index < ROWS; row_index++)
    {
        for (int col_index = 0; col_index < COLS; col_index++)
        {
            pntr_matrix[row_index][col_index] = rand() % 100;
        }
    }
}

/**
 * @brief Prints the contents of the matrix using pointer arithmetic.
 * @param pntr_matrix Double pointer to the matrix.
 */
void print_matrix(int **pntr_matrix)
{
    for (int row_index = 0; row_index < ROWS; row_index++)
    {
        for (int col_index = 0; col_index < COLS; col_index++)
        {
            int cell_value = *(*(pntr_matrix + row_index) + col_index);
            printf("[%d][%d] = %d\n", (row_index + 1), (col_index + 1), cell_value);
        }
    }
}

/**
 * @brief Evaluates diagonal sums and prints the final comparison.
 * @param pntr_matrix Double pointer to the matrix.
 */
void evaluate_matrix_diagonals(int **pntr_matrix)
{
    int primary_sum = calculate_primary_diagonal(pntr_matrix);
    int secondary_sum = calculate_secondary_diagonal(pntr_matrix);

    printf("\nPrimary Diagonal Sum: %d", primary_sum);
    printf("\nSecondary Diagonal Sum: %d\n", secondary_sum);

    (primary_sum == secondary_sum) ? printf("The sums of both diagonals are equal.\n")
    : (primary_sum > secondary_sum) ? printf("The sum of the primary diagonal is greater.\n")
    : printf("The sum of the secondary diagonal is greater.\n");
}


int main(void)
{
    srand((unsigned int)time(NULL));

    // Dynamic memory allocation for rows
    int **pntr_matrix = (int **)malloc(ROWS * sizeof(int *));
    if (pntr_matrix == NULL) return 1;

    // Dynamic memory allocation for columns per row
    for (int row_index = 0; row_index < ROWS; row_index++)
    {
        pntr_matrix[row_index] = (int *)malloc(COLS * sizeof(int));
        if (pntr_matrix[row_index] == NULL) return 1;
    }

    fill_matrix(pntr_matrix);
    print_matrix(pntr_matrix);
    evaluate_matrix_diagonals(pntr_matrix);

    free(pntr_matrix);

    return 0;
}