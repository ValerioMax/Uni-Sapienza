#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include "lista.h"
#include "albero_binario.h"

TipoInfoAlbero max(TipoInfoAlbero dato1, TipoInfoAlbero dato2);
bool foglia(TipoAlbero a);
bool singolo(TipoAlbero a);
void printAlbero(TipoAlbero a, int space);
TipoLista append(TipoLista l,T e);
TipoLista concat(TipoLista l1,TipoLista l2);
int length(TipoLista l);
TipoInfoAlbero trova_massimo(TipoAlbero a);
TipoInfoAlbero somma_foglie(TipoAlbero a);
int cerca_livello(TipoAlbero a, TipoInfoAlbero v);
int cerca_livello_aux(TipoAlbero a, TipoInfoAlbero v, int i);
int conta_dispari(TipoAlbero a);
int somma_singoli(TipoAlbero a);
TipoLista albero_lista(TipoAlbero a);
TipoLista percorso_lungo(TipoAlbero a);
void percorso_lungo_aux(TipoAlbero a, TipoLista l, TipoLista* max);
void somma_sottoalbero(TipoAlbero a);
void scambia_foglie(TipoAlbero a);
void max_figli_livello(TipoAlbero a, int livello);
void scambia_foglie_livello(TipoAlbero a, int livello);
void set_albbinric(TipoAlbero a, TipoLista l);
void set_albbinric_aux(TipoAlbero a, TipoLista l, int n);

int main(void){

	//Albero standard
	TipoAlbero a=creaAlbBin(17,NULL,NULL);
	
	//Livello 1
	a->sinistro=creaAlbBin(10,NULL,NULL);
	a->destro=creaAlbBin(21,NULL,NULL);
	
	//Livello 2
	a->sinistro->sinistro=creaAlbBin(6,NULL,NULL);
	a->sinistro->destro=creaAlbBin(13,NULL,NULL);
	a->destro->sinistro=creaAlbBin(20,NULL,NULL);
	a->destro->destro=creaAlbBin(33,NULL,NULL);
	
	//Livello 3
	a->sinistro->sinistro->sinistro=creaAlbBin(2,NULL,NULL);
	a->sinistro->sinistro->destro=creaAlbBin(7,NULL,NULL);
	
	//Esercizio 1
	/*int x=trova_massimo(a);
	printf("\nIl massimo valore dell'albero è: %d\n\n",x);*/
	
	//Esercizio 2
	/*int y=somma_foglie(a);
	printf("\nLa somma delle foglie dell'albero è: %d\n\n",y);*/

	//Esercizio 3
	/*int z=cerca_livello(a,13);
	printf("\nIl valore si trova al livello %d dell'albero\n\n",z);*/
	
	//Esercizio 4
	/*int w=conta_dispari(a);
	printf("\nI nodi dispari dell'albero sono: %d\n\n",w);*/
	
	//Esercizio 5
	/*int k=somma_singoli(a);
	printf("\nLa somma dei nodi singoli è: %d\n\n",k);*/
	
	//Esercizio 6
	/*printf("\n\n");
	printAlbero(a,0);
	TipoLista h=albero_lista(a);
	printf("\n\n");
	printlist(h);*/
	
	//Esercizio 7
	printf("\n\nAlbero input:\n\n");
	printAlbero(a,0);
	TipoLista b=percorso_lungo(a);
	printf("\nLista output:\n\n");
	printlist(b);
	printf("\n\n");
	
	//Esercizio 8
	/*printf("\n\nAlbero prima:\n\n");
	printAlbero(a,0);
	somma_sottoalbero(a);
	printf("\n\nAlbero dopo:\n\n");
	printAlbero(a,0);
	printf("\n\n");*/
	
	//Esercizio 9
	/*printf("\n\nAlbero prima:\n\n");
	printAlbero(a,0);
	scambia_foglie(a);
	printf("\n\nAlbero dopo:\n\n");
	printAlbero(a,0);
	printf("\n\n");*/
	
	//Esercizio 10
	/*printf("\n\nAlbero prima:\n\n");
	printAlbero(a,0);
	max_figli_livello(a,2);
	printf("\n\nAlbero dopo:\n\n");
	printAlbero(a,0);
	printf("\n\n");*/
	
	//Esercizio 11
	/*printf("\n");
	TipoLista l=listaVuota();
	l=cons(19,l);
	l=cons(17,l);
	l=cons(16,l);
	l=cons(14,l);
	l=cons(13,l);
	l=cons(12,l);
	l=cons(11,l);
	l=cons(9,l);
	l=cons(7,l);
	printlist(l);
	
	printf("\n\nAlbero prima:\n\n");
	printAlbero(a,0);
	set_albbinric(a,l);
	printf("\n\nAlbero dopo:\n\n");
	printAlbero(a,0);
	printf("\n\n");*/
}

void printAlbero(TipoAlbero a, int space){
	if(a==NULL)
		return;
	space+=10;
	printAlbero(a->destro,space);
	for(int i=10;i<space;i++)
		printf(" ");
	printf("%d\n",radice(a));
	printAlbero(a->sinistro,space);	
}

TipoInfoAlbero max(TipoInfoAlbero dato1, TipoInfoAlbero dato2){
	if(dato1>=dato2)
		return dato1;
	else
		return dato2;
}

bool foglia(TipoAlbero a){
	return (a->sinistro==NULL && a->destro==NULL); 
}

bool singolo(TipoAlbero a){
	return ((a->sinistro!=NULL && a->destro==NULL) || (a->sinistro==NULL && a->destro!=NULL));
}

TipoLista append(TipoLista l,T e){
	if(estVuota(l))
		return cons(e,l);
	return cons(car(l),append(cdr(l),e));
}

