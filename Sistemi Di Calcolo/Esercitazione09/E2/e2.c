#include "e2.h"

int crc32b(char *bytes, int n) { //esi, edi
    int magic = ~0; //ecx
    int crc = magic; //ebp
    while (n--) {
        int value; //ebx
        int byte = *bytes++; //ecx
        int index = crc ^ byte; //ecx
        get_constant(&value, index & 0xFF);
        crc = value ^ (crc >> 8);
    }
    return crc ^ magic;
}

//capire come prima cosa tutti i registri che servono dopo la chiamata
//  in questo caso alcuni vengno riscritti nelle iterazioni successive del ciclo quindi si puo usare quelli normali

//NOTA: si può creare spazio in stack per metterci valori che non si saprebbe dove mettere perche si ha finite le variabili
//      (e poi si usa un registro di appoggio solo per fare un'operazione con tali valori)

magic : norm (ecx) ma rivalutarlo solo alla fine del ciclo
crc : spec
bytes : spec
n : spec
value : spec 
byte :  norm (ecx visto che magic lo valuto alla fine)
index : norm
