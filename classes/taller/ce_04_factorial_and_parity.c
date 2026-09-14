/**
 * @file ce_04_factorial_and_parity.c
 * @brief Calculates the factorial of a positive integer using loops and verifies its parity.
 * @author Fabiano Del Villar
 * @date 2026-09-09
 */

#include <stdio.h>
#include <stdbool.h>

/**
 * @brief Calculates the factorial of a given positive integer using a while loop.
 * @param input_num Positive integer to process.
 * @return Calculated factorial as a long integer.
 */
long calculate_factorial(int input_num) 
{
    long result_factorial = 1;
    int current_counter = 1;

    // Standard while loop implementation for factorial calculation
    while (current_counter <= input_num)
    {
        result_factorial *= current_counter;
        current_counter++;
    }
        
    return result_factorial;
} 

bool is_even(long evaluated_value) 
{
    return (evaluated_value % 2 == 0);
}

/**
 * @brief Processes input evaluation and outputs factorial and parity results.
 * @param input_num Integer number to evaluate.
 */
void process_factorial_parity(int input_num)
{
    long factorial_val = calculate_factorial(input_num);
    const char *parity_status = is_even(factorial_val) ? "is EVEN." : "is ODD.";

    printf("Factorial of %d is: %ld\n", input_num, factorial_val);
    printf("The result %ld %s\n", factorial_val, parity_status);
}


int main(void)
{
    int input_num = 5;

    process_factorial_parity(input_num);

    return 0;
}