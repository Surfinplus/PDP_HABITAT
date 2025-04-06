#include "Bocek.h"

Bocek bocek_yarat(char* sembol, int deger ){
    Bocek bocek = (Bocek)malloc(sizeof(struct Bocek));
    bocek->super = new_Canli(deger);
    bocek->sembol = sembol;
    bocek->super->gorunum = &GOrunum;
    bocek->super->set_sembol = &SEt_sembol;
    bocek->yoket = &delete_Bocek;
    return bocek;

}


char* GOrunum(const Bocek bocek){
    return bocek->sembol;
}

void* SEt_sembol(const Bocek bocek,char* sembol){
    bocek->sembol = sembol;
}

void delete_Bocek(const Bocek bocek){
    if(bocek==NULL) return;
    bocek ->super->yoket(bocek->super);// oluşturulan bocek için canlı yapısını da serbest bırakır
    free(bocek);

}

