#include <stdio.h>

int main()
{
    int N1, N2, n, mcm;

    printf("inserisci il numero N1: ");
    scanf("%d", &N1);
    printf("inserisci il numero N2: ");
    scanf("%d", &N2);

    mcm = 1;
    n = 1;
    while (N1 != 1 && N2 != 1)
    {
        n++;
        while ((N1 % n == 0) || (N2 % n == 0))
        {
            mcm = mcm * n;
            if (N1 % n == 0)
            {
                N1 = N1 / n;
            }
               
            if (N2 % n == 0)
            {
                N2 = N2 / n;
            }
        }
    }
    printf("%d", mcm);
}