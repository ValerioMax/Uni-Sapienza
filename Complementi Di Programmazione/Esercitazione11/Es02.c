#include <stdio.h>
#include <stdlib.h>
#include "albero_binario.h"
#include "lista.h"

void printa(TipoAlbero a)
{
    if (!estVuoto(a))
    {
        printa(sinistro(a));
        printa(destro(a));
        printf("%d, ", radice(a));
    }
}

int max(int a, int b)
{
    if (a > b)
        return a;
    else
        return b;
}

bool foglia(TipoAlbero a)
{
    if (estVuoto(sinistro(a)) && estVuoto(destro(a)))
        return true;
    else
        return false;
}

bool singolo(TipoAlbero(a))
{
    if ((estVuoto(sinistro(a)) && !estVuoto(destro(a))) || (!estVuoto(sinistro(a)) && estVuoto(destro(a))))
        return true;
    else
        return false;
}

TipoLista concat(TipoLista l1, TipoLista l2)
{
    if (estVuota(l1))
        return l2;
    else
        return cons(car(l1), concat(cdr(l1), l2));
}

//RAGIONARE DALL'ALTO IN QUESTI CASI!: IMMAGINARE SOLO RADICE PADRE E DUE SOTTOALBERI!
//Pensare che profondita(sinistro(a)) restituisce la profondità del sott.alb sinistro e profondita(destro(a)) restituisce la profondità del sott.alb destro e il gioco è fatto!
//Per trovare la prof. di un sott.alb quando arriverà alla fine restituirà -1 ma progressivamente gli viene sommato +1 a ogni chiamata (per ogni livello)
//[es.: sott.alb sx ha prof. 4, si avrà sx = 1 + (1 + (1 + (1 + (1 + (-1))))) = 4
//      sott.alb dx ha prof. 5, si avrà dx = 1+ (1 + (1 + (1 + (1 + (1 + (-1)))))) = 5
//      max(4, 5) = 5
//NON PENSARE A TUTTI I PERCORSI CHE VENGONO PROGRESSIVAMENTE FATTI MA RAGIONARE DALL'ALTO PENSANDO SOLO A DUE SOTTOALBERI
int profondita(TipoAlbero a)
{
    if (estVuoto(a))
        return -1;
    else
    {
        int sx = 1 + profondita(sinistro(a));
        int dx = 1 + profondita(destro(a));
        return max(sx, dx);
    }
}

//COME E' SCRITTO NON E' INTUITIVO, VEDERE SOTTO
TipoInfoAlbero trova_massimo(TipoAlbero a)
{
    if (estVuoto(a))
        return -1;
    else
    {
        int max = radice(a);
        int max_sx = trova_massimo(sinistro(a));
        int max_dx = trova_massimo(destro(a));

        if (max_sx > max)
            max = max_sx;
        if (max_dx > max)
            max = max_dx;
        
        return max;        
    }
}

//ANCHE QUI RAGIONO DALL'ALTO: SULLA RADICE PADRE E SU SOLO DUE SOTTOALBERI!
//Come minimo il max è la radice, poi calcolo il max del sottoalbero sx e lo comparo con max, poi trovo il max del sott.alb dx e lo comparo con max.
//Alla fine restituirà -1 ma nel mentre lo sto comparando con la radice corrente!
int trova_massimo1(TipoAlbero a)
{
    if (estVuoto(a))
        return -1;
    else
    {
        int max = radice(a);
        int max_sx = trova_massimo(sinistro(a));
        if (max_sx > max)
            max = max_sx;

        int max_dx = trova_massimo(destro(a));
        if (max_dx > max)
            max = max_dx;
        
        return max;
    }
}

TipoInfoAlbero somma_foglie(TipoAlbero a)
{
    if (estVuoto(a))
        return 0;
    else
    {
        if (foglia(a))
            return radice(a);
        else
            return somma_foglie(sinistro(a)) + somma_foglie(destro(a));
    }
}

int cerca_livello_aux(TipoAlbero a, TipoInfoAlbero v, int i)
{
    if (estVuoto(a))
        return -1;
    else if (radice(a) == v)
        return i;
    else
        return max(cerca_livello_aux(sinistro(a), v, i+1), cerca_livello_aux(destro(a), v, i+1));
}

int cerca_livello(TipoAlbero a, TipoInfoAlbero v)
{
    return cerca_livello_aux(a, v, 0);
}

