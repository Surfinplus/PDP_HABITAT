#ifndef CANLI_H
#define CANLI_H

#include "stdio.h"
#include "stdlib.h"
#include "string.h"

struct Canli{

    int value;
    
    char* (*gorunum)();//soyut metod
    void* (*set_sembol)();//soyut metod
    char* (*gorunum_goster)(struct Canli*,void*);
    int (*get_deger)(struct Canli*);
    void (*yoket)(struct Canli*);
       
};
typedef struct Canli* Canli;
Canli new_Canli(int);
int get_deger( Canli);
void delete_Canli( Canli);
char* gorunum_goster( Canli,void*);
int* canli_dongu(int*,int*);












#endif