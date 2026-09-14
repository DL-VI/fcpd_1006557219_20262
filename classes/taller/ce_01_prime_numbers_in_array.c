/**
 * @file ce_01_prime_numbers_in_array.c
 * @brief Generates a random array and counts prime numbers found within.
 * @author Fabiano Del Villar
 * @date 2026-09-09
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

#define SIZE 50

/* Global array to store generated numbers */
int data[SIZE];

/**
 * @brief Fills the global array with random numbers between 0 and 99.
 */
void fill_array(void)
{
    for (int index = 0; index < SIZE; index++)
    {
        data[index] = rand() % 100;
    }
}

/**
 * @brief Checks if a given integer is a prime number.
 * @param number Integer to evaluate.
 * @return true if the number is prime, false otherwise.
 */
bool is_prime(int number)
{
    if (number <= 1)
        return false;
    if (number == 2)
        return true;
    if (number % 2 == 0)
        return false;

    for (int divisor = 3; divisor < number; divisor += 2)
    {
        if (number % divisor == 0) 
            return false;
    }

    return true;
}

/**
 * @brief Iterates through the global array and counts prime numbers.
 * @return Total number of prime elements.
 */
int count_prime_numbers(void)
{
    int prime_count = 0;
    
    for (int index = 0; index < SIZE; index++)
    {
        int number = data[index];
        if (is_prime(number)) 
        {
            prime_count++;
        }
    }

    return prime_count;
}

int main(void)
{
    srand((unsigned int)time(NULL));
    fill_array();

    int total_primes = count_prime_numbers();
    printf("Number of prime numbers found: %d\n", total_primes);

    return 0;
}