/**
 * @file ce_05_recursive_sum_digits.c
 * @brief Recursively calculates the sum of all digits of a given integer.
 * @author Fabiano Del Villar
 * @date 2026-09-09
 */

#include <stdio.h>

/**
 * @brief Recursive function to calculate the sum of digits of a number.
 * @param number Current number being processed.
 * @param sum Accumulated sum of extracted digits.
 * @return Final accumulated sum of all digits.
 */
int recursive_sum_digits(int number, int sum)
{
    if (number == 0) 
        return sum;

    sum += number % 10;
    number /= 10;
    return recursive_sum_digits(number, sum);        
}

int main(void)
{
    int input_number = 54;
    int initial_sum = 0;

    printf("The sum is: %d\n", recursive_sum_digits(input_number, initial_sum));
    
    return 0;
}