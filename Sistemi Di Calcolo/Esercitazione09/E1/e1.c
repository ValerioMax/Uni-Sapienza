#include "e1.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

person_t *new_person(char *name, char *surname, int year, int phd, person_t *next)
{
    person_t *p = malloc(sizeof(person_t));

    p->name = name;
    p->surname = surname;
    p->year = year;
    p->has_phd = phd;
    p->next = next;

    return p;
}

int parseCSV(const char* file, person_t** out, int minAge) {
    int res;
    FILE *f = fopen(file, "r");
    if (!f) goto CLEANUP;               //se non è riuscito ad aprire il file errore

    res =  fseek(f, 0, SEEK_END);       //porto alla fine il puntatore a caratteri del file
    if (ftell(f) == 0) goto CLEANUP;    //se pos. corrente == 0 il file è vuoto
    res =  fseek(f, 0, SEEK_SET);       //altrimenti riporta all'inizio puntatore

    char *buf = malloc(65);
    char *token;
    char *name;
    char *surname;
    int year;
    int phd;
    person_t *temp;

    *out = NULL;

    while(feof(f) == 0)
    {
        buf = fgets(buf, 65, f);

        token = strtok(buf, ",");
        name = strdup(token);

        token = strtok(NULL, ",");
        surname = strdup(token);

        token = strtok(NULL, ",");
        year = (token[6] - '0')*1000 + (token[7] - '0')*100 + (token[8] - '0')*10 + (token[9] - '0');

        token = strtok(NULL, ",");
        phd = (token[0] == 'y') ? 1 : 0;

        if (year >= minAge)
        {
            if (!*out) //se la lista è vuota crea nodo iniziale
            {
                *out = new_person(name, surname, year, phd, NULL);
                temp = *out;
            }
            else //altrimenti aggiunge in coda
            {
                temp->next = new_person(name, surname, year, phd, NULL);
                temp = temp->next;
            }                
        }
        else
        {
            free(name);
            free(surname);
        }
    }
    free(buf);
    fclose(f);
    return 0;

CLEANUP:
    int old_errno = errno;  //mi salvo il valore di errno

    *out = NULL;
    if (f)
    {
        fclose(f);          
        errno = old_errno;  //nel caso l'istr precedente vada in errore riporto errno al valore salvato (errore del programma effettivo e non del CLEANUP (gestione errori))
        return 0;
    }
    else
        return -1;
}