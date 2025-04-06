#ifndef BITKI_H
#define BITKI_H
#include "Canli.h"

struct Bitki
{
    Canli super;
    char* sembol; //Varsayılan sembol eğer girilmezse bu sembol kullanılacak
    //ancak eğer bu sembol kullanılmıyorsa girilmeyince tekrar kontrol sağlanacak
    void (*yoket)(struct Bitki*);

};

typedef struct Bitki* Bitki;
Bitki bitki_yarat(char*, int);
char* Gorunum(const Bitki);
void* Set_sembol(const Bitki,char*);
void delete_Bitki(const Bitki);







#endif