/**
 * @file ce_10_student_management_system.c
 * @brief Student management system using structures, dynamic memory, and pointers.
 * @author Fabiano Del Villar
 * @date 2026-09-09
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define GRADES_COUNT 3
#define MINIMUM_PASSING_GRADE 3.0f

typedef struct
{
    int id;
    char name[50];
    float grades[GRADES_COUNT];
    float average;
} Student;

/**
 * @brief Calculates the average grade of a single student.
 * @param pntr_student Pointer to the Student structure.
 * @return Calculated average grade.
 */
float calculate_average(Student *pntr_student)
{
    float total_sum = 0.0f;

    for (int index = 0; index < GRADES_COUNT; index++)
    {
        total_sum += pntr_student->grades[index];
    }

    return total_sum / GRADES_COUNT;
}

/**
 * @brief Calculates averages and prints all registered students.
 * @param pntr_list Pointer to the array of Student structures.
 * @param count Total number of students.
 */
void display_students(Student *pntr_list, int count)
{
    printf("\n--- STUDENT AVERAGES ---\n");
    for (int index = 0; index < count; index++)
    {
        float current_avg = calculate_average(&pntr_list[index]);
        pntr_list[index].average = current_avg;
        printf("ID: %d | Name: %s | Average: %.2f\n",
               pntr_list[index].id, pntr_list[index].name, pntr_list[index].average);
    }
}

/**
 * @brief Displays the list of students who passed according to the minimum grade.
 * @param pntr_list Pointer to the array of Student structures.
 * @param count Total number of students.
 */
void display_passing_students(Student *pntr_list, int count)
{
    printf("\n--- LIST OF PASSING STUDENTS ---\n");
    for (int index = 0; index < count; index++)
    {
        if (pntr_list[index].average >= MINIMUM_PASSING_GRADE)
        {
            printf("Name: %s\n", pntr_list[index].name);
        }
    }
    printf("\n");
}

/**
 * @brief Prompts user input and handles student processing.
 */
void process_student_records(void)
{
    int total_students;
    printf("\nEnter the number of students to register: ");
    if (scanf("%d", &total_students) != 1 || total_students <= 0)
    {
        printf("Invalid number of students.\n");
        return;
    }

    Student *pntr_students = (Student *)malloc(total_students * sizeof(Student));
    if (pntr_students == NULL)
    {
        printf("Memory allocation failed.\n");
        return;
    }

    for (int index = 0; index < total_students; index++)
    {
        printf("\nStudent Data %d\n", index + 1);
        printf("ID: ");
        scanf("%d", &pntr_students[index].id);

        printf("Name: ");
        scanf(" %49[^\n]", pntr_students[index].name);

        printf("Enter 3 grades [0.0 - 5.0]:\n");
        for (int grade_idx = 0; grade_idx < GRADES_COUNT; grade_idx++)
        {
            printf("Grade %d: ", grade_idx + 1);
            scanf("%f", &pntr_students[index].grades[grade_idx]);
        }
    }

    display_students(pntr_students, total_students);
    display_passing_students(pntr_students, total_students);

    free(pntr_students);
}

int main(void) 
{
    process_student_records();
    return 0;
}