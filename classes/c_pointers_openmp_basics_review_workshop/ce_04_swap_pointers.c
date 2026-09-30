/**
 * @file ce_04_swap_pointers.c
 * @brief Practice logic exercises in C focusing on pointers, double pointers,
 * and pointer arithmetic
 * @author Fabiano Del Villar
 * @date 2026-09-28
 *
 * FUNCTIONALITY:
 * This program implements a `swap()` function that receives two integer pointers.
 * It swaps the underlying values stored in the original memory addresses using
 * pass-by-reference. The program prints the variable values before and after
 * executing the swap to demonstrate the side effect.
 *
 * EXPECTED OUTPUT:
 * 
 * --- Before Swap ---
 * Value x = 7, Value y = 10
 * 
 * --- After Swap ---
 * Value x = 10, Value y = 7
 */

#include <stdio.h>

void swap(int *x, int *y)
{
    int copy = *x;
    *x = *y;
    *y = copy;
}

int main()
{
    int value_x = 7, value_y = 10;
    
    printf("\n--- Before Swap ---\n");
    printf("Value x = %d, Value y = %d\n", value_x, value_y);
    
    swap(&value_x, &value_y);

    printf("\n--- After Swap ---\n");
    printf("Value x = %d, Value y = %d\n", value_x, value_y);
    return 0;
}