int conta_dispari(TipoAlbero a)
{
    if (estVuoto(a))
        return 0;
    else
    {
        if (!estVuoto(sinistro(a)) && !estVuoto(destro(a)) && (radice(a) + radice(sinistro(a)) + radice(destro(a))) % 2 != 0)
            return 1 + conta_dispari(sinistro(a)) + conta_dispari(destro(a));
        else if (!estVuoto(sinistro(a)) && estVuoto(destro(a)) && (radice(a) + radice(sinistro(a))) % 2 != 0)
            return 1 + conta_dispari(sinistro(a));
        else if (estVuoto(sinistro(a)) && !estVuoto(destro(a)) && (radice(a) + radice(destro(a))) % 2 != 0)
            return 1 + conta_dispari(destro(a));
        else if (foglia(a) && radice(a) % 2 != 0)
            return 1;
        else
            return conta_dispari(sinistro(a)) + conta_dispari(destro(a));
    }
}

int somma_singoli(TipoAlbero a)
{
    if (estVuoto(a))
        return 0;
    else if (singolo(a))
        return 1 + somma_singoli(sinistro(a)) + somma_singoli(destro(a));
    else
        return somma_singoli(sinistro(a)) + somma_singoli(destro(a));
}

TipoLista albero_lista_aux(TipoAlbero a, TipoLista l)
{
    if (estVuoto(a))
        return listaVuota();
    else
    {
        l = albero_lista_aux(sinistro(a), l);
        l = cons(radice(a), l);
        l = albero_lista_aux(destro(a), l);
        return l;
    }
}
TipoLista albero_lista(TipoAlbero a)
{
    return albero_lista_aux(a, listaVuota());
}

void somma_sottoalbero(TipoAlbero a)
{
    if (!estVuoto(a))
    {
        somma_sottoalbero(sinistro(a));
        somma_sottoalbero(destro(a));
        if (a->sinistro != NULL && a->destro != NULL)
            a->info = a->info + a->sinistro->info + a->destro->info;
        else if (a->sinistro == NULL && a->destro != NULL)
            a->info = a->info + a->destro->info;
        else if (a->sinistro != NULL && a->destro == NULL)
            a->info = a->info + a->sinistro->info;
    }
}

void scambia_foglie(TipoAlbero a)
{
    if (!estVuoto(a))
    {
        scambia_foglie(sinistro(a));
        scambia_foglie(destro(a));
        if (!estVuoto(a->sinistro) && !estVuoto(a->destro) && foglia(a->sinistro) && foglia(a->destro))
        {
            int temp = a->sinistro->info;
            a->sinistro->info = a->destro->info;
            a->destro->info = temp;
        }
    }
}

void max_figli_livello(TipoAlbero a, int livello)
{
    if (!estVuoto(a))
    {
        if (livello == 0)
        {
            if (a->sinistro != NULL && a->destro != NULL)
                a->info = max(a->sinistro->info, a->destro->info);
            else if (a->sinistro == NULL && a->destro != NULL)
                a->info = a->destro->info;
            else if (a->sinistro != NULL && a->destro == NULL)
                a->info = a->sinistro->info;
            else
                a->info = 0;
        }
        max_figli_livello(sinistro(a), livello-1);
        max_figli_livello(destro(a), livello-1);
    }
}

void scambia_foglie_livello(TipoAlbero a, int livello)
{
    if (!estVuoto(a))
    {
        if (livello == 1)
        {
            if (foglia(a->sinistro) && foglia(a->destro))
            {
                int temp = a->sinistro->info;
                a->sinistro->info = a->destro->info;
                a->destro->info = temp;
            }
        }
        scambia_foglie_livello(sinistro(a), livello-1);
        scambia_foglie_livello(destro(a), livello-1);
    }
}

int main()
{
    //livello 0
    TipoAlbero a = creaAlbBin(2, NULL, NULL);
    //livello 1
    a->sinistro = creaAlbBin(5, NULL, NULL); 
    a->destro = creaAlbBin(7, NULL, NULL);
    //livello 2
    a->sinistro->sinistro = creaAlbBin(1, NULL, NULL);
    a->sinistro->destro = creaAlbBin(3, NULL, NULL);
    a->destro->sinistro = creaAlbBin(9, NULL, NULL);
    a->destro->destro = creaAlbBin(6, NULL, NULL);

    printa(a);
    printf("\n");
    // printf("%d\n", trova_massimo(a));
    // printf("%d\n", somma_foglie(a));
    // printf("%d\n", cerca_livello(a, 5));
    // printf("%d\n", conta_dispari(a));
    // printf("%d\n", somma_singoli(a));

    // TipoLista l = albero_lista(a);
    // printlist(l);

    // somma_sottoalbero(a);
    // printa(a);

    // scambia_foglie(a);
    // printa(a);

    // max_figli_livello(a, 1);
    // printa(a);

    // scambia_foglie_livello(a, 2);
    // printa(a);

    printf("%d\n", profondita(a));
    printf("%d\n", trova_massimo1(a));

    return 0;
}