#include <stdio.h>
#include <stdlib.h>

int main()
{
    int* px = (int*) malloc(sizeof(int));
    int* pmax = px + 1;
    printf("Inserisci numero: ");
    scanf("%d", px);
    *pmax = *px;
    while (*px != 0)
    {
        printf("Inserisci numero: ");
        scanf("%d", px);
        if (*px > *pmax)
            *pmax = *px;
    }
    printf("%d", *pmax);
    free(px);
    free(pmax);
    return 0;
}