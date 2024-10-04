#include <stdio.h>
#include <stdlib.h>
#include "scl.h"
#include "coda.h"
#include "pila.h"

//Ausiliarie Code:

void allocaCoda(Coda *c){
	int n,x;
	printf("\nInserire quantità elementi: ");
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		x=rand()%10+1;
		inCoda(c,x);
	}
}

void printc(Coda *c){
	if(!estCodaVuota(c)){
		printf("%d ",primoCoda(c));
		printc(&((*c)->next));
	}
	else
		printf("]");
}

//10.6
void stampa_sequenza(Coda* c)
{
    int x;
    printf("Inserisci numero: ");
    scanf("%d", &x);
    while (x > 0)
    {
        inCoda(c, x);
        printf("Inserisci numero: ");
        scanf("%d", &x);
    }
    printc(c);
    printf("\n");
}

//10.7
int elemento_iesimo(Coda* c, int pos)
{
    if (estCodaVuota(c) && pos>0)
    {
        printf("pos > length(coda)");
        return -1;
    }
    else if (pos == 0)
        return outCoda(c);
    else
    {
        //perché se metto solo outCoda invece che T x = outCoda(c) va lo stesso?
        T x = outCoda(c);
        return elemento_iesimo(c, pos-1);
    }
}

//10.8
void avoid_stampa(Coda *c, int elem)
{
    Coda* c2 = codaVuota();
    while (!estCodaVuota(c))
    {
        T e = outCoda(c);
        inCoda(c2, e);
        if (e != elem)
            printf("%d, ", e);
    }

    while (!estCodaVuota(c2))
        inCoda(c, outCoda(c2));
}

// 10.9
Coda* coda_circolare(Coda *c, int n)
{
    Coda* c2 = codaVuota();
    while (n != 0)
    {
        T e = outCoda(c);
        inCoda(c2, e);
        inCoda(c, e);
        n--;
    }
    return c2;
}

//10.10
Coda* elementi_pari(Coda *c)
{
    Coda* c2 = codaVuota();
    int i = 0;
    while (!estCodaVuota(c))
    {
        T e = outCoda(c);
        if (i % 2 == 0)
            inCoda(c2, e);
        i++;
    }
    return c2;
}

//Ausiliarie Pile:

void printp(Pila* p)
{
    if (!estPilaVuota(p))
    {
        printf("%d, ", primoPila(p));
        printp(&(*p)->next);
    }
}

int strlen(const char v[])
{
    int i = 0;
    int len = 0;
    while (v[i] != '\0')
    {
        len++;
        i++;
    }
    return len;
}

void printv(int* v, int len)
{
    for (int i = 0; i < len; i++)
    {
        printf("%d ,", v[i]);
    }
}

//10.1
void stampa_sequenza_inversa(void)
{
    Pila* p = pilaVuota();
    int x;
    printf("Inserisci numero: ");
    scanf("%d", &x);
    while (x >= 0)
    {
        inPila(p, x);
        printf("Inserisci numero: ");
        scanf("%d", &x);
    }
    printp(p);
}

//10.2
void rimuovi_alcuni(Pila *p, const int *rimuovere, int n)
{
    for (int i = 0; i < n; i++)
    {
        if (estPilaVuota(p))
            exit(1);
        if (primoPila(p) == rimuovere[i])
        {
            outPila(p);
            rimuovi_alcuni(p, rimuovere, n);
        }
    }
}

//10.3
//non va fatto così ma con le pile
bool check_palindrome1(const char* s)
{
    int len = strlen(s);
    int j = 0;
    for (int i = 0; i < (strlen(s)/2); i++)
    {
        if (s[j] != s[len-1])
            return false;
        j++;
        len--;
    }
    return true;
}

//versione con le pile
bool check_palindrome(const char* s)
{
    Pila* p =  pilaVuota();
    for (int i = 0; i < strlen(s); i++)
        inPila(p, s[i]);
    
    for (int j = 0; j < strlen(s); j++)
    {
        T e = outPila(p);
        if (e != s[j])
            return false;
    }
    return true;
}

//10.4


//10.5
//la pila finale è corretta, manca solo di trasformarla in vettore da restituire
int* rimuoviMinori(int* arr, int len)
{
    Pila* p = pilaVuota();
    int x = 0;
    for (int i = 0; i < len; i++)
    {
        if (estPilaVuota(p))
        {
            inPila(p, arr[i]);
            x++;
        }
           
        else
        {
            while (arr[i] < primoPila(p))
            {
                outPila(p);
                x--;
            }
            inPila(p, arr[i]);
            x++;
        }
    }

    int* v;
    for (int i = 0; i < x; i++)
    {
        T e = outPila(p);
        v[i] = e;
    }

    return v;
}

//questa funziona, manca solo di trasforamare la pila in un vettore
Pila* rimuoviMinori_aux(int* arr, int len)
{
    Pila* p = pilaVuota();
    int x = 0;
    for (int i = 0; i < len; i++)
    {
        if (estPilaVuota(p))
        {
            inPila(p, arr[i]);
            x++;
        }
           
        else
        {
            while (arr[i] < primoPila(p))
            {
                outPila(p);
                x--;
            }
            inPila(p, arr[i]);
            x++;
        }
    }
    return p;
}

int main()
{
    Coda* c = codaVuota();
    inCoda(c, 12);
    inCoda(c, 3);
    inCoda(c, 9);
    inCoda(c, 7);
    
    //stampa_sequenza(c);
    // printf("\n");
    
    // printc(c);
    // printf("%d\n", elemento_iesimo(c, 2));
    // printc(c);

    // printc(c);
    // printf("\n");
    // avoid_stampa(c, 3);
    // printf("\n");
    // printc(c);

    // Coda* c2 = coda_circolare(c, 34);
    // printc(c2);

    // Coda* c2 = elementi_pari(c);
    // printc(c2);


    Pila* p = pilaVuota();
    inPila(p, 8);
    inPila(p, 19);
    inPila(p, 79);
    inPila(p, 2);

    //stampa_sequenza_inversa();

    // int v[] = {2, 1, 19};
    // printp(p);
    // printf("\n");
    // rimuovi_alcuni(p, v, 3);
    // printp(p);

    // const char s[] = "abba";
    // if (check_palindrome1(s))
    //     printf("OK");
    // else
    //     printf("NO");

    int arr[] = {1, 3, 4, 2, 4, 2, 3};
    // int* v = rimuoviMinori(arr, 7);
    // printv(v, 4);

    Pila* p1 = rimuoviMinori_aux(arr, 7);
    printp(p1);

    return 0;
}