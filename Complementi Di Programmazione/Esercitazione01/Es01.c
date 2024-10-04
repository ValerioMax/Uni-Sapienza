#include <stdio.h>
 
int main()
{
    printf ("inserisci due numeri a e b per trovare la soluzione di a*x + b = 0: \n");
    float a, b, x ;
    scanf("%f%f", &a , &b);
    x = (-b) / a;
    printf("%f", x);
}