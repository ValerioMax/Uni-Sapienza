#include <stdio.h>
#include <stdlib.h>
#include "lista.h"

TipoLista init_aux(T *vec, int len, int i)
{
    if (len == i)
        return listaVuota();
    else
        return cons(vec[i], init_aux(vec, len, i+1));
}

TipoLista init(T *vec, int len)
{
    return init_aux(vec, len, 0);
}

TipoLista doubledCopy(TipoLista list)
{
    if (estVuota(list))
        return listaVuota();
    else
        return cons(car(list), cons(car(list), doubledCopy(cdr(list))));
}

TipoLista multipleSublist(TipoLista list, unsigned int m)
{
    if (estVuota(list))
        return listaVuota();
    else if (car(list) % m == 0)
        return cons(car(list), multipleSublist(cdr(list), m));
    else
        return multipleSublist(cdr(list), m);
}

TipoLista subList_aux(TipoLista list, int start, int end, int i)
{
    if (estVuota(list))
        return listaVuota();
    else if (i >= start && i < end)
        return cons(car(list), subList_aux(cdr(list), start, end, i+1));
    else
        return subList_aux(cdr(list), start, end, i+1);
}

TipoLista subList(TipoLista list, int start, int end)
{
    return subList_aux(list, start, end, 0);
}

TipoLista interleave(TipoLista l1, TipoLista l2)
{
    if (estVuota(l1))
        return listaVuota();
    else
        return cons(car(l1), cons(car(l2), interleave(cdr(l1), cdr(l2))));
}

TipoLista concat(TipoLista l1, TipoLista l2)
{
    if (estVuota(l1))
        return l2;
    else
        return cons(car(l1), concat(cdr(l1), l2));
}

TipoLista append(T e, TipoLista l)
{
    TipoLista le = cons(e, listaVuota());
    return concat(l, le);
}

//get() restituisce l'elemento alla posizione i della lista l.
T get(TipoLista l , int i)
{
    if (i == 0)
        return car(l);
    else
        return get(cdr(l), i-1);
}

//ins() inserisce l'elemento e alla posizione i della lista l (restituendo una nuova lista)
TipoLista ins(TipoLista l, int i, T e)
{
    if (estVuota(l))
        return listaVuota();
    if (i == 0)
        return cons(car(l), cons(e, ins(cdr(l), i-1, e)));
    else
        return cons(car(l), ins(cdr(l), i-1, e));
}

TipoLista ins1(TipoLista l, int i, T e)
{
    if (i < 0 || estVuota(l))
    {
        printf("Index out of range oppure lista vuota.\n");
        exit(1);
    }
    else if (i == 0)
        return cons(e, l);
    else
        return cons(car(l), ins1(cdr(l), i - 1, e));
    
}

int main()
{
    TipoLista l1 = cons(2, cons(4, cons(9, cons(12, listaVuota()))));
    printlist(l1);
    // TipoLista l2 = doubledCopy(l1);
    // printlist(l2);

    // TipoLista l3 = multipleSublist(l1, 2);
    // printlist(l3);

    // TipoLista l4 = subList(l1, 1, 4);
    // printlist(l4);

    // TipoLista l6 = cons(5, cons(7, cons(2, cons(1, listaVuota()))));
    // printlist(l6);    

    // TipoLista l5 = interleave(l1, l6);
    // printlist(l5);

    // TipoLista l7 = cons(2, cons(4, cons(9, cons(12, listaVuota()))));
    // printlist(l7);
    // TipoLista l8 = append(5, l7);
    // printlist(l8);

    // TipoLista l9 = concat(l7, l8);
    // printlist(l9);

    // printf("%d\n", get(l9, 4));

    // TipoLista l10 = ins1(l7, 2, 1000);
    // printlist(l10);

    int v[]= {1,2,2,4,5,7};
    TipoLista l = init(v, 6);
    printlist(l);

    return 0;
}