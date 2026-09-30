#include <stdio.h>

#define N 10

int sum_array(int *array)
{
    int sum = 0;
    for (int index = 0; index < N; index++)
        sum += *(array + index);

    return sum;
}

int main()
{
    int array[N] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    printf("The sum of the array elements is: %d\n", sum_array(array));
    return 0;
}