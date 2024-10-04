#include <stdio.h>
#include <math.h>

int main()
{
    int a, b, dist;
    int* pa = &a;
    int* pb = &b;
    int* pc;
    dist = pb - pa;
    int distva = abs(pb - pa);
    printf("la distanza (in ternmini di blocchi di memoria di tipo int (4 byte)) in valore assoluto fra le variabili a e b e': %d\n", distva);
    if (dist > 0)
        pc = pb + dist;
    else if (dist < 0)
        pc = pb - dist;
    
    *pc = 13;
    printf("%d\n", a);

    return 0;
}