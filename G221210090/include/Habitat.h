#ifndef HABITAT_H
#define HABITAT_H

#include "Canli.h"
#include "Bitki.h"

struct Habitat {
    Canli** canli_dizisi;
    int satir_sayisi;
    int sutun_sayisi;
};

typedef struct Habitat* Habitat;

Habitat new_Habitat(int, int);
void Habitat_yaz(const Habitat);
void delete_Habitat(Habitat);


#endif
