#ifndef CANLIX_H
#define CANLIX_H
#include "Canli.h"

struct CANLIX
{
    Canli super;
    char* sembol; //Varsayılan sembol eğer girilmezse bu sembol kullanılacak
    //ancak eğer bu sembol kullanılmıyorsa girilmeyince tekrar kontrol sağlanacak
    void (*yoket)(struct CANLIX*);

};

typedef struct CANLIX* CANLIX;
CANLIX CANLIX_yarat(char*, int);
char* GORUNUM(const CANLIX);
void* SET_SEMBOL(const CANLIX,char*);
void delete_CANLIX(const CANLIX);







#endif