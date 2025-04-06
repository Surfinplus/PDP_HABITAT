#ifndef SINEK_H
#define SINEK_H
#include "Canli.h"
#include "Bocek.h"



struct Sinek {

    Bocek superx;
    char* sembol; //Varsayılan sembol eğer girilmezse bu sembol kullanılacak
    //ancak eğer bu sembol kullanılmıyorsa girilmeyince tekrar kontrol sağlanacak
    void (*yoket)(struct Sinek*); // burda belki sıkıntı olabilir gözden geçir
    

};


typedef struct Sinek* Sinek;
Sinek sinek_yarat(char*, int);
char* GORUnum(const Sinek);
void* SET_Sembol(const Sinek,char*);
void delete_Sinek(const Sinek);












#endif