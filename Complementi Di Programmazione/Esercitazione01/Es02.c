#include <stdio.h>

int main()
{
    float i;
    float j = 0;
    float media;
    float somma = 0;

    while (i != 0)
    {
        printf("inserisci un numero: ");
        scanf("%f", &i);
        j++;
        somma += i;
        media = somma / j;
    }
    printf("%f", media);
}