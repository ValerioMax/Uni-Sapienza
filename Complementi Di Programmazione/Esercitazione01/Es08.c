#include <stdio.h>

int main()
{
    int n, i;

    printf("inserisci numero: ");
    scanf("%d", &n);
    if (n != 0)
    {
        while (n != 0)
        {
            printf("%d\n", n);
            i = 0;
            while (i < n)
            {
                i++;
                printf("*");
            }
            printf("\n");
            printf("inserisci numero: ");
            scanf("%d", &n);         
        }
    } 
}