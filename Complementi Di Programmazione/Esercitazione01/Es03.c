#include <stdio.h>

int main()
{
    int N, i = 0, j = 0;

    printf("inserisci dimensioni quadrato: ");
    scanf("%d", &N);
    while (i < N)
    {
        i++;
        j = 0;
        while (j < N)
        {
            j++;
            printf("*");
        }
        printf("\n");
    }
    
}