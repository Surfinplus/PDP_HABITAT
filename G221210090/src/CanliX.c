#include "CanliX.h"
 
CANLIX CANLIX_yarat(char* sembol, int deger){
    CANLIX canli = (CANLIX)malloc(sizeof(struct CANLIX));
    canli->super = new_Canli(deger);
    canli->sembol = sembol;
    canli->super->gorunum = &GORUNUM;
    canli->super->set_sembol = &SET_SEMBOL;
    canli->yoket = &delete_CANLIX;
    return canli;
}


char* GORUNUM(const CANLIX canli){
    return canli->sembol;
}

void* SET_SEMBOL(const CANLIX canli,char* sembol){
    canli->sembol = sembol;
}

void delete_CANLIX(const CANLIX canli){
    if(canli==NULL) return;
    canli ->super->yoket(canli->super);// oluşturulan canlix için canlı yapısını da serbest bırakır
    
    free(canli);

}