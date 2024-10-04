#include <stdio.h>
#include <stdlib.h>
#include "lista.h"
#include "albero_binario.h"

TipoAlbero copy(TipoAlbero a)
{
    if (estVuoto(a))
        return albBinVuoto();
    else
        return creaAlbBin(radice(a), copy(sinistro(a)), copy(destro(a)));
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
    if (a->destro == NULL && a->sinistro == NULL)
        return true;
    else
        return false;
}

void printa(TipoAlbero a)
{
    if (!estVuoto(a))
    {
        printa(sinistro(a));
        printa(destro(a));
        printf("%d, ", radice(a));
    }
}

int massimo(TipoAlbero a)
{
    if (estVuoto(a))
        return -1;
    else
    {
        int max = radice(a);
        int sx = massimo(sinistro(a));
        if (sx > max)
            max = sx;
        int dx = massimo(destro(a));
        if (dx > max)
            max = dx;
        return max;
    }
}

int minimo_aux(TipoAlbero a, int max)
{
    if (estVuoto(a))
        return max;
    else
    {
        int min = radice(a);
        int sx = minimo_aux(sinistro(a), max);
        if (sx < min)
            min = sx;
        int dx = minimo_aux(destro(a), max);
        if (dx < min)
            min = dx;
        return min;
    }
}

//metto un valore molto grande nel return di base: se voglio star sicuro metto il valore massimo dell'albero.
int minimo(TipoAlbero a)
{
    return minimo_aux(a, massimo(a));
    // if (estVuoto(a))
    //     return 9999;
    // else
    // {
    //     int min = radice(a);
    //     int sx = minimo(sinistro(a));
    //     if (sx < min)
    //         min = sx;
    //     int dx = minimo(destro(a));
    //     if (dx < min)
    //         min = dx;
    //     return min;
    // }
}

void rimuovi_minimo_aux(TipoAlbero* a, int min)
{
    if (!estVuoto(*a))
    {
        rimuovi_minimo_aux(&(*a)->sinistro, min);
        rimuovi_minimo_aux(&(*a)->destro, min);
        if ((*a)->sinistro != NULL && (*a)->sinistro->info == min)
            (*a)->sinistro = NULL;
        if ((*a)->destro != NULL && (*a)->destro->info == min)
            (*a)->destro = NULL;
    }
}

void rimuovi_minimo(TipoAlbero* a)
{
    return rimuovi_minimo_aux(a, minimo(*a));
}

void duplica_foglie(TipoAlbero* a)
{
    if (!estVuoto(*a))
    {
        duplica_foglie(&(*a)->sinistro);
        duplica_foglie(&(*a)->destro);
        if (foglia(*a))
        {
            TipoAlbero b = creaAlbBin((*a)->info, NULL, NULL);
            (*a)->sinistro = b;
        }
    }
}

void rimuovi_foglie_profonde(TipoAlbero *a, int n)
{
    if (!estVuoto(*a))
    {
        if (n <= 1)
        {
            if ((*a)->sinistro != NULL && foglia((*a)->sinistro))
                (*a)->sinistro = NULL;
            if ((*a)->destro != NULL && foglia((*a)->destro))
                (*a)->destro = NULL;
        }
        rimuovi_foglie_profonde(&(*a)->sinistro, n-1);
        rimuovi_foglie_profonde(&(*a)->destro, n-1);
    }
}

int conta_nodi(TipoAlbero a)
{
    if (estVuoto(a))
        return 0;
    
    else
    {
        int sx = conta_nodi(sinistro(a));
        int dx = conta_nodi(destro(a));
        // if (sinistro(a) != NULL && destro(a) != NULL)
        //     return 2;
        // else if (sinistro(a) != NULL && destro(a) == NULL)
        //     return 1;
        // else if (sinistro(a) == NULL && destro(a) != NULL)
        //     return 1;
        return  1 + sx + dx;
    }
}

void scambia_sottoalberi_simili(TipoAlbero *a)
{
    if (!estVuoto(*a))
    {
        if (conta_nodi((*a)->sinistro) == conta_nodi((*a)->destro))
        {
            TipoAlbero b = (*a)->sinistro;
            (*a)->sinistro = (*a)->destro;
            (*a)->destro = b;
        }
        scambia_sottoalberi_simili(&(*a)->sinistro);
        scambia_sottoalberi_simili(&(*a)->destro);
    }
}

