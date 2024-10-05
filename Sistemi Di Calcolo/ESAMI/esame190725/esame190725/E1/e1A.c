#include "e1A.h"
//
//28, 32
//  s = ebp
//  map = edi
//  max = esi
//  map[i] = dl
//  i = ecx
//  
int most_freq_char(const char* s, int* map) {
    int i, max = 0;
    clear(map, 256);
    while (*s) map[*s++]++;
    for (i=0; i<256; ++i)
        if (map[i] > map[max]) max = i;
    return max;
}

//map[*]