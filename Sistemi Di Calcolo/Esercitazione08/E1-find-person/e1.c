#include "e1.h"
#include <stdio.h>

int com(const void *a, const void *b)
{
	person_t  *p1 = (person_t *) a;
	person_t  *p2 = (person_t *) b;

	return strcmp(p1->name, p2->name);
}

void sort_people(person_t p[], size_t n)
{
	qsort(p, n, sizeof(person_t), com);
}

person_t *find_person(char *key, person_t sorted[], size_t n)
{
	person_t p;
	p.name = key;
	return bsearch(&p, sorted, n, sizeof(person_t), com); //NOTA: la key dovrà essere comparata, e se uso la funz. com scritta sopra il parametro (key di bsearch) passato deve essere un person_t* se no va in SEGFAULT
}
