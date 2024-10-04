#include <stdio.h>
#include <stdlib.h>
#include "insf_scl.h"

Insieme init(int *arr, int n)
{
    if (n == 0)
        return inserisci(insiemeVuoto(), arr[n]);
    else
        return inserisci(init(arr, n-1), arr[n-1]);
}

void print(Insieme s)
{
    IteratoreInsieme it = creaIteratoreInsieme(s);
    while (hasNext(it))
    {
        T e = next(it);
        printf("%d, ", e);
    }
}

Insieme copy(Insieme s)
{
    IteratoreInsieme it = creaIteratoreInsieme(s);
    Insieme s1 = insiemeVuoto();
    while (hasNext(it))
    {
        T e = next(it);
        s1 = inserisci(s1, e);
    }
    return s1;
}

int size(Insieme s)
{
    if (estVuoto(s))
        return 0;
    IteratoreInsieme it = creaIteratoreInsieme(s);
    int n = 0;
    while (hasNext(it))
    {
        T e = next(it);
        n++;
    }
    return n;
}

bool subset(Insieme a, Insieme b)
{
    IteratoreInsieme it = creaIteratoreInsieme(a);
    while (hasNext(it))
    {
        T e = next(it);
        if (!membro(b, e))
            return false;
    }
    return true;
}

bool equal(Insieme a, Insieme b)
{
    if (subset(a, b) && size(a) == size(b))
        return true;
    else
        return false;
}

Insieme intersection(Insieme a, Insieme b)
{
    IteratoreInsieme it = creaIteratoreInsieme(a);
    Insieme s = insiemeVuoto();
    while (hasNext(it))
    {
        T e = next(it);
        if (membro(b, e))
            s = inserisci(s, e);
    }
    return s;
}

Insieme unione(Insieme a, Insieme b)
{
    Insieme s = copy(b);
    IteratoreInsieme it = creaIteratoreInsieme(a);
    while (hasNext(it))
        s = inserisci(s, next(it));
    return s;
}

int main()
{
    Insieme s1 = inserisci(inserisci(inserisci(insiemeVuoto(), 3), 4), 7);
    // int v[] = {4,5,3,6};
    // Insieme s2 = init(v, 4);
    // print(s2);

    // Insieme s3 = copy(s1);
    // print(s3);

    // printf("%d\n", size(s1));

    // Insieme a = inserisci(inserisci(inserisci(insiemeVuoto(), 3), 4), 7);
    // Insieme b = inserisci(inserisci(inserisci(insiemeVuoto(), 2), 4), 7);
    // if (subset(a, b))
    //     printf("SI");
    // else
    //     printf("NO");

    // Insieme a = inserisci(inserisci(inserisci(insiemeVuoto(), 3), 4), 7);
    // Insieme b = inserisci(inserisci(inserisci(insiemeVuoto(), 3), 4), 7);
    // if (equal(a, b))
    //     printf("SI");
    // else
    //     printf("NO");

    Insieme a = inserisci(inserisci(inserisci(inserisci(insiemeVuoto(), 3), 4), 7), 10);
    Insieme b = inserisci(inserisci(inserisci(insiemeVuoto(), 2), 4), 7);
    Insieme s = intersection(a, b);
    //print(s);
    Insieme u = unione(a, b);
    print(u);
    
    return 0;
}