void limita_livello(TipoAlbero *a, int livello)
{
    if (!estVuoto(*a))
    {
        if (livello < 1)
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

void rimuovi_max_livello(TipoAlbero *a, int livello)
{

}

int somma_albero(TipoAlbero a)
{
    if (estVuoto(a))
        return 0;
    else
        return radice(a) + somma_albero(sinistro(a)) + somma_albero(destro(a));
}

void comprimi_sottoalberi(TipoAlbero *a)
{
    if (!estVuoto(*a))
    {
        if ((*a)->sinistro != NULL && (*a)->destro == NULL)
        {
            (*a)->info = somma_albero((*a)->sinistro);
            (*a)->sinistro = NULL;
        }
        else if ((*a)->sinistro == NULL && (*a)->destro != NULL)
        {
            (*a)->info = somma_albero((*a)->destro);
            (*a)->destro = NULL;
        }
        comprimi_sottoalberi(&(*a)->sinistro);
        comprimi_sottoalberi(&(*a)->destro);

    }
}

void sx_pari_dx_dispari(TipoAlbero* a)
{
    if (!estVuoto(*a))
    {
        if ((*a)->info % 2 != 0)
        {
            if ((*a)->destro != NULL)
                (*a)->destro = NULL;
            if ((*a)->sinistro == NULL)
            {
                TipoAlbero b = creaAlbBin((*a)->info, NULL, NULL);
                (*a)->sinistro = b;
            }
        }
        else
        {
            if ((*a)->sinistro != NULL)
                (*a)->sinistro = NULL;
            if ((*a)->destro == NULL)
            {
                TipoAlbero b = creaAlbBin((*a)->info, NULL, NULL);
                if ((*a)->sinistro != NULL)
                    (*a)->sinistro->sinistro = b;
                else
                    (*a)->sinistro = b;
            }
        }
        sx_pari_dx_dispari(&(*a)->sinistro);
        sx_pari_dx_dispari(&(*a)->destro);
    }
}

int profondita(TipoAlbero a)
{
    if (estVuoto(a))
        return -1;
    else
    {
        int sx = 1 + profondita(sinistro(a));
        int dx = 1 +profondita(destro(a));
        return max(sx, dx);
    }
}

void percorso_lungo(TipoAlbero* a)
{
    if (!estVuoto(*a))
    {
        if (profondita((*a)->sinistro) > profondita((*a)->destro))
            (*a)->destro = NULL;
        else
            (*a)->sinistro = NULL;
        percorso_lungo(&(*a)->sinistro);
        percorso_lungo(&(*a)->destro);
    }
}

TipoAlbero albero_percorso_lungo(TipoAlbero *a)
{
    TipoAlbero b = copy(*a);
    percorso_lungo(&b);
    return b;
}

int conta_pari(TipoAlbero a)
{
    if (estVuoto(a))
        return 0;
    else
    {
        int sx = conta_pari(sinistro(a));
        int dx = conta_pari(destro(a));
        if (radice(a) % 2 == 0)
            return 1 + sx + dx;
        else
            return 0 + sx + dx;
        
    }
}

// int* g(){
// 	int a = 10;
// 	return &a;
// }

// void stampaPari(TipoAlbero a){
// 	if (a == NULL){
// 		return;
// 	}
// 	if (a -> info % 2 == 0){
// 		printf("%d ", a -> info);
// 		return;
// 	}
// 	if (a -> sinistro != NULL){
// 		stampaPari((a.sinistro));
// 	}
// 	if (a -> destro != NULL){
// 		stampaPari((a.destro));
// 	}
// }

int main()
{
    // //livello 0
    // TipoAlbero a = creaAlbBin(2, NULL, NULL);
    // //livello 1
    // a->sinistro = creaAlbBin(5, NULL, NULL); 
    // a->destro = creaAlbBin(7, NULL, NULL);
    // //livello 2
    // a->sinistro->sinistro = creaAlbBin(1, NULL, NULL);
    // a->sinistro->destro = creaAlbBin(3, NULL, NULL);
    // a->destro->sinistro = creaAlbBin(9, NULL, NULL);
    // a->destro->destro = creaAlbBin(6, NULL, NULL);
    // a->destro->destro->destro = creaAlbBin(20, NULL, NULL);

    // printa(a);
    printf("\n");
    //printf("%d\n", minimo(a));
    // rimuovi_minimo(&a);
    // printa(a);

    // duplica_foglie(&a);
    // printa(a);

    // rimuovi_foglie_profonde(&a, 1);
    // printa(a);

    //printf("%d\n", conta_nodi(a));

    // scambia_sottoalberi_simili(&a);
    // printa(a);

    // limita_livello(&a, 1);
    // printa(a);

    //printf("%d\n", somma_albero(a));

    // comprimi_sottoalberi(&a);
    // printa(a);

    // percorso_lungo(&a);
    // printa(a);

    // TipoAlbero b = copy(a);
    // printa(b);

    // TipoAlbero b = albero_percorso_lungo(&a);
    // printa(b);

    //printf("%d\n", conta_pari(a));

	// int* x = g();
	// printf("%d\n",*x);
	// free(x);

    long int a = 12345678;
    char* pa = (char*) &a;
    printf("%d\n", sizeof(long int));
    printf("%d\n", sizeof(a));
    printf("%d\n", pa[4]);
    for (int i = 1; i <= sizeof(a); i++){
        printf("%d\n", pa[i]);
    }
		
    int x = 1;
    if (x == 1)
    {
            x = 9;
        x++;
    }
    
    printf("%d\n", x);

    return 0;
}