#include <stdio.h>
#include <stdlib.h>

int main()
{
    int N;
    printf("Inserisci intero N: ");
    scanf("%d", &N);
    int* p = (int*) malloc(sizeof(int) * N);
    for (int i = 0; i <= N; i++)
    {   
        printf("Indirizzo intero num. %d: %d; Contenuto: %d\n", i, p + i, *(p + i));
    }
    free(p);
    return 0;
}