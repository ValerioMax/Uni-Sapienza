#pragma once

typedef int T;
struct NodoSCL
{
    T info;
    struct NodoSCL *next;
};
typedef struct NodoSCL TipoNodo;
typedef TipoNodo *TipoLista;

// Operazioni
TipoLista listaVuota();             // crea lista vuota
int estVuota(TipoLista l);          // controllo se vuota
TipoLista cons(T e, TipoLista l);   // crea nuova lista uguale ma aggiungendo qualcosa per primo elem
T car(TipoLista l);                 // leggo valore del primo
TipoLista cdr(TipoLista l);         // ritorno coda della lista (lista ottenuta eliminando il primo elemento)

void printlist(TipoLista l);
