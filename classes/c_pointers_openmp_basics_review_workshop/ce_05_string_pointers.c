#include <stdio.h>

int main()
{
    char *string = "AC Milan";
    char *pntr_string = string;

    while (*pntr_string != '\0') 
    {
        printf("%c = %p\n", *pntr_string, (void*)pntr_string);
        pntr_string++;
    }
    return 0;
}