#ifndef BOCEK_H
#define BOCEK_H

#include "Canli.h"

struct Bocek{

    Canli super;
    char* sembol; //Varsayılan sembol eğer girilmezse bu sembol kullanılacak
    //ancak eğer bu sembol kullanılmıyorsa girilmeyince tekrar kontrol sağlanacak
    void (*yoket)(struct Bocek*);  //Yok etme işlemi






};

typedef struct Bocek* Bocek;
Bocek bocek_yarat(char*, int);
char* GOrunum(const Bocek);
void* SEt_sembol(const Bocek,char*);
void delete_Bocek(const Bocek);





#endif