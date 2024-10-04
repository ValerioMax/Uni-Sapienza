#include "e3.h"

// La funzione my_strpbrk(s1, s2) deve restituire il puntatore alla prima 
// occorrenza in `s1` di un qualsiasi carattere presente nella stringa `s2` 
// oppure `NULL` se alcun carattere di s2 appare in `s1` prima che `s1` 
// stessa termini.

int is_in(char c, const char *s2)
{
	while (*s2)
		if (c == *s2++)
			return 1;
	return 0;
}

char *my_strpbrk(const char *s1, const char *s2)
{
	while (*s1)
	{
		if (is_in(*s1, s2))
			return (char *) s1;
		s1++;
	}
	return NULL;
}
