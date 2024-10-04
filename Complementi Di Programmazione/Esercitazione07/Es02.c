#include <stdio.h>
#include <stdlib.h>

//typedef float TipoInfoSCL;
typedef char TipoInfoSCL;

struct ElemSCL
{
    TipoInfoSCL info;
    struct ElemSCL *next;
};

typedef struct ElemSCL TipoNodoSCL;
typedef TipoNodoSCL * TipoSCL;

void printscl(TipoSCL scl)
{
    if (scl != NULL)
    {
        printf("%d ", scl->info);
        printscl(scl->next);
    }
}

void prints(TipoSCL scl)
{
    printscl(scl);
    printf("\n");
}

int scl_len(TipoSCL p)
{
    if (p == NULL)
        return 0;
    else
        return 1 + scl_len(p->next);
}

int scl_sum(TipoSCL scl)
{
    if (scl == NULL)
        return 0;
    else
        return scl->info + scl_sum(scl->next);
}

float scl_media(TipoSCL scl)
{
    return scl_sum(scl)/scl_len(scl);
}

float scl_dot(TipoSCL scl1, TipoSCL scl2)
{
    if (scl_len(scl1) != scl_len(scl2))
    {
        printf("Non si può fare");
        exit(1);
    }
    else if (scl1 == NULL)
        return 0;
    else
        return scl1->info * scl2->info + scl_dot(scl2->next, scl2->next);
}

void scl_duplicate_pos_aux(TipoSCL scl, int pos, int i)
{
    if (i == pos)
    {
        TipoSCL temp = (TipoSCL) malloc(sizeof(TipoNodoSCL));
        temp->info = scl->info;
        temp->next = scl->next;
        scl->next = temp;
    }
    else
        scl_duplicate_pos_aux(scl->next, pos, i+1);
}

void scl_duplicate_pos(TipoSCL scl, int pos)
{
    return scl_duplicate_pos_aux(scl, pos, 0);
}

// void scl_positives(TipoSCL scl, TipoSCL *ris)
// {

// }

void sclstring_print(TipoSCL s)
{
    if (s != NULL)
    {
        printf("%c", s->info);
        sclstring_print(s->next);
    }
}

void printss(TipoSCL s)
{
    sclstring_print(s);
    printf("\n");
}

//da finire

int main()
{
    TipoSCL p1 = (TipoSCL) malloc(sizeof(TipoNodoSCL));
    p1->info = 2;
    p1->next = NULL;

    TipoSCL temp = (TipoSCL) malloc(sizeof(TipoNodoSCL));
    temp->info = 3;
    temp->next = NULL;

    p1->next = temp;

    temp = (TipoSCL) malloc(sizeof(TipoNodoSCL));
    temp->info = 5;
    temp->next = NULL;

    p1->next->next = temp;

    temp = (TipoSCL) malloc(sizeof(TipoNodoSCL));
    temp->info = 1;
    temp->next = NULL;

    p1->next->next->next = temp;

    // prints(p1);
    // printf("%d\n", scl_len(p1));
    // printf("%d\n", scl_sum(p1));

    // scl_duplicate_pos(p1, 2);

    // prints(p1);

    TipoSCL s1 = (TipoSCL) malloc(sizeof(TipoNodoSCL));
    s1->info = 'c';
    s1->next = NULL;

    temp = (TipoSCL) malloc(sizeof(TipoNodoSCL));
    temp->info = 'i';
    temp->next = NULL;

    s1->next = temp;

    temp = (TipoSCL) malloc(sizeof(TipoNodoSCL));
    temp->info = 'a';
    temp->next = NULL;

    s1->next->next = temp;

    printss(s1);

    return 0;
}