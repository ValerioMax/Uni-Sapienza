#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int* allocaInt()
{
    int* p = (int*) malloc(sizeof(int));
    return p;
}

void printInt(int *i1, int *i2)
{
    printf("%d, %d", *i1, *i2);
}

void soluzioneEquazione(int a, int b, int c)
{
    printf("x1 = %f, x2 = %f", (-b + sqrt(pow(b,2) + 4*a*c))/(2*a), (-b + sqrt(pow(b,2) - 4*a*c))/(2*a));
}

int MCD(int i1, int i2)
{
    int n = 1, mcd = 1;
    while (i1 != 1 || i2 != 1)
    {
        n++;
        while (i1 % n == 0 || i2 % n == 0)
        {
            if (i1 % n == 0 && i2 % n == 0)
                mcd = mcd * n;
            if (i1 % n == 0)
                i1 = i1 / n;
            if (i2 % n == 0)
                i2 = i2 / n;
        }
    }
    return mcd;
}

int mcm(int i1, int i2)
{
    int n = 1, Mcm = 1;
    while (i1 != 1 && i2 != 1)
    {
        n++;
        while (i1 % n == 0 || i2 % n == 0)
        {
            Mcm = Mcm * n;
            if (i1 % n == 0)
                i1 = i1 / n;
            if (i2 % n == 0)
                i2 = i2 / n;
        }
    }
    return Mcm;
}

void conversioneTemperatura(float t, char c)
{
    if (c == 'C')
    {
        printf("K = %f\n", t + 273.15);
        printf("F = %f\n", t * 9/5 + 32);
    }
    else if (c == 'K')
    {
        printf("C = %f\n", t - 273.15);
        printf("F = %f\n", t * 9/5 + 32);
    }
    else if (c == 'F')
    {
        printf("C = %f\n", (t - 32) * 5/9);
        printf("K = %f\n", ((t - 32) * 5/9) + 273.15);
    }
}

void* conversioneTemperaturaP(float *t, char c)
{
    
}

int main()
{
    int c = MCD(90,140);
    c = mcm(27,12);
    printf("%d", c);

    return 0;
}
