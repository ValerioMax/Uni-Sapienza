#include <stdio.h>

int main()
{
    int N, n, i, j, somma;

    printf("inserisci numero di cifre della serie di Fibonacci: ");
    scanf("%d", &N);
    i = 1;
    j = 1;
    printf("%d ", i);
    printf("%d ", j);
    for (n = 1; n <= N - 2; n++)
    {
        somma = i + j;
        printf("%d ", somma);
        i = j;
        j = somma;
    }
}