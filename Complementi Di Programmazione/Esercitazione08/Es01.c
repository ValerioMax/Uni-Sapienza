#include <stdio.h>
#include <stdlib.h>
#include "insf_scl.h"

Insieme init(int *arr, int n)
{
    Insieme ins = insiemeVuoto();
    for (int i = 0; i < n; i++)
        ins = inserisci(ins, arr[i]);
    return ins;
}

void print(Insieme s)
{
    if (s->next == NULL)
        printf("%d, ", s->info);
    else
    {
        printf("%d, ", s->info);
        print(s->next);
    }
}

void stampa(Insieme ins)
{
    IteratoreInsieme it = creaIteratoreInsieme(ins);
    while (hasNext(it))
    {
        T e = next(it);
        printf("%d ", e);
    }
    printf("\n") ;
}

void printins(Insieme s)
{
    printf("{");
    print(s);
    printf("\b\b}\n");
}

Insieme copy(Insieme s)
{
    IteratoreInsieme it = creaIteratoreInsieme(s);
    T e;
    Insieme ins = insiemeVuoto();
    while (hasNext(it))
    {
        e = next(it);
        ins = inserisci(ins, e);
    }
    return ins;
}

int size(Insieme s)
{
    IteratoreInsieme it = creaIteratoreInsieme(s);
    T e;
    int len = 0;
    while (hasNext(it))
    {
        e = next(it);
        len++;
    }
    return len;
}

bool subset(Insieme a, Insieme b)
{
    IteratoreInsieme it = creaIteratoreInsieme(a);
    T e = a->info;
    while (hasNext(it))
    {
        if (!membro(b, e))
            return false;
        else
            e = next(it);
    }
    return true;
}

bool equal(Insieme a, Insieme b)
{
    if ((size(a) == size(b)) && (subset(a, b)))
        return true;
    else
        return false;
}

Insieme intersection(Insieme a, Insieme b)
{
    Insieme ins = insiemeVuoto();
    IteratoreInsieme it = creaIteratoreInsieme(a);
    T e = a->info;
    
    if (membro(b, e))
        ins = inserisci(ins, e);
    while (hasNext(it))
    {
        e = next(it);
        if (membro(b, e))
            ins = inserisci(ins, e);
    }
    return ins;
}

Insieme unione(Insieme a, Insieme b)
{
    IteratoreInsieme it = creaIteratoreInsieme(a);
    T e = a->info;
    Insieme ins = copy(b);

    if (!membro(ins, e))
        ins = inserisci(ins, e);
    
    while (hasNext(it))
    {
        e = next(it);
        if (!membro(ins, e))
            ins = inserisci(ins, e);
    }
    return ins;
}

int main()
{
    int v1[] = {2,3,3,45,1,6};
    Insieme s1 = init(v1, 6);
    //printins(s1);
    Insieme s2 = copy(s1);
    //printins(s2);
    //printf("s1 ha %d elementi\n", size(s1));

    int v2[] = {2,3,1,45,23,5,5,9,1};
    Insieme s3 = init(v2, 9);
    // printins(s3);
    // if (subset(s1, s3))
    //     printf("OK");
    // else
    //     printf("NO");

    // if (equal(s1, s3))
    //     printf("OK");
    // else
    //     printf("NO");

    // Insieme intersezione = intersection(s1, s3);
    // printins(s1);
    // printins(s3);
    // printins(intersezione);

    Insieme unio = unione(s1, s3);
    printins(s1);
    printins(s3);
    printins(unio);

    return 0;
}