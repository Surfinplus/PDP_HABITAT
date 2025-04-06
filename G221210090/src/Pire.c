#include "Pire.h"
#include "Bocek.h"

//bence boceğin superini bilmesi için içeri aktarmalıyız 

Pire pire_yarat(char* sembol, int deger){

    Pire pire = (Pire)malloc(sizeof(struct Pire));
    pire->superx = bocek_yarat(sembol,deger);
    pire->sembol=sembol;
    pire->superx->super->gorunum = &GORunum;
    pire->superx->super->set_sembol = &SET_sembol;
    pire->yoket = &delete_Pire;
    return pire;
    

}

char* GORunum(const Pire pire){
    return pire->sembol;
}

void* SET_sembol(const Pire pire,char* sembol){
    pire->sembol = sembol;
}

void delete_Pire(const Pire pire){
    if(pire==NULL) return;
    pire ->superx->super->yoket(pire->superx->super);// oluşturulan pire için bocek yapısını da serbest bırakır
    free(pire);

}