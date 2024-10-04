#include <stdio.h>

int main()
{
    char c;
    short int s;
    int i;
    long int l;
    float f;
    double d;

    printf("dimensione char: %d\n", sizeof(char));
    printf("dimensione short int: %d\n", sizeof(short int));
    printf("dimensione int: %d\n", sizeof(int));
    printf("dimensione long int: %d\n", sizeof(long int));
    printf("dimensione float: %d\n", sizeof(float));
    printf("dimensione double: %d\n", sizeof(double));

    return 0;
}