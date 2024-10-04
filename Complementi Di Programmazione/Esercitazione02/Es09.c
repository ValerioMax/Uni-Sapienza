#include <stdio.h>
#include <math.h>

int lensum(int sum){   
    int n, len = 0;
    while (sum - pow(10,n) >= 0)
    {
        len++;
        n++;
    }
    return len;
}

int main()
{
    char c = 0;
    int sum = 0;
    while (c != '*')
    {
        sum += c;
        printf("Inserisci il prossimo carattere del tuo nome terminando la sequenza con il carattere '*': ");
        scanf("%c", &c);       
    }
    int somma = sum;
    while (!((somma >= 1 && somma <= 9) || somma == 11 || somma == 22))
    {
        int i = -1, n = lensum(sum);
        while (n >= 0)
        {
            while (sum >= 0)
            {
                sum -= pow(10,n);
                i++;
            }
            somma += i;
            n--;
        }
        printf("il numero del destino e': %d\n", sum);
        return 0;
    }
    return 0;
}