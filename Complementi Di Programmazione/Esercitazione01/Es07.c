#include <stdio.h>

int main()
{
    int n, min;

    printf("inserisci un numero: ");
    scanf("%d", &n);
    if (n != 0)
    {
        min = n;
        while (n != 0)
        {
            if (n < min)
                min = n;
            printf("inserisci un numero: ");
            scanf("%d", &n);
        }
        printf("%d", min);
        return ("%d", min);
    }
}