#include <stdio.h>

int main()
{
    int i;

    for (i = 0; i <= 255; i++)
        printf("Codice car: %d; Carattere: %c\n", i, i);
    return 0;
}