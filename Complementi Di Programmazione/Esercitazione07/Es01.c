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

int scl_len(TipoSCL p)
{
    if (p == NULL)
        return 0;
    else
        return 1 + scl_len(p->next);
}

void a(TipoSCL p)
{
    if (p != NULL)
    {
        printf("%.2f, ", p->info);
        a(p->next);
    } 
}

void scl_print(TipoSCL p)
{
    printf("[");
    a(p);
    printf("\b\b]");
    printf("\n"); 
}

float scl_sum(TipoSCL scl)
{
    if (scl == NULL)
        return 0;
    else
        return scl->info + scl_sum(scl->next);
}

// float scl_media(TipoSCL scl)
// {
//     if (scl == NULL)
//         return 0;
//     else
//         return 
// }

float scl_dot(TipoSCL scl1, TipoSCL scl2)
{
    if (scl_len(scl1) != scl_len(scl2))
    {
        printf("vettori di dimensioni diverse");
        return 1;
    }
    else if (scl1 == NULL)
        return 0;
    else
        return (scl1->info * scl2->info) + scl_dot(scl1->next, scl2->next);
}

void scl_duplicate_pos(TipoSCL scl, int pos)
{
    if (pos >= scl_len(scl))
        printf("pos fuori dal range");
    else if (scl == NULL)
        return;
    else if (pos == 0)
    {
        TipoSCL temp = (TipoSCL) malloc(sizeof(TipoNodoSCL));
        temp->info = scl->info;
        temp->next = scl->next;
        scl->next = temp;
    }
    else
        scl_duplicate_pos(scl->next, pos - 1);
}

void sclstring_print(TipoSCL s)
{
    if (s != NULL)
    {
        printf("%c", s->info);
        sclstring_print(s->next);
    }         
}
//?
TipoSCL sclstring_create(const char *s)
{
    if (s[0] == '\0')
    {
        TipoSCL p = (TipoSCL) malloc(sizeof(TipoNodoSCL));
        p->info = ' ';
        p->next = NULL;
        return p;
    }
    else
    {
        TipoSCL p1 = (TipoSCL) malloc(sizeof(TipoNodoSCL));
        p1->info = s[0];
        p1->next = NULL;
    }
}

int main()
{
    //Lista1
    TipoSCL p1 = (TipoSCL) malloc(sizeof(TipoNodoSCL));
    p1->info = 2;
    p1->next = NULL;

    TipoSCL temp = (TipoSCL) malloc(sizeof(TipoNodoSCL));
    temp->info = 3;
    temp->next = NULL;

    p1->next = temp;

    temp = (TipoSCL) malloc(sizeof(TipoNodoSCL));
    temp->info = 1;
    temp->next = NULL;

    p1->next->next = temp;

    //Lista2
    TipoSCL p2 = (TipoSCL) malloc(sizeof(TipoNodoSCL));
    p2->info = 2;
    p2->next = NULL;

    temp = (TipoSCL) malloc(sizeof(TipoNodoSCL));
    temp->info = 4;
    temp->next = NULL;

    p2->next = temp;

    temp = (TipoNodoSCL* /*stessa cosa di scrivere TipoSCL*/) malloc(sizeof(TipoNodoSCL));
    temp->info = 2;
    temp->next = NULL;

    p2->next->next = temp;

    //scl_print(p1);
    // scl_print(p2);
    // printf("\n\n%.2f", scl_dot(p1,p2));

    // printf("%d", scl_len(p1));

    //printf("%.2f\n", scl_sum(p1));

    // scl_duplicate_pos(p1, 3);
    // printf("\n");
    // scl_print(p1);

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

    sclstring_print(s1);

    return 0;
}