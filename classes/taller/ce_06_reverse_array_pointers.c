/**
 * @file ce_06_reverse_array_pointers.c
 * @brief Reverses the elements of an array using pointer arithmetic.
 * @author Fabiano Del Villar
 * @date 2026-09-09
 */

#include <stdio.h>

/**
 * @brief Reverses an integer array in-place using pointer arithmetic.
 * @param pntr_array Pointer to the first element of the array.
 * @param array_size Total number of elements in the array.
 */
void reverse_array(int *pntr_array, int array_size)
{
    int temp_first, temp_last;

    for (int index = 0; index < (array_size / 2); index++)
    {
        temp_first = *(pntr_array + index);
        temp_last = *(pntr_array + (array_size - 1 - index));
        *(pntr_array + index) = temp_last;
        *(pntr_array + (array_size - 1 - index)) = temp_first;
    }
}

/**
 * @brief Prints all elements of an integer array separated by commas using pointers.
 * @param pntr_array Pointer to the first element of the array.
 * @param array_size Total number of elements to print.
 */
void print_array(int *pntr_array, int array_size)
{
    for (int index = 0; index < array_size; index++)
    {
        printf("%d,", *(pntr_array + index));
    }
}

/**
 * @brief Processes array reversal demo and prints results.
 */
void process_array_reversal(void)
{
    int numbers_array[5] = {1, 5, 12, 65, 90};
    int array_size = sizeof(numbers_array) / sizeof(numbers_array[0]);
    int *pntr_array = numbers_array;

    printf("Original: ");
    print_array(pntr_array, array_size);

    reverse_array(pntr_array, array_size);

    printf("\nInverted: ");
    print_array(pntr_array, array_size);
    printf("\n");
}

int main(void)
{
    process_array_reversal();
    return 0;
}