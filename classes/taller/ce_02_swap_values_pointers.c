/**
 * @file ce_02_swap_values_pointers.c
 * @brief Swaps the values of two integers using pointers (pass by reference).
 * @author Fabiano Del Villar
 * @date 2026-09-09
 */

#include <stdio.h>

/**
 * @brief Swaps the integer values stored at two memory locations.
 * @param pntr_one Pointer to the first integer.
 * @param pntr_two Pointer to the second integer.
 */
void swap_values(int *pntr_one, int *pntr_two)
{
    int temporal = *pntr_one;
    *pntr_one = *pntr_two;
    *pntr_two = temporal;
}

/**
 * @brief Prompts user for input and displays swapped values.
 */
void execute_swap_demo(void)
{
    int number_one, number_two;

    printf("Enter the first number: ");
    if (scanf("%d", &number_one) != 1) return;

    printf("Enter the second number: ");
    if (scanf("%d", &number_two) != 1) return;

    printf("\n--- Before Swap ---\n");
    printf("Number one = %d, Number two = %d\n", number_one, number_two);

    swap_values(&number_one, &number_two);

    printf("\n--- After Swap ---\n");
    printf("Number one = %d, Number two = %d\n", number_one, number_two);
}

int main(void)
{
    execute_swap_demo();
    return 0;
}