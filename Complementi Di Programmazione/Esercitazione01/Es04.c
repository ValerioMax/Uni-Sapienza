#include <stdio.h>

int main()
{
    int N, i = 0, j = 0;

    printf("inserisci dimensioni quadrato: ");
    scanf("%d", &N);

    while (j < N)
        {
            j++;
            printf("*");
        }
        printf("\n");

    i = 0;
    while (i < N - 2)
    {
        i++;
        j = 0;
        printf("*");
        while (j < N - 2)
        {
            j++;
            printf(" ");
        }
        printf("*");
        printf("\n");
    }
    
    j = 0;
    while (j < N)
        {
            j++;
            printf("*");
        }
}