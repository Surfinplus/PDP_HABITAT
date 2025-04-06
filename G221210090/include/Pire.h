#ifndef PIRE_H
#define PIRE_H
#include "Canli.h"
#include "Bocek.h"


struct Pire {

    Bocek superx;
    char* sembol; //Varsayılan sembol eğer girilmezse bu sembol kullanılacak
    //ancak eğer bu sembol kullanılmıyorsa girilmeyince tekrar kontrol sağlanacak
    void (*yoket)(struct Pire*); // burda belki sıkıntı olabilir gözden geçir



};

typedef struct Pire* Pire;
Pire pire_yarat(char*, int);
char* GORunum(const Pire);
void* SET_sembol(const Pire,char*);
void delete_Pire(const Pire);








#endif