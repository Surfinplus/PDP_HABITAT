#include "Sinek.h"
#include "Bocek.h"



Sinek sinek_yarat(char* sembol, int deger ){
 
 
    Sinek sinek = (Sinek)malloc(sizeof(struct Sinek));
    sinek->superx = bocek_yarat(sembol,deger);
    sinek->sembol = sembol;
    sinek->superx->super->gorunum = &GORUnum;
    sinek->superx->super->set_sembol = &SET_Sembol;
    sinek->yoket = &delete_Sinek;
    return sinek;

}



char* GORUnum(const Sinek sinek){
    return sinek->sembol;
}



void* SET_Sembol(const Sinek sinek,char* sembol){
    sinek->sembol = sembol;
}



void delete_Sinek(const Sinek sinek){

    if(sinek==NULL) return;
    sinek ->superx->super->yoket(sinek->superx->super);// oluşturulan sinek için bocek yapısını da serbest bırakır
    free(sinek);




}










