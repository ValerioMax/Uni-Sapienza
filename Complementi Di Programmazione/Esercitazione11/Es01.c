#include <stdio.h>
#include <stdlib.h>
#include "albero_binario.h"
#include "lista.h"

bool foglia(TipoAlbero a)
{
    return (a->sinistro == NULL && a->destro == NULL);
}

bool singolo(TipoAlbero a)
{
    return (a->sinistro == NULL && a->destro != NULL || a->sinistro != NULL && a->destro == NULL);
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
	if (estVuota(l))
		return cons(e, l);
	return cons(car(l), append(cdr(l), e));
}


TipoLista concat(TipoLista l1, TipoLista l2)
{
	if (estVuota(l2))
		return l1;
	return concat(append(l1, car(l2)), cdr(l2));
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

// determina il massimo fra due interi
int massimo(int a, int b)
{
    if (a > b)
        return a;
    else
        return b;
}

int profondita(TipoAlbero a)
{
    int s, d;
    if (a == NULL)
        return -1; // l’albero vuoto ha profondita ’ -1
    else
    {
        // calcola la profondita ’ dei sottoalberi
        s = profondita(a->sinistro);
        d = profondita(a->destro);
        // l’albero complessivo ha profondita ’ max(s,d) + 1 (perchè lo tolgo col -1 nel return finale (?))
        return (massimo(s, d) + 1);
    }
}

//print dell'albero visitandolo in postordine
void printa(TipoAlbero a)
{
    if (!estVuoto(a))
    {
        printa(sinistro(a));
        printa(destro(a));
        printf("%d, ", radice(a));
    }
}
//??????????????????????????????????????????????? anche se funziona
TipoInfoAlbero trova_massimo1(TipoAlbero a)
{  
    if(estVuoto(a))
        return -1;
    
    int max = radice(a);
    
    int max_sinistro = trova_massimo1(sinistro(a));

    int max_destro = trova_massimo1(destro(a));
    
    if (max_sinistro > max)
        max = max_sinistro;

    if (max_destro > max)
        max = max_destro;
    
    return max;
}

//perché devo usare i puntatori?
T trova_massimo2_aux(TipoAlbero a, T* p_max)
{
    if (!estVuoto(a))
    {
        trova_massimo2_aux(sinistro(a), p_max);
        trova_massimo2_aux(destro(a), p_max);
        if (radice(a) > *p_max)
            *p_max = radice(a);
        return *p_max;
    }
}

T trova_massimo2(TipoAlbero a)
{
    T max = 0;
    return trova_massimo2_aux(a, &max);
}

T somma_foglie1_aux(TipoAlbero a, T* tot)
{
    if (!estVuoto(a))
    {
        somma_foglie1_aux(sinistro(a), tot);
        somma_foglie1_aux(destro(a), tot);
        *tot = *tot + radice(a);
        return *tot;
    }
}

TipoInfoAlbero somma_foglie1(TipoAlbero a)
{
    T tot = 0;
    return somma_foglie1_aux(a, &tot);
}

//soluzione di Vittorio
// int cerca_livello(TipoAlbero a, TipoInfoAlbero v)
// {
//     if (estVuoto(a))
//         return -1;

//     if (radice(a) == v)
//         return 0;

//     int sx = cerca_livello(sinistro(a), v);

//     int dx = cerca_livello(destro(a), v);

//     //controllo se l'alb sx e l'alb dx sono vuoti
//     if (sx != -1)
//         return 1 + cerca_livello(sinistro(a), v);

//     if (dx != -1)
//         return 1 + cerca_livello(destro(a), v);

//     return -1;   
// }

int cerca_livello_aux(TipoAlbero a, TipoInfoAlbero v, int i)
{
    if (estVuoto(a))
        return -1;
    else if (radice(a) == v)
        return i;
    else
        return massimo(cerca_livello_aux(sinistro(a), v, i+1), cerca_livello_aux(destro(a), v, i+1));
}

int cerca_livello(TipoAlbero a, TipoInfoAlbero v)
{
    return cerca_livello_aux(a, v, 0);
}

int conta_dispari(TipoAlbero a)
{
    if (estVuoto(a))
        return 0;
    else if (!foglia(a))
    {
        if ((radice(sinistro(a)) + radice(destro(a)) + radice(a)) % 2 != 0)
            return 1 + conta_dispari(sinistro(a)) + conta_dispari(destro(a));
        else
            return conta_dispari(sinistro(a)) + conta_dispari(destro(a));
    }
}

int somma_singoli(TipoAlbero a)
{
    if (estVuoto(a))
        return 0;
    else if (singolo(a))
        return radice(a) + somma_singoli(sinistro(a)) + somma_singoli(destro(a));
    else
        return somma_singoli(sinistro(a)) + somma_singoli(destro(a));
}

//essendo l'albero in input un albero di ricerca, con la scansione simmetrica si scansionano e inseriscono nella lista valori in ordine crescente in automatico
TipoLista albero_lista(TipoAlbero a)
{
    if (estVuoto(a))
        return listaVuota();
    else
    {
        TipoLista sx = albero_lista(sinistro(a));
        sx = cons(radice(a), sx);
        TipoLista dx = albero_lista(destro(a));
        return concat(sx, dx);
    }
}

//da finire
// TipoLista percorso_lungo(TipoAlbero a)
// {

// }

TipoInfoAlbero somma_foglie2(TipoAlbero a)
{
    if (estVuoto(a))
        return 0;
    else
        return radice(a) + somma_foglie2(sinistro(a)) + somma_foglie2(destro(a));
}

void somma_sottoalbero(TipoAlbero a)
{
    if (!estVuoto(a))
    {
        somma_sottoalbero(sinistro(a));
        somma_sottoalbero(destro(a));
        if (!foglia(a))
            a->info = somma_foglie2(sinistro(a)) + somma_foglie2(destro(a));
    }    
}

void scambia_foglie(TipoAlbero a)
{
    if (!estVuoto(a))
    {
        scambia_foglie(sinistro(a));
        scambia_foglie(destro(a));
        if (!foglia(a))
        {
            TipoInfoAlbero temp = a->sinistro->info;
            a->sinistro->info = a->destro->info;
            a->destro->info = temp;
        }
    }
}

void max_figli_livello(TipoAlbero a, int livello)
{
    if (estVuoto(a))
        return;
    else if (livello == 0)
    {
        if (sinistro(a) != NULL && destro(a) != NULL)
            a->info = massimo(radice(sinistro(a)), radice(destro(a)));
        else if (sinistro(a) != NULL && destro(a) == NULL)
            a->info = radice(sinistro(a));
        else if (sinistro(a) == NULL && destro(a) != NULL)
            a->info = radice(destro(a));
    }
    else
    {
            max_figli_livello(sinistro(a), livello-1);
            max_figli_livello(destro(a), livello-1);
    }
}

void scambia_foglie_livello(TipoAlbero a, int livello)
{
    if (estVuoto(a))
        return;
    else if (livello == 1)
    {
        if (sinistro(a) != NULL && destro(a) != NULL)
        {
            TipoInfoAlbero temp = a->sinistro->info;
            a->sinistro->info = a->destro->info;
            a->destro->info = temp;
        }
    }
    else
    {
        scambia_foglie_livello(sinistro(a), livello-1);
        scambia_foglie_livello(destro(a), livello-1);
    }
}

int trova_indice(int len)
{
    int i = 0;
    while (i <= (int) len/2)
        i++;
    return i;
}

int elem_in_pos(TipoLista l, int pos)
{
    if (pos == 0)
        return car(l);
    else
        return elem_in_pos(cdr(l), pos-1);
}

//da finire, non funziona
void set_albbinric(TipoAlbero a, TipoLista l)
{
    if (estVuoto(a))
        return;
    else
    {
        set_albbinric(sinistro(a), l);
        a->info = car(l);

        set_albbinric(destro(a), l);
    }
    
}

int main()
{
    // TipoAlbero a = creaAlbBin(4, albBinVuoto(), albBinVuoto());
    // TipoAlbero b = creaAlbBin(3, albBinVuoto(), albBinVuoto());
    // TipoAlbero c = creaAlbBin(9, albBinVuoto(), albBinVuoto());
    // TipoAlbero d = creaAlbBin(2, albBinVuoto(), albBinVuoto());
    // TipoAlbero e = creaAlbBin(5, a, b);
    // TipoAlbero f = creaAlbBin(7, c, d);
    // TipoAlbero g = creaAlbBin(1, e, f);

    TipoAlbero a=creaAlbBin(1,NULL,NULL);
	
	//Livello 1
	a->sinistro=creaAlbBin(5,NULL,NULL);
	a->destro=creaAlbBin(7,NULL,NULL);
	
	//Livello 2
	a->sinistro->sinistro=creaAlbBin(4,NULL,NULL);
	a->sinistro->destro=creaAlbBin(3,NULL,NULL);
	a->destro->sinistro=creaAlbBin(9,NULL,NULL);
	a->destro->destro=creaAlbBin(2,NULL,NULL);

    // a->sinistro->sinistro->sinistro = creaAlbBin(7,NULL,NULL);

    // a->sinistro->sinistro->sinistro->destro = creaAlbBin(2,NULL,NULL);

    // printf("%d\n", profondita(f));
    // printa(a);
    // printf("\n");
    
    // printf("%d\n", trova_massimo(a));
    // printf("%d\n", somma_foglie(a));

    // printf("%d", cerca_livello(a, 2));

    // printf("%d", conta_dispari(a));

    // printf("%d", somma_singoli(a));

    // TipoLista l = albero_lista(a);
    // printl(l);

    // printa(a);
    // printf("\n");
    // somma_sottoalbero(a);
    // printa(a);

    // printa(a);
    // printf("\n");
    // scambia_foglie(a);
    // printa(a);

    // printa(a);
    // printf("\n");
    // max_figli_livello(a, 1);
    // printa(a);

    // printa(a);
    // printf("\n");
    // scambia_foglie_livello(a, 2);
    // printa(a);

    TipoLista l = cons(5, cons(7, cons(9, cons(12, cons(15, cons(19, cons(21, listaVuota())))))));
    set_albbinric(a, l);
    printa(a);

    return 0;
}