#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 3

void fill_matrix(int **matrix)
{
    for (int index_row = 0; index_row < N; index_row++)
        for (int index_column = 0; index_column < N; index_column++)
            *(*(matrix + index_row) + index_column) = rand() % 100;
}

void print_matrix(int **matrix)
{
    for (int index_row = 0; index_row < N; index_row++) 
    {
        for (int index_column = 0; index_column < N; index_column++)
        {
            if (index_column == N - 1) 
                printf("%d\n", *(*(matrix + index_row) + index_column));
            else  printf("%d ", *(*(matrix + index_row) + index_column));
        }
    }
}

int main()
{
    srand(time(NULL));

    int **pntr_matrix = (int**)malloc(N * sizeof(int*));

    for (int index = 0; index < N; index++)
        *(pntr_matrix + index) = (int*)malloc(N * sizeof(int));

    fill_matrix(pntr_matrix);
    print_matrix(pntr_matrix);
    free(pntr_matrix);

    return 0;
}
