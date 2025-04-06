#include "Bitki.h"
// bitkinin sembolünü sen oluştururken vericeksin eğer bu işe yaramazsa gorunumden return B yapmayı dene 
Bitki bitki_yarat(char* sembol, int deger){
    Bitki bitki = (Bitki)malloc(sizeof(struct Bitki));
    bitki->super = new_Canli(deger);
    bitki->sembol = sembol;
    bitki->super->gorunum = &Gorunum;
    bitki->super->set_sembol = &Set_sembol;
    bitki->yoket = &delete_Bitki;
    return bitki;
}


char* Gorunum(const Bitki bitki){
    return bitki->sembol;
}

void* Set_sembol(const Bitki bitki,char* sembol){
    bitki->sembol = sembol;
}

void delete_Bitki(const Bitki bitki){
    if(bitki==NULL) return;
    bitki ->super->yoket(bitki->super);// oluşturulan bitki için canlı yapısını da serbest bırakır
    
    free(bitki);

}