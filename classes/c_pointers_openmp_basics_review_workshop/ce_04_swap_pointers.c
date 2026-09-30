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
