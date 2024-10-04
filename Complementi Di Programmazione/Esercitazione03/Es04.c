#include <stdio.h>
#include <stdlib.h>

int main()
{
    float* pt = (float*) malloc(sizeof(float));
    char* ps =  (char*) pt + 4;
    printf("inserisci valore: ");
    scanf("%f", pt);
    printf("inserisci scala('C', 'K', 'F'): ");
    scanf(" %c", ps);
    if (*ps == 'C')
    {
        printf("K = %f\n", *pt + 273.15);
        printf("F = %f\n", *pt * 9/5 + 32);
    }
    else if (*ps == 'K')
    {
        printf("C = %f\n", *pt - 273.15);
        printf("F = %f\n", *pt * 9/5 + 32);
    }
    else if (*ps == 'F')
    {
        printf("C = %f\n", (*pt - 32) * 5/9);
        printf("K = %f\n", ((*pt - 32) * 5/9) + 273.15);
    }
    free(pt);
    free(ps);
    return 0;
}
