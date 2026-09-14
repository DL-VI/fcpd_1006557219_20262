/**
 * @file ce_08_grade_letter_conversion.c
 * @brief Converts a numerical grade (0-100) to a letter grade using ternary operators.
 * @author Fabiano Del Villar
 * @date 2026-09-09
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/**
 * @brief Evaluates a numerical score and prints its corresponding letter grade.
 * @param score Numerical grade between 0 and 100.
 */
void evaluate_letter_grade(int score)
{
    printf("Score: %d\n", score);
    printf("Grade: ");

    (score >= 0 && score <= 20) ? printf("F") :
    (score > 20 && score <= 40) ? printf("D") :
    (score > 40 && score <= 60) ? printf("C") :
    (score > 60 && score <= 80) ? printf("B") : printf("A");

    printf("\n");
}

/**
 * @brief Generates a random grade and triggers grade evaluation.
 */
void process_grade_evaluation(void)
{
    // Generates a random grade between 0 and 100
    int random_score = rand() % 101;

    evaluate_letter_grade(random_score);
}

int main(void)
{
    srand((unsigned int)time(NULL));

    process_grade_evaluation();

    return 0;
}