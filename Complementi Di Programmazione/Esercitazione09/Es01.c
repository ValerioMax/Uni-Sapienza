#include <stdio.h>
#include <stdlib.h>
#include "lista.h"
#include <stdbool.h>

void inverti(T vec[], int len)
{
    T temp;
    int j;
    for (int i = 0; i < (len/2); i++)
    {
        j = len-1 - i;
        temp = vec[j];
        vec[j] = vec[i];
        vec[i] = temp;
    }
}
//9.1 versione iterativa
TipoLista init(T *vec, int len)
{
    inverti(vec, len);

    TipoLista l = listaVuota();
    for (int i = 0; i < len; i++)
    {
        l = cons(vec[i], l);
    }
    return l;
}

//9.1 versione ricorsiva
TipoLista init2(T *vec, int len)
{
    if (len == 1)
        return cons(*vec, listaVuota());
    else
        return cons(*vec, init2(vec + 1, len - 1));
}

void printv(T v[], int len)
{
    for (int i = 0; i < len; i++)
        printf("%d, ", v[i]);
    printf("\n");
}

void print(TipoLista l)
{
    if (l->next != NULL)
    {
        printf("%d, ", l->info);
        print(l->next);
    }
    else
        printf("%d ", l->info);
}

void printl(TipoLista l)
{
    printf("[");
    print(l);
    printf("\b]\n");
}

//get() restituisce l'elemento alla posizione i della lista l.
T get(TipoLista l , int i)
{
    if (i < 0 || estVuota(l))
    {
        printf("Index out of range oppure lista vuota.\n");
        exit(1);
    }
    else if (i == 0)
        return car(l);
    else
        return get(cdr(l), i - 1);

}

//ins() inserisce l'elemento e alla posizione i della lista l (restituendo una nuova lista)
TipoLista ins(TipoLista l, int i, T e)
{
    if (i < 0 || estVuota(l))
    {
        printf("Index out of range oppure lista vuota.\n");
        exit(1);
    }
    else if (i == 0)
        return cons(e, l);
    else
        return cons(car(l), ins(cdr(l), i - 1, e));
    
}

int length(TipoLista l)
{
    if (estVuota(l))
        return 0;
    else
        return 1 + length(cdr(l));
}

TipoLista append(TipoLista l, T e)
{
    if(estVuota(l))
        return cons(e, l);
    else
        return cons(car(l), append(cdr(l), e));
}

//9.2 versione iterativa
TipoLista doubledCopy(TipoLista list)
{
    TipoLista l = listaVuota();
    for (int i = 0; i < length(list); i++)
    {
        l = append(l, get(list, i));
        l = append(l, get(list, i));
    }
    return l;
}

//9.2 ausiliaria della versione ricorsiva
TipoLista doubledCopy1_aux(TipoLista list, int len)
{
    if (len == 1)
        return cons(car(list), cons(car(list), listaVuota()));
    else
        return cons(car(list), cons(car(list), doubledCopy1_aux(cdr(list), len-1)));
}

//9.2 versione ricorsiva
TipoLista doubledCopy1(TipoLista list)
{
    int len = length(list);
    return doubledCopy1_aux(list, len);
}

//9.3 versione iterativa
TipoLista multipleSublist(TipoLista list, unsigned int m)
{
    if (estVuota(list))
        return list;
    else
    {
        TipoLista l = listaVuota();
        for (int i = 0; i < length(list); i++)
        {
            if (get(list, i) % m == 0)
                l = append(l, get(list, i));
        }
        return l;
    }
}

//9.3 ausiliaria della versione ricorsiva
TipoLista multipleSublist1_aux(TipoLista list, unsigned int m, int len)
{
    if (len == 1)
    {
        if (car(list) % m == 0)
            return cons(car(list), listaVuota());
        else
            return listaVuota();
    }
    else if (car(list) % m != 0)
        return multipleSublist1_aux(cdr(list), m, len-1);
    else
        return cons(car(list), multipleSublist1_aux(cdr(list), m, len-1));
}

//9.3 versione ricorsiva
TipoLista multipleSublist1(TipoLista list, unsigned int m)
{
    int len = length(list);
    return multipleSublist1_aux(list, m, len);
}

//9.4 versione iterativa
TipoLista subList(TipoLista list, int start, int end)
{
    TipoLista l = listaVuota();
    for (int i = 0; i < length(list); i++)
    {
        if (get(list, i) == start)
        {
            while (get(list, i) != end)
            {
                l = append(l, get(list, i));
                i++;
            }
            return l;
        }
    }
}

//9.4 ausiliaria versione ricorsiva
TipoLista subList1_aux(TipoLista list, int start, int end, int i)
{
    if (i == end)
        return listaVuota();
    else if (i >= start)
        return cons(car(list), subList1_aux(cdr(list), start, end, i+1));
    else if (i < start)
        return subList1_aux(cdr(list), start, end, i+1);
}

//9.4 versione ricorsiva
TipoLista subList1(TipoLista list, int start, int end)
{
    int i = 0;
    return subList1_aux(list, start, end, i);
}

//si assuma che length(l1) == length(l2).
TipoLista interleave(TipoLista l1, TipoLista l2)
{
    TipoLista l = listaVuota();
    for (int i = 0; i < length(l1); i++)
    {
        l = append(l, get(l1, i));
        l = append(l, get(l2, i));
    }
    return l;
}

//da correggere
TipoLista interleave1_aux(TipoLista l1, TipoLista l2, int i, int len)
{
    if (i == len)
        return listaVuota();
    else
        return cons(car(l2), cons(car(l1), interleave1_aux(cdr(l1), cdr(l2), i+1, len)));
}

TipoLista interleave1(TipoLista l1, TipoLista l2)
{
    int i = 0;
    return interleave1_aux(l1, l2, 0, length(l1) * 2);
}

int main()
{
    // int v[] = {2,3,4,4,5,6};
    // TipoLista l = init(v, 6);
    // printl(l);

    // printf("%d\n", get(l, 2));
    // TipoLista l1 = ins(l, 2, 59);
    // printl(l1);
    // printf("%d", length(l));

    // TipoLista l2 = doubledCopy(l);
    // printl(l2);

    // TipoLista l3 = multipleSublist(l, 2);
    // printl(l3);

    // TipoLista l4 = subList(l, 3, 6);
    // printl(l4);

    // int v1[] = {1,3,5,7,9};
    // TipoLista l5 = init(v1, 5);
    // int v2[] = {2,4,6,8,10};
    // TipoLista l6 = init(v2, 5);

    // printl(l5);
    // printl(l6);

    // TipoLista l7 = interleave(l5, l6);
    // printl(l7);

    T v1[] = {1,1,1,1,1,1};
    // printv(v1, 6);
    TipoLista l1 = init2(v1, 6);
    printl(l1);

    // TipoLista l2 = doubledCopy1(l1);
    // printl(l2);

    // TipoLista l3 = multipleSublist1(l1, 3);
    // printl(l3);

    // TipoLista l4 = subList1(l1, 0, 4);
    // printl(l4);

    T v2[] = {2,2,2,2,2,2};
    TipoLista l5 = init2(v2, 6);
    printl(l5);
    TipoLista l6 = interleave1(l1, l5);
    printl(l6);

    return 0;
}