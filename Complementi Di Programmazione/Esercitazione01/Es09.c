#include <stdio.h>
#include <math.h>

int main()
{
    int N, i, n, num = 0;

    printf("inserisci numero di bit N: ");
    scanf("%d", &N);
    i = 0;
    while (i < N)
    {
        printf("inserisci il valore del prossimo bit meno significativo: ");
        scanf("%d", &n);
        num += n * pow(2,i);
        i++;
    }
    printf("%d", num);
}
