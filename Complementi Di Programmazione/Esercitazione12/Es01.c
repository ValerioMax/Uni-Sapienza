#include <stdio.h>
#include <stdlib.h>
#include "albero_binario.h"
#include "lista.h"
#include "coda.h"

void printa(TipoAlbero a)
{
    if (!estVuoto(a))
    {
        printa(sinistro(a));
        printa(destro(a));
        printf("%d, ", radice(a));
    }
}

bool foglia(TipoAlbero a)
{
    return (a->sinistro == NULL && a->destro == NULL);
}

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

TipoInfoAlbero trova_minimo(TipoAlbero a)
{  
    if(!estVuoto(a))
    {
        int min = radice(a);
    
        int min_sinistro = trova_minimo(sinistro(a));

        int min_destro = trova_minimo(destro(a));
        
        if (min_sinistro < min && !foglia(a))
            min = min_sinistro;

        if (min_destro < min && !foglia(a))
            min = min_destro;
        
        return min;
    }    
}

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

int conta_nodi(TipoAlbero a)
{
    if (estVuoto(a))
        return 0;
    else
    {
        int sx = conta_nodi(sinistro(a));
        int dx = conta_nodi(destro(a));
        return 1 + sx + dx;
    }
}

void visitaAmpiezza(TipoAlbero a)
{
    if (estVuoto(a))
        return;
    Coda* c = codaVuota();
    inCoda(c, a);
    while (!estCodaVuota(c))
    {
        TipoAlbero n = primoCoda(c);
        printf("%d,, ", radice(n));
        outCoda(c);
        if (!estVuoto(sinistro(n)))
            inCoda(c, sinistro(n));
        if (!estVuoto(destro(n)))
            inCoda(c, destro(n));
    }
}

//Es1 ver side effect
void rimuovi_minimo_aux(TipoAlbero* a, TipoInfoAlbero min)
{
    if (!estVuoto(*a))
    {
        rimuovi_minimo_aux(&(*a)->sinistro, min);
        rimuovi_minimo_aux(&(*a)->destro, min);
        if (!foglia(*a) && (*a)->sinistro->info == min)
            (*a)->sinistro = NULL;
        if (!foglia(*a) && (*a)->destro->info == min)
            (*a)->destro = NULL;
    }
}

void rimuovi_minimo(TipoAlbero* a)
{
    return rimuovi_minimo_aux(a, trova_minimo(*a));
}

//Es1 ver funzionale
TipoAlbero rimuovi_minimo(TipoAlbero a)
{

}

//Es2 ver side effect
void duplica_foglie(TipoAlbero *a)
{
    if (!estVuoto(*a))
    {
        duplica_foglie(&(*a)->sinistro);
        duplica_foglie(&(*a)->destro);
        if (foglia(*a))
        {
            TipoAlbero x = creaAlbBin((*a)->info, NULL, NULL);

            (*a)->sinistro = x;
        }
    }
}

//Es2 ver funzionale
TipoAlbero duplica_foglie(TipoAlbero a)
{

}

//Es3 ver side effect
void rimuovi_foglie_profonde(TipoAlbero *a, int n)
{
    if (!estVuoto(*a))
    {
        rimuovi_foglie_profonde(&(*a)->sinistro, n);
        rimuovi_foglie_profonde(&(*a)->destro, n);
        if (foglia((*a)->sinistro) && cerca_livello(*a, (*a)->sinistro->info) >= n)
            (*a)->sinistro = NULL;
        if (foglia((*a)->destro) && cerca_livello(*a, (*a)->destro->info) >= n)
            (*a)->destro = NULL;
    }
    
}

//Es3 ver funzionale
TipoAlbero rimuovi_foglie_profonde(TipoAlbero a, int n)
{

}

//Es4 side effect
void scambia_sottoalberi_simili(TipoAlbero *a)
{
    if (!estVuoto(*a))
    {
        scambia_sottoalberi_simili(&(*a)->sinistro);
        scambia_sottoalberi_simili(&(*a)->destro);
        if ((*a)->sinistro != NULL && (*a)->destro != NULL && conta_nodi((*a)->sinistro) == conta_nodi((*a)->destro))
        {
            TipoAlbero temp = (*a)->sinistro;
            (*a)->sinistro = (*a)->destro;
            (*a)->destro = temp;
        }
    }
}

//Es4 funzionale
TipoAlbero scambia_sottoalberi_simili(TipoAlbero a)
{

}

//Es5 side effect
void limita_livello(TipoAlbero *a, int livello)
{
    if (!estVuoto(*a))
    {
        if (livello == 0)
        {
            if ((*a)->sinistro != NULL)
                (*a)->sinistro = NULL;
            if ((*a)->destro != NULL)
                (*a)->destro = NULL;
        }
        limita_livello(&(*a)->sinistro, livello-1);
        limita_livello(&(*a)->destro, livello-1);
    }
}

//Es5 funzionale
TipoAlbero limita_livello(TipoAlbero a, int livello)
{

}

//Es6 side effect
void rimuovi_max_livello(TipoAlbero *a, int livello)
{

}

//Es6 funzionale
TipoAlbero rimuovi_max_livello(TipoAlbero a, int livello)
{

}

int main()
{
    TipoAlbero a = creaAlbBin(10,NULL,NULL);
	
	//Livello 1
	a->sinistro = creaAlbBin(5,NULL,NULL);
	a->destro = creaAlbBin(7,NULL,NULL);
	
	//Livello 2
	a->sinistro->sinistro = creaAlbBin(4,NULL,NULL);
	a->sinistro->destro = creaAlbBin(3,NULL,NULL);
	a->destro->sinistro = creaAlbBin(9,NULL,NULL);
	a->destro->destro = creaAlbBin(2,NULL,NULL);

    //Livello 3
    a->sinistro->sinistro->sinistro = creaAlbBin(13, NULL, NULL);
    a->sinistro->sinistro->destro = creaAlbBin(11, NULL, NULL);

    TipoAlbero* b;
    b = &a;

    // printf("%d\n", trova_minimo(a));
    // printa(a);
    // printf("\n");
    // rimuovi_minimo(b);
    // printa(a);

    // printa(a);
    // printf("\n");
    // duplica_foglie(b);
    // printa(a);

    // printa(a);
    // printf("\n");
    // rimuovi_foglie_profonde(b, 2);
    // printa(a);

    // printa(a);
    // printf("\n%d", conta_nodi(a));

    // printa(a);
    // printf("\n");
    // scambia_sottoalberi_simili(b);
    // printa(a);

    // printa(a);
    // printf("\n");
    // limita_livello(b, 2);
    // printa(a);

    visitaAmpiezza(a);
}