TipoLista concat(TipoLista l1,TipoLista l2){
	if(estVuota(l2))
		return l1;
	return concat(append(l1,car(l2)),cdr(l2));
}

int length(TipoLista l){
	if(estVuota(l))
		return 0;
	else
		return 1+length(cdr(l));
}

TipoInfoAlbero trova_massimo(TipoAlbero a){
	if(estVuoto(a))
		return -1;
	else{
		TipoInfoAlbero s=trova_massimo(a->sinistro);
		TipoInfoAlbero d=trova_massimo(a->destro);
		TipoInfoAlbero x=max(s,d);
		return max(radice(a),x);
	}
}

TipoInfoAlbero somma_foglie(TipoAlbero a){
	if(estVuoto(a))
		return -1;
	else if(a->sinistro==NULL && a->destro==NULL)
		return radice(a);
	else{
		TipoInfoAlbero s=somma_foglie(a->sinistro);
		TipoInfoAlbero d=somma_foglie(a->destro);
		return s+d;		
	}
}

int cerca_livello(TipoAlbero a, TipoInfoAlbero v){
	return cerca_livello_aux(a,v,0);
}

int cerca_livello_aux(TipoAlbero a, TipoInfoAlbero v, int i){
	if(estVuoto(a))
		return -1;
	else if(radice(a)==v)
		return i;
	else
		return max(cerca_livello_aux(a->sinistro,v,i+1),cerca_livello_aux(a->destro,v,i+1));
}

int conta_dispari(TipoAlbero a){
	if(estVuoto(a))
		return 0;
	else if(!foglia(a) && (radice(a)+radice(a->sinistro)+radice(a->destro))%2==1)
		return 1+conta_dispari(a->sinistro)+conta_dispari(a->destro);
	else
		return conta_dispari(a->sinistro)+conta_dispari(a->destro);
}

int somma_singoli(TipoAlbero a){
	if(estVuoto(a))
		return 0;
	else if(singolo(a))
		return radice(a)+somma_singoli(a->sinistro)+somma_singoli(a->destro);
	else
		return somma_singoli(a->sinistro)+somma_singoli(a->destro);
}

TipoLista albero_lista(TipoAlbero a){
	if(estVuoto(a))
		return listaVuota();
	else{
		TipoLista t=albero_lista(a->destro);
		t=cons(radice(a),t);
		TipoLista t2=albero_lista(a->sinistro);
		return concat(t2,t);
	}
}

TipoLista percorso_lungo(TipoAlbero a){
	TipoLista max=listaVuota();
	percorso_lungo_aux(a,listaVuota(),&max);
	return max;
}

void percorso_lungo_aux(TipoAlbero a, TipoLista l, TipoLista* max){
	if(estVuoto(a)){}
	l=cons(radice(a),l);
	if(foglia(a)){
		if(length(l)>length(*max))
			*max=l;
	}
	else{
		percorso_lungo_aux(a->sinistro,l,max);
		percorso_lungo_aux(a->destro,l,max);
	}	
}

void somma_sottoalbero(TipoAlbero a){
	if(a==NULL){}
	else if(!foglia(a)){
		somma_sottoalbero(a->sinistro);
		somma_sottoalbero(a->destro);
		assegnaRadice(a,a->sinistro->info+a->destro->info);
	}
}

void scambia_foglie(TipoAlbero a){
	if(a==NULL){}
	else if(!foglia(a) && !singolo(a) && (foglia(a->sinistro)&&foglia(a->destro))){
		int temp=a->sinistro->info;
		a->sinistro->info=a->destro->info;
		a->destro->info=temp;
	}
	else{
		scambia_foglie(a->sinistro);
		scambia_foglie(a->destro);
	}
}

void max_figli_livello(TipoAlbero a, int livello){
	if(estVuoto(a)){}
	else if(livello==0){
		if(!foglia(a) && !singolo(a))
			assegnaRadice(a,max(a->sinistro->info,a->destro->info));
		else if(a->sinistro!=NULL && a->destro==NULL)
			assegnaRadice(a,a->sinistro->info);
		else if(a->sinistro==NULL && a->destro!=NULL)
			assegnaRadice(a,a->destro->info);
		else
			assegnaRadice(a,0);				
	}
	else{
		max_figli_livello(a->sinistro,livello-1);
		max_figli_livello(a->destro,livello-1);						
	}
}

void scambia_foglie_livello(TipoAlbero a, int livello){
	if(estVuoto(a)){}
	else if(livello==1 && !estVuoto(a->sinistro) && !estVuoto(a->destro) && foglia(a->sinistro) && foglia(a->destro)){
		TipoInfoAlbero t=radice(a->sinistro);
		assegnaRadice(a->sinistro,a->destro->info);
		assegnaRadice(a->destro,t);					
	}
	else{
		scambia_foglie_livello(a->sinistro,livello-1);
		scambia_foglie_livello(a->destro,livello-1);						
	}
}

void set_albbinric(TipoAlbero a, TipoLista l){
	int n=length(l);
	set_albbinric_aux(a,l,n);
}

void set_albbinric_aux(TipoAlbero a, TipoLista l, int n){
	if(estVuoto(a) || n==0){}
	else{
		int m=n/2;
		TipoLista l2=l;
		for(int i=0;i<m;i++)
			l2=cdr(l2);
		assegnaRadice(a,car(l2));
		TipoLista ls=listaVuota();
		TipoLista ld=listaVuota();
		for(int i=0;i<m;i++){
			ls=append(ls,car(l));
			l=cdr(l);
		}
		l=cdr(l);
		for(int i=m+1;i<n;i++){
			ld=append(ld,car(l));
			l=cdr(l);
		}
		set_albbinric_aux(a->sinistro,ls,m);
		set_albbinric_aux(a->destro,ld,n-m-1);
	}
}
