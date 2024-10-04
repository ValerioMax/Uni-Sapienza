#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

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
            m->rows_pt[i][j] = rand()%3;
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
        {
            printf("%.1f  ", m->rows_pt[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

Mat* mat_clone(Mat* m)
{
    Mat* m1 = (Mat*) malloc(sizeof(Mat));
    m1->rows = m->rows;
    m1->cols = m->cols;
    m1->rows_pt = (float**) malloc(sizeof(float*) * m1->rows);
    for (int i = 0; i < m1->rows; i++)
    {
        m1->rows_pt[i] = (float*) malloc(sizeof(float) * m1->cols);
        for (int j = 0; j < m1->cols; j++)
            m1->rows_pt[i][j] = m->rows_pt[i][j];
    }
    return m1;
}

bool mat_is_symmetric(Mat* m)
{
    if (m->rows != m->cols)
    {
        printf("Matrice non quadrata\n");
        return false;
    }
    for (int i = 0; i < m->rows; i++)
    {
        for (int j = 0; j < m->cols; j++)
        {
            if (m->rows_pt[i][j] != m->rows_pt[j][i])
                return false;
        }
    }
    return true;
}

void mat_normalize_rows(Mat* m)
{
    
    for (int i = 0; i < m->rows; i++)
    {
        float norma = 0;
        for (int j = 0; j < m->cols; j++)
        {
            norma = norma + pow(m->rows_pt[i][j], 2);
        }
        norma = sqrt(norma);

        for (int j = 0; j < m->cols; j++)
        {
            m->rows_pt[i][j] = m->rows_pt[i][j] / norma;
        }
    }
}

Mat* mat_sum(Mat *m1, Mat *m2)
{
    if (m1->rows != m2->rows || m1->cols != m2->cols)
    {
        printf("dimensioni matrici diverse\n");
        return NULL;
    }

    Mat* m = (Mat*) malloc(sizeof(Mat));
    m->rows = m1->rows;
    m->cols = m1->cols;
    m->rows_pt = (float**) malloc(sizeof(float*) * m->rows);
    for (int i = 0; i < m->rows; i++)
    {
        m->rows_pt[i] = (float*) malloc(sizeof(float) * m->cols);
        for (int j = 0; j < m->cols; j++)
            m->rows_pt[i][j] = m1->rows_pt[i][j] + m2->rows_pt[i][j];
    }
    return m;
}

//cosa chiede? la matrice dei valori medi?
Mat* mat_average(Mat *m1, Mat *m2)
{
    Mat* m = mat_sum(m1, m2);
    for (int i = 0; i < m->rows; i++)
    {
        for (int j = 0; j < m->cols; j++)
            m->rows_pt[i][j] = m->rows_pt[i][j] / 2;
    }
    return m;
}

float rigapercolonna(float* v1, float* v2, int len)
{
    int x = 0;
    for (int j = 0; j < len; j++)
        x = x + (v1[j] * v2[j]);

    return x;
}

Mat* mat_product(Mat *m1, Mat *m2)
{
    if (m1->cols != m2->rows)
    {
        printf("Dimensioni matrici non permette prodotto M1 M2 (non M2 M1)");
        return NULL;
    }
    Mat* m = (Mat*) malloc(sizeof(Mat));
    m->rows = m1->rows;
    m->cols = m2->cols;
    m->rows_pt = (float**) malloc(sizeof(float*) * m->rows);
    for (int i = 0; i < m->rows; i++)
    {
        m->rows_pt[i] = (float*) malloc(sizeof(float) * m->cols);
        for (int j = 0; j < m->cols; j++)
        {
            //trovo il vettore colonna di m2, mentre il vettore riga di m1 è semplicemente m1->rows_pt[i]
            float v[m2->rows];
            for (int k = 0; k < m2->rows; k++)
                v[k] = m2->rows_pt[k][j];

            m->rows_pt[i][j] = rigapercolonna(m1->rows_pt[i], v, m2->rows);
        }
    }
    return m;
}

int main()
{
    // Mat* m = mat_alloc(3, 2);
    // mat_print(m);

    // Mat* m1 = mat_clone(m);
    // mat_print(m1);

    // if (mat_is_symmetric(m))
    //     printf("OK");
    // else
    //     printf("NO");

    // mat_normalize_rows(m);
    // mat_print(m);

    // Mat* m2 = mat_sum(m, m);
    // mat_print(m2);

    // float v1[] = {2,2,1};

    // float v2[] = {1,2,1};

    // printf("%.f\n", rigapercolonna(v1, v2, 3));

    // Mat* m = mat_alloc(3, 2);
    // mat_print(m);

    // Mat* m3 = mat_alloc(2, 3);
    // mat_print(m3);

    // Mat* m4 = mat_product(m, m3);
    // mat_print(m4);

    return 0;
}