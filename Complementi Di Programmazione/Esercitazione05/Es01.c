#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#include <time.h>
#include <unistd.h>

typedef struct {
  int rows;
  int cols;
  float **rows_pt;
} Mat;

Mat* mat_alloc(int rows, int cols)
{
    Mat* m = (Mat*) malloc(sizeof(Mat));
    m->rows = rows;
    m->cols = cols;
    m->rows_pt = (float**) malloc(sizeof(float*) * rows);
    for (int i = 0; i < rows; i++)
    {
        m->rows_pt[i] = (float*) malloc(sizeof(float) * cols);
        for (int j = 0; j < cols; j++)
            m->rows_pt[i][j] = rand()%2;
    }
    return m;
}

void mat_free(Mat *m)
{
    for (int i = 0; i < m->rows; i++)
        free(m->rows_pt[i]);
    free(m->rows_pt);
    free(m);
}

void mat_print(Mat *m)
{
    for (int i = 0; i < m->rows; i++)
    {
        for (int j = 0; j < m->cols; j++)
            printf("%0.f  ", m->rows_pt[i][j]);
        printf("\n");
    }
    printf("\n");
}

Mat* mat_clone(Mat *m)
{
    Mat* m1 = (Mat*) malloc(sizeof(Mat));
    m1->rows = m->rows;
    m1->cols = m->cols;
    m1->rows_pt = (float**) malloc(sizeof(float*) * m->rows);
    for (int i = 0; i < m1->rows; i++)
    {
        m1->rows_pt[i] = (float*) malloc(sizeof(float) * m1->cols);
        for (int j = 0; j < m1->cols; j++)
            m1->rows_pt[i][j] = m->rows_pt[i][j];
    }
    return m1;
}

bool mat_is_symmetric(Mat *m)
{
    bool var = true;
    for (int i = 0; i < m->rows; i++)
    {
        for (int j = 0; j < m->cols; j++)
            if (m->rows_pt[i][j] != m->rows_pt[j][i])
                var = false;      
    }
    return var;
}

//sbagliato: va divisa la norma del vettore riga i-esima, non il modulo di ogni elemento di tale vettore. Vedi Es2.c
void mat_normalize_rows(Mat *m)
{
    for (int i = 0; i < m->rows; i++)
    {
        for (int j = 0; j < m->cols; j++)
        {
            printf("%0.2f  ", m->rows_pt[i][j] / abs(m->rows_pt[i][j]));
        }
        printf("\n");
    }
    printf("\n");
}

Mat* mat_sum(Mat *m1, Mat *m2)
{
    if (m1->rows != m2->rows || m1->cols != m2->cols)
    {
        printf("Errore: m1 e m2 hanno diverso numero di colonne/righe");
        return NULL;
    }
    else
    {
        Mat* ms = (Mat*) malloc(sizeof(Mat));
        ms->rows = m1->rows;
        ms->cols = m1->cols;
        ms->rows_pt = (float**) malloc(sizeof(float*) * m1->rows);
        for (int i = 0; i < ms->rows; i++)
        {
            ms->rows_pt[i] = (float*) malloc(sizeof(float) * ms->cols);
            for (int j = 0; j < ms->cols; j++)
                ms->rows_pt[i][j] = m1->rows_pt[i][j] + m1->rows_pt[i][j];
        }
        return ms;
    }   
}

Mat* mat_product(Mat *m1, Mat *m2)
{
    if (m1->cols != m2->rows)
    {
        printf("Errore: numero di colonne di m1 != numero di righe di m2");
        return NULL;
    }
    else
    {
        
        Mat* mp = (Mat*) malloc(sizeof(Mat));
        mp->rows = m1->rows;
        mp->cols = m2->cols;
        mp->rows_pt = (float**) malloc(sizeof(float*) * mp->rows);
        for (int i = 0; i < mp->rows; i++)
        {
            mp->rows_pt[i] = (float*) malloc(sizeof(float) * mp->cols);
            for (int j = 0; j < mp->cols; j++)
            {
                float sum = 0;
                for(int h = 0; h < m1->cols; h++)
                {
                    float x = 0;
                    for(int k = 0; k < m2->rows; k++)
                    {
                        if (h == k)
                        {
                            x = m1->rows_pt[i][h] * m2->rows_pt[k][j];
                            sum += x;
                        }
                    }
                }
                mp->rows_pt[i][j] = sum;
            }
        }
        return mp;
    }
}

Mat* game_of_life(Mat* m)
{
    Mat* m1 = (Mat*) malloc(sizeof(Mat));
    m1->rows = m->rows;
    m1->cols = m->cols;
    m1->rows_pt = (float**) malloc(sizeof(float*) * m1->rows);
    int x = 0;
    for (int i = 0; i < m1->rows; i++)
    {
        m1->rows_pt[i] = (float*) malloc(sizeof(float) * m1->cols);
        for (int j = 0; j < m1->cols; j++)
        {
            if ((j > 0) && (int) m->rows_pt[i][j-1] == 1)
                x++;
            if ((j < m1->cols - 1) && (int) m->rows_pt[i][j+1] == 1)
                x++;
            if ((i > 0) && (int) m->rows_pt[i-1][j] == 1)
                x++;
            if ((i < m1->rows - 1) && (int) m->rows_pt[i+1][j] == 1)
                x++;
            if ((j > 0) && (i > 0) && (int) m->rows_pt[i-1][j-1] == 1)
                x++;
            if ((i > 0) && (j < m1->cols - 1) && (int) m->rows_pt[i-1][j+1] == 1)
                x++;
            if ((i < m1->rows - 1) && (j > 0) && (int) m->rows_pt[i+1][j-1] == 1)
                x++;
            if ((i < m1->rows - 1) && (j < m1->cols - 1) && (int) m->rows_pt[i+1][j+1] == 1)
                x++;
            
            if (x < 2)
                m1->rows_pt[i][j] = 0;
            else if ((x == 3) && (m->rows_pt[i][j] == 0))
                m1->rows_pt[i][j] = 1;
            else if ((x == 2 || x == 3) &&  (m->rows_pt[i][j] == 1))
                m1->rows_pt[i][j] = 1;
            else if ((x == 2 || x == 3) &&  (m->rows_pt[i][j] == 0))
                m1->rows_pt[i][j] = 0;
            else if (x > 3)
                m1->rows_pt[i][j] = 0;
            x = 0;
        }
    }
    return m1;
}

void mat_print2(Mat* m)
{
    for (int i = 0; i < m->rows; i++)
    {
        for (int j = 0; j < m->cols; j++)
        {
            if (m->rows_pt[i][j] == 1)
                printf("%c ", 254);
            else
                printf("  ", 79);
        }
            
        printf("\n");
    }
    printf("\n");
}

void print_gameoflife(Mat* m)
{
    char c;
    while (true)
    {
        Mat* m1 = game_of_life(m);
        mat_print2(m1);
        sleep(0.95);
        system("cls");
        m = m1;
    }  
}

Mat* mat_alloc2(int rows, int cols)
{
    Mat* m = (Mat*) malloc(sizeof(Mat));
    m->rows = rows;
    m->cols = cols;
    m->rows_pt = (float**) malloc(sizeof(float*) * rows);
    float n;
    for (int i = 0; i < rows; i++)
    {
        m->rows_pt[i] = (float*) malloc(sizeof(float) * cols);
        for (int j = 0; j < cols; j++)
        {
            printf("Elem [%d][%d]: ", i, j);
            scanf("%f", &n);
            m->rows_pt[i][j] = n;
        }  
    }
    return m;
}

Mat* mat_alloc3(int rows, int cols)
{
    Mat* m = (Mat*) malloc(sizeof(Mat));
    m->rows = rows;
    m->cols = cols;
    m->rows_pt = (float**) malloc(sizeof(float*) * rows);
    
    FILE* f = fopen("cannone1.txt", "r");
    char x = fgetc(f);
    int x1 = x - '0';
    char spazio;
    while (x != EOF)
    {
        for (int i = 0; i < rows; i++)
        {
            m->rows_pt[i] = (float*) malloc(sizeof(float) * cols);
            for (int j = 0; j < cols; j++)
            {
                m->rows_pt[i][j] = x1;
                spazio = fgetc(f);
                x = fgetc(f);
                x1 = x - '0';
            }  
        }
    }
    fclose(f);
    return m;
}

int main()
{
    // Mat* pm = mat_alloc(2,4);
    // mat_print(pm);
    // printf("\n\n");
    // Mat* pm1 = mat_clone(pm);
    // mat_print(pm1);


    // bool x = mat_is_symmetric(pm);
    // if (x == true)
    //     printf("Matrice simmetrica");
    // else
    //     printf("Matrice non simmetrica");


    // mat_normalize_rows(pm);

    // Mat *m1 = mat_alloc(3, 4);
    // Mat *m2 = mat_alloc(4, 4);
    // Mat *ms = mat_sum(m1, m2);
    // mat_print(ms);

    // Mat* m1 = mat_alloc(2,2);
    // Mat* m2 = mat_alloc(2,3);
    // mat_print(m1);
    // mat_print(m2);
    // Mat* mp = mat_product(m1, m2);
    // mat_print(mp);
    
    // Mat* m = mat_alloc2(10,10);
    // mat_print2(m);
    // printf("\n");
    
    // print_gameoflife(m);

    Mat* m = mat_alloc3(24,38);
    mat_print2(m);
    print_gameoflife(m);

    return 0;
}