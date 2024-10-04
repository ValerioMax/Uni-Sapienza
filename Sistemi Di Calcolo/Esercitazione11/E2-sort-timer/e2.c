#include "e2.h"

static void do_sort(int *v, int n) {
    int i, j;
    for (i=0; i<n; ++i)
        for (j=1; j<n; ++j)
            if (v[j-1] > v[j]) {
                int tmp = v[j-1];
                v[j-1] = v[j];
                v[j] = tmp;
            }
}

void sort(int *v, int n) {

    // completare con gestione segnali...

    do_sort(v, n);
}

