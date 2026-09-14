/**
 * @file ce_09_dynamic_array_sum.c
 * @brief Creates a dynamic array, populates it with user input, and calculates the total sum.
 * @author Fabiano Del Villar
 * @date 2026-09-09
 */

#include <stdio.h>
#include <stdlib.h>

/**
 * @brief Calculates the sum of all elements in an integer array using pointer indexing.
 * @param pntr_array Pointer to the dynamically allocated integer array.
 * @param array_size Total number of elements in the array.
 * @return Sum of all array elements.
 */
int calculate_array_sum(const int *pntr_array, int array_size)
{
    int total_sum = 0;
    
    for (int index = 0; index < array_size; index++)
    {
        total_sum += pntr_array[index];
    }
    
    return total_sum;
}

/**
 * @brief Prints the elements of the array separated by commas.
 * @param pntr_array Pointer to the integer array.
 * @param array_size Total number of elements in the array.
 */
void print_array_elements(const int *pntr_array, int array_size)
{
    for (int index = 0; index < array_size; index++)
    {
        printf("%d,", *(pntr_array + index));
    }
}

/**
 * @brief Prompts user to populate the dynamic array, displays its contents, and computes the sum.
 */
void process_dynamic_array(void)
{
    int array_size, input_value;

    printf("\nNumber of elements: ");
    if (scanf("%d", &array_size) != 1 || array_size <= 0)
    {
        printf("Invalid array size.\n");
        return;
    }

    // Dynamic memory allocation for user elements
    int *pntr_array = (int *)malloc(array_size * sizeof(int));
    if (pntr_array == NULL)
    {
        printf("Memory allocation failed.\n");
        return;
    }

    // User input loop
    for (int index = 0; index < array_size; index++)
    {
        printf("Value %d: ", (index + 1));
        if (scanf("%d", &input_value) == 1)
        {
            *(pntr_array + index) = input_value;
        }
    }

    print_array_elements(pntr_array, array_size);

    int total_sum = calculate_array_sum(pntr_array, array_size);
    printf("\nThe sum of all elements in the array is: %d\n", total_sum);

    free(pntr_array);
    pntr_array = NULL;
}

int main(void)
{
    process_dynamic_array();
    return 0;
}