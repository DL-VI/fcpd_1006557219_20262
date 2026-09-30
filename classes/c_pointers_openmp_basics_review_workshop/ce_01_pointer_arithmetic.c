#include <stdio.h>

#define N 10

void print_array(int *array)
{
    printf("[");
    for (int index = 0; index < N; index++)
    {
        if (index == N - 1)
            printf("%d", *(array + index));
        else printf("%d,", *(array + index));
    }
    printf("]\n");
}

int main()
{
    int array[N] = {1,2,3,4,5,6,7,8,9,10};
    print_array(array);

    return 0;
}