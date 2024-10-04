#include <stdio.h>

int main()
{
    int N, M, w = 0, h, j, i, z;
    printf("inserisci parametro N: ");
    scanf("%d", &N);
    printf("inserisci parametro M: ");
    scanf("%d", &M);
    /*ciclo che scandisce le righe*/
    while (w < N*M)
    {
        w += 2*M;

        /*ciclo che scandisce le righe che iniziano per asterisco*/
        z = 0;
        while (z < M)
        {
            z++;
            /*ciclo che scandisce la singola riga*/
            h = 0;
            while (h < N*M)
            {
                h += 2*M;
                /*fai M asterischi*/
                i = 0;
                while (i < M)
                {
                    i++;
                    printf("*");
                }

                /*fai M underscore*/
                j = 0;
                while (j < M)
                {
                    j++;
                    printf("_");
                }
            }
            printf("\n");
        }

        /*ciclo che scandisce le righe che iniziano per underscore*/
        z = 0;
        while (z < M)
        {
            z++;
            /*ciclo che scandisce la singola riga*/
            h = 0;
            while (h < N*M)
            {
                h += 2*M;
                /*fai M underscore*/
                i = 0;
                while (i < M)
                {
                    i++;
                    printf("_");
                }

                /*fai M asterischi*/
                j = 0;
                while (j < M)
                {
                    j++;
                    printf("*");
                }
            }
            printf("\n");
        }
    }
}