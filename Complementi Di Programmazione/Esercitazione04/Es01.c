#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

void random_array(int v[], int dim, int max_value)
{
    srand(time(0));
    for (int i = 0; i <= dim; i++)
    {
        v[i] = rand() % max_value;
    }
}

double* vec_clone(const double v[], int dim)
{
    double vcopy[dim];
    for (int i = 0; i <= dim; i++)
    {
        vcopy[i] = v[i];
    }
    double* pt_vcopy = vcopy;
    return pt_vcopy;
}

void vec_scale(double v[], int dim, double scale)
{
    for (int i = 0; i <= dim; i++)
    {
        v[i] = scale * v[i];
    }
}

int countrep(int n, int v[], int dim)
{
    int count = 0;
    for (int j = 0; j <= dim; j++)
    {
        if (n == v[j])
            count++;
    }
    return count;
}
//??????????????????????????????:
// int* numeri_unici(const int array[], int dim, int *output_dim)
// {
//     int x = 0;
//     int dopp[dim];
//     for (int i = 0; i < dim; i++)
//     {
//         if (countrep(array[i], dopp, dim) == 0 && countrep(array[i], array, dim) == 0)
//         {
            
//         }
//     }
// }

void print_chars(const char s[], const int idxs[], int dim)
{
    for (int i = 0; i <= dim; i++)
    {
        if (idxs[i] < strlen(s) - 1)
            putchar(s[idxs[i]]);
        //alternativamente si usa il printf
        //printf("%c", s[idxs[i]]);
    }
}

char* select_chars(const char s[], const int idxs[], int dim)
{
    char* p_str = (char*) malloc(sizeof(char) * dim);

    for (int i = 0; i <= dim; i++)
    {
        if (idxs[i] < strlen(s) - 1)
            p_str[i] = s[idxs[i]];
    }
    return p_str;
}

char* invert_string(char s[])
{
    char temp;
    int x;
    if ((strlen(s) - 1)% 2 == 0)
        x = (strlen(s) - 1)/ 2;
    else
        x = (strlen(s) - 2) / 2;
    for (int i = 0; i < x; i++)
    {
        temp = s[i];
        s[i] = s[strlen(s) - 2 - i];
        s[strlen(s) - 2 - i] = temp;
    }
    char* ps = s;
    return ps;
}

char* mocking_spongebob(const char s[], int step)
{
    char* p_s1 = (char*) malloc(sizeof(char) * strlen(s));
    int x = 0;
    int k = 0;
    for (int i = 0; i < strlen(s); i++)
    {
        if (k == x)
        {
            if (s[i] >= 97 && s[i] <= 122)
                p_s1[i] = s[i] - 32;
            else
                p_s1[i] = s[i];
            x += step;
        }
        else
        {
            if (s[i] == ' ')
            {
                p_s1[i] = s[i];
                k--;
            }
            else
                p_s1[i] = s[i];
        }
        k++;
    }
    return p_s1;
}

char* capitalizer(const char s[])
{
    char* p_s1 = (char*) malloc(sizeof(char) * strlen(s));
    //for (int i = 0; i < strlen(s); i++)
    int i = 0;
    while (s[i] != '\0')
    {
        if (i == 0)
        {
            if (s[i] >= 97 && s[i] <= 122)
                p_s1[i] = s[i] - 32;
            else
                p_s1[i] = s[i];
        }
            
        else if (s[i - 1] == ' ')
        {
            if (s[i] >= 97 && s[i] <= 122)
                p_s1[i] = s[i] - 32;
            else
                p_s1[i] = s[i];
        }
        else
        {
            if (s[i] >= 65 && s[i] <= 90)
                p_s1[i] = s[i] + 32;
            else
                p_s1[i] = s[i];
        }
        i++;
    }
    return p_s1;
}

char** capitalizer_strings(const char* s[], int len)
{
    char** p_ps = (char**) malloc(sizeof(char) * len);
    for (int i = 0; i < len; i++)
    {
        p_ps[i] = capitalizer(s[i]);
    }
    return p_ps;
}

char ** read_lines(const char filepath[], int *lines_n)
{
    FILE* file = fopen(filepath, "r");
    if (file == NULL)
    {
        printf("Errore nell'apertura del file\n");
    }
    char c[256];
    while (fscanf(file, " %s", c) != EOF)
        printf("%s", c);
    int close = fclose(file);
}

int main()
{
    // const int n = 5;
    // int array[n];
    // random_array(array, n, 20);
    // int* p = array;
    // printf("%d", p[3]);

    //    double vec[5] = {11,22,33,44,55};
    //    printf("%lf", vec_clone(vec, 5)[4]);

    // int v[] = {1,2,2,2,3,4,5,5,6};
    // printf("%d", countrep(5, v, 9));

    //char s[] = {'c','i','a','o','!','\0'};
    //int idxs[] = {1,3,5,5,0,2,0,0,9,0};
    //print_chars(s, idxs, 10);
    //printf("%c", select_chars(s, idxs, 10)[1]);
    //putchar(invert_string(s)[3]);

    // char s[] = "Non puoi insegnare TDP gjmthdt gj h ghfh jfhjgj  gg gggg AAA beshtgeAAAA";
    // for (int i = 0; i < strlen(s); i++)
    // {
    //     putchar(mocking_spongebob(s, 2)[i]);
    // }

    // char s[] = "i punTAtoRi Sono semPLici";
    // for (int i = 0; i < strlen(s); i++)
    // {
    //     putchar(capitalizer(s)[i]);
    // }
    // int i = 0;
    // while (s[i] != '\0')
    // {
    //     putchar(capitalizer(s)[i++]);
    // }
    
    // const char* s[] = {"cIao","CASA","CIaoaoOo"};
    // char** new_s = capitalizer_strings(s, 3);
    // for (int i = 0; i < 3; i++)
    //     printf("%s\n", new_s[i]);

    return 0;
}