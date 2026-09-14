/**
 * @file ce_03_min_max_ternary.c
 * @brief Determines the largest and smallest of three integers using ternary operators.
 * @author Fabiano Del Villar
 * @date 2026-09-09
 */

#include <stdio.h>

/**
 * @brief Evaluates and prints the largest number among three integers.
 * @param first_num First integer.
 * @param second_num Second integer.
 * @param third_num Third integer.
 */
void print_largest(int first_num, int second_num, int third_num) 
{
    int largest_num = (second_num >= first_num && second_num >= third_num) ? second_num :
                      (third_num >= first_num && third_num >= second_num) ? third_num : first_num;

    printf("The largest number is: %d\n", largest_num);
}

/**
 * @brief Evaluates and prints the smallest number among three integers.
 * @param first_num First integer.
 * @param second_num Second integer.
 * @param third_num Third integer.
 */
void print_smallest(int first_num, int second_num, int third_num)
{
    int smallest_num = (second_num <= first_num && second_num <= third_num) ? second_num :
                       (third_num <= first_num && third_num <= second_num) ? third_num : first_num;

    printf("The smallest number is: %d\n", smallest_num);
}

/**
 * @brief Checks for equality among numbers and triggers largest/smallest evaluations.
 * @param first_num First integer.
 * @param second_num Second integer.
 * @param third_num Third integer.
 */
void process_number_comparison(int first_num, int second_num, int third_num)
{
    if (first_num == second_num && second_num == third_num) 
    {
        printf("All three numbers are equal.\n");
        return;
    }

    print_largest(first_num, second_num, third_num);
    print_smallest(first_num, second_num, third_num);
}


int main(void) 
{
    int first_num = 4;
    int second_num = 8;
    int third_num = 3;

    process_number_comparison(first_num, second_num, third_num);

    return 0;
}