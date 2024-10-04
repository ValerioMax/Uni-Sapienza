#include <stdio.h>

int main()
{
    int N, i, j, num;

    printf("inserisci numero di righe del triangolo di Floyd: ");
    scanf("%d", &N);
    i = 0;
    j = 0;
    num = 0;
    /*contatore di righe*/
    while (i < N)
    {
        i++;
        /*contatore di numeri nelle righe*/
        j = 0;
        while (j < i)
        {
            j++;
            num++;
            printf("%d ", num);
        }
        printf("\n");
    }
}