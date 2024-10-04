#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<string.h>
#include<time.h>
#include "pila.h"
#include "coda.h"

void allocaPila(Pila *p);
void allocaCoda(Coda *c);
void print(Pila *p);
void printC(Coda *c);
void stampa_sequenza_inversa(void);
void rimuovi_alcuni(Pila *p, const int* rimuovere, int n);
bool check_palindrome(const char* s);
bool check_palindrome_r(const char* s);
bool check_palindrome_r_aux(const char* s, int i);
int* rimuoviMinori(int* arr, int len);
void stampa_sequenza(void);
int elemento_iesimo(Coda *c, int pos);
void avoid_stampa(Coda *c, int elem);
Coda* coda_circolare(Coda *c, int n);
Coda* elementi_pari(Coda *c);
Coda* elementi_pari_aux(Coda *c, int i);

int main(void){
	//Pila standard
	srand(time(NULL));
	/*Pila *p=pilaVuota();
	allocaPila(p);*/

	//Esercizio 1
	//stampa_sequenza_inversa();
	
	//Esercizio 2
	/*int n=3;
	int *rimuovere=(int*)malloc(n*sizeof(int));
	printf("\nPila --> [ ");
	print(p);
	printf("\nRimuovere --> [ ");
	for(int i=0;i<n;i++){
		rimuovere[i]=rand()%10+1;
		printf("%d ",rimuovere[i]);
	}
	printf("]");
	rimuovi_alcuni(p,rimuovere,n);
	printf("\nRisultato --> [ ");
	print(p);
	printf("\n\n");*/
	
	//Esercizio 3-4
	/*char* s="onorarono";
	bool t=check_palindrome_r(s);
	if(t==true)
		printf("\nLa parola è palindroma\n\n");
	else
		printf("\nLa parola NON è palindroma\n\n");*/
		
	//Esercizio 5
	/*int n=7;
	int arr[7]={1,3,4,2,4,2,3};
	int* ris=rimuoviMinori(arr,n);*/
	
	//Esercizio 6
	//stampa_sequenza();
	
	//Esercizio 7
	/*Coda *c=codaVuota();
	allocaCoda(c);
	printf("\nCoda: [ ");
	print(c);
	int x=elemento_iesimo(c,4);
	printf("\n\nL'elemento è: %d\n",x);
	printf("\nRisultato: [ ");
	print(c);
	printf("\n\n");*/
	
	//Esercizio 8
	Coda *c=codaVuota();
	allocaCoda(c);
	printf("\nCoda: [ ");
	print(c);
	avoid_stampa(c,5);
	printf("\nCoda originale: [ ");
	print(c);
	printf("\n\n");
		
		
		
	//Esercizio 9
	/*Coda *c=codaVuota();
	allocaCoda(c);
	printf("\nCoda: [ ");
	print(c);
	Coda *ris=coda_circolare(c,12);
	printf("\nRisultato: [ ");
	print(ris);
	printf("\n\n");*/
	
	//Esercizio 10
	/*Coda *c=codaVuota();
	allocaCoda(c);
	printf("\nCoda: [ ");
	print(c);
	Coda *ris=elementi_pari(c);
	printf("\nRisultato: [ ");
	print(ris);
	printf("\n\n");*/
}

void allocaPila(Pila *p){
	int n,x;
	printf("\nInserire quantità elementi: ");
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		x=rand()%10+1;
		inPila(p,x);
	}
}

void allocaCoda(Coda *c){
	int n,x;
	printf("\nInserire quantità elementi: ");
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		x=rand()%10+1;
		inCoda(c,x);
	}
}

void print(Pila *p){
	if(!estPilaVuota(p)){
		printf("%d ",primoPila(p));
		print(&((*p)->next));
	}
	else
		printf("]");
}

void printC(Coda *c){
	if(!estCodaVuota(c)){
		printf("%d ",primoCoda(c));
		printC(&((*c)->next));
	}
	else
		printf("]");
}

void stampa_sequenza_inversa(void){
	int x;
	Pila *p=pilaVuota();
	printf("\nInserire elemento (negativo per terminare): ");
	scanf("%d",&x);
	while(x>=0){
		inPila(p,x);
		printf("Inserire elemento (negativo per terminare): ");
		scanf("%d",&x);
	}
	printf("\nLa sequenza inversa è: \n");
	while(!estPilaVuota(p))
		printf("%d, ",outPila(p));
	printf("\n\n");
}

void rimuovi_alcuni(Pila *p, const int* rimuovere, int n){
	int i=0;
	while(i<n){
		if(primoPila(p)==rimuovere[i]){
			i=0;
			outPila(p);
		}
		else
			i++;
	}
}

bool check_palindrome(const char* s){
	int n=strlen(s);
	Pila *p=pilaVuota();
	for(int i=0;i<n;i++)
		inPila(p,s[i]);
	bool pal=true;
	int j=0;
	while(!estPilaVuota(p)){
		if(outPila(p)!=s[j])
			pal=false;
		j++;
	}
	return pal;
}

bool check_palindrome_r(const char* s){
	return check_palindrome_r_aux(s,0);
}

bool check_palindrome_r_aux(const char* s, int i){
	if(i==strlen(s)-1 || i==strlen(s)-1-i)
		return true;
	else{
		return *s==s[strlen(s)-1-i] && check_palindrome_r_aux(s+1,i+1); 
	}
}

int* rimuoviMinori(int* arr, int len){
	Pila *p=pilaVuota();
	T x, j=0;
	for(int i=0;i<len;i++){
		while(!estPilaVuota(p) && arr[i]<primoPila(p)){
			x=outPila(p);
			j--;
		}
		inPila(p,arr[i]);
		j++;
	}
	int* ris=(int*)malloc(j*sizeof(int));
	printf("\n {");
	for(int i=0;i<j;i++){
		ris[i]=outPila(p);
		printf(" %d",ris[i]);
	}
	printf(" }\n\n");
	return ris;
}

void stampa_sequenza(void){
	int x;
	printf("\nInserire un numero (negativo per terminare): ");
	scanf("%d",&x);
	Coda *c=codaVuota();
	while(x>0){
		inCoda(c,x);
		printf("\nInserire un numero (negativo per terminare): ");
		scanf("%d",&x);
	}
	printf("\nCoda: [");
	while(!estCodaVuota(c))
		printf(" %d",outCoda(c));
	printf(" ]\n\n");
}

int elemento_iesimo(Coda *c, int pos){
	if(estCodaVuota(c) && pos>0)
		return -1;
	else if(pos==0)
		return outCoda(c);
	else{
		outCoda(c);
		return elemento_iesimo(c, pos-1);
	}
			
}

void avoid_stampa(Coda *c, int elem){
	Coda *c2=codaVuota();
	printf("\nAvoid stampa: [ ");
	while(!estCodaVuota(c)){
		if(primoCoda(c)!=elem)
			printf("%d ",primoCoda(c));	;
		inCoda(c2,outCoda(c));
	}
	printf("]");
	while(!estCodaVuota(c2))
		inCoda(c,outCoda(c2));
}

Coda* coda_circolare(Coda *c, int n){
	int i=0;
	Coda* c1=codaVuota();
	while(i<n){
		inCoda(c1,primoCoda(c));
		inCoda(c,outCoda(c));
		i++;
	}
	return c1;
}

Coda* elementi_pari(Coda *c){
	return elementi_pari_aux(c,0);
}

Coda* elementi_pari_aux(Coda *c, int i){
	Coda *c1=codaVuota();
	while(!estCodaVuota(c)){
		T x=outCoda(c);
		if(i%2==0)
			inCoda(c1,x);
		i++;
	}
	return c1;
}
