#include "e1A.h"
//24, 28, 32
//  out = ebp
//  i = ecx
//  a = esi
//  b = edi
unsigned int* div_vectors(unsigned int* a, unsigned int* b, int n) {
    if (a == NULL || b == NULL || n == 0)
        return NULL;
    unsigned int* out = malloc(sizeof(unsigned int) * n);
    int i;
    for (i = 0; i < n; i++) {
        out[i] = a[i] / b[i];  // usare idiv, attenzione a edx!
    }
    return out;
}
