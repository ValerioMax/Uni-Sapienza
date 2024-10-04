#include <stdio.h>
#include <math.h>

int main()
{
    short s;
    int i;
    long l;
    float f;
    double d;

    printf("inserisci s: ");
    scanf("%hd", &s);
    printf("inserisci i: ");
    scanf("%d", &i);
    printf("inserisci l: ");
    scanf("%ld", &l);
    printf("inserisci f: ");
    scanf("%f", &f);
    printf("inserisci d: ");
    scanf("%lf", &d);

    printf("s+10*l = %ld\n", s+10*l);
    printf("(s+i)*l = %ld\n", (s+i)*l);
    printf("(s+i)*l+f = %f\n", (s+i)*l+f);
    printf("s/f + sin(f) = %f\n", s/f + sin(f));
    printf("l+1.5f = %f\n", l+1.5f);
    printf("i<10\n");
    printf("d * 3.14159 = %lf\n", d * 3.14159);

    return 0;
}