#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

float product(float vec[], int n)
{
    if (n <= 0)
    {
        printf("Vettore nullo");
        return 1;
    }    
    else if (n == 1)
        return vec[n - 1];
    else if (n > 1)
        return vec[n - 1] * product(vec, n - 1);  
}

float vec_somprec(float v[], int n)
{
    n--;
    if (n == 0)
        return 0;
    else
        return v[n - 1] + vec_somprec(v, n - 1);
}

void vec_integral(float* v, int n)
{
    n--;
    if (n == 0)
        v[n] = 0;
    else
        v[n] = vec_somprec(v, n);
        vec_integral(v, n - 1);
}

void printvec(float v[], int n)
{
    int i = 0;
    while (i < n)
    {
        printf("%.2f, ", v[i]);
        i++;
    } 
}

int length(char * s)
{
    if (s[0] == '\0')
        return 0;
    else
        return 1 + length(s + 1); 
}

int char_position(char* s, char ch)
{
    if (s[0] == ch)
        return 0;
    else
        return 1 + char_position(s + 1, ch);
}

bool is_lowercase(char *s)
{
    if (s[0] == '\0')
        return true;
    else if (s[0] >= 'a' && s[0] <= 'z')
        return is_lowercase(s + 1);
    else
        return false;        
}

bool is_any_lowercase(char *s)
{
    if (s[0] >= 'a' && s[0] <= 'z')
        return true;
    else
    {
        if (s[0] == '\0')
            return false;
        else
            return is_any_lowercase(s + 1);
    }
}

void to_uppercase(char *s)
{
    if (s[0] >= 'a' && s[0] <= 'z')
    {
        s[0] = s[0] - ('a'-'A');
        to_uppercase(s + 1);
    }
    else if (s[0] != '\0')
        return to_uppercase(s + 1);
}

void printstr(char* s)
{
    int i = 0;
    while (s[i] != '\0')
    {
        printf("%c", s[i]);
        i++;
    }
    printf("\n");
}

void copy(char * dest, char * src)
{
    if (src[0] == '\0')
        dest[0] = src[0];
    else
    {
        dest[0] = src[0];
        copy(dest + 1, src + 1);
    }
}

void concat(char * dest, const char * src)
{
    if (dest[0] == '\0')
    {
        if (src[0] != 0)
        {
            dest[0] = src[0];
            dest[1] = '\0';
            concat(dest + 1, src + 1);
        }
    }
    else
        concat(dest + 1, src);
}

int main()
{
    // float v[] = {2,2,2,2,2,2,2};
    // float x = product(v, 7);
    // printf("%f", x);

    // float v[] = {1,2,1,3,2};
    // vec_integral(v, 5);
    // printvec(v, 5);

    // char s[] = "Ciao!!aaaaa";
    // printf("%d", length(s));

    // char s[] = "Ciao!caa";
    // printf("%d", char_position(s, '?'));

    // char s[] = "ciao";
    // bool var = is_lowercase(s);
    // if (var)
    //     printf("OK");
    // else
    //     printf("No");

    // char s[] = "cIAO";
    // bool var = is_any_lowercase(s);
    // if (var)
    //     printf("OK");
    // else
    //     printf("No");

    // char s[] = "cIaOaaAa";
    // to_uppercase(s);
    // printstr(s);
    
    // char s1[] = "Ciaooooa";
    // char* s2 = (char*) malloc(sizeof(char) * length(s1));
    // printstr(s2);
    // copy(s2, s1);
    // printstr(s1);
    // printstr(s2);

    return 0;
}