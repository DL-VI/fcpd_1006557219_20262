/**
 * @file ce_05_string_pointers.c
 * @brief Practice logic exercises in C focusing on pointers, double pointers,
 * and pointer arithmetic
 * @author Fabiano Del Villar
 * @date 2026-09-28
 *
 * FUNCTIONALITY:
 * Declares a character string literal ("AC Milan") and iterates through each
 * character using a pointer (`pntr_string`). It prints each character along with
 * its specific memory address using pointer incrementing (`pntr_string++`)
 * until reaching the null terminator (`'\0'`).
 *
 * EXPECTED OUTPUT:
 * A = 0x7ff7bfe0b7a0
 * C = 0x7ff7bfe0b7a1
 *   = 0x7ff7bfe0b7a2
 * M = 0x7ff7bfe0b7a3
 * i = 0x7ff7bfe0b7a4
 * l = 0x7ff7bfe0b7a5
 * a = 0x7ff7bfe0b7a6
 * n = 0x7ff7bfe0b7a7
 * (Note: Exact hexadecimal memory addresses will vary per execution)
 */

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