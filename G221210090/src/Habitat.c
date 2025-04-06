#include "Habitat.h"
#include <stdio.h>
#include <stdlib.h>

Habitat new_Habitat(int satir, int sutun) {
    Habitat habitat = (Habitat)malloc(sizeof(struct Habitat));
    habitat->satir_sayisi = satir;
    habitat->sutun_sayisi = sutun;
    
    // İki boyutlu dizi oluştur
    habitat->canli_dizisi = (Canli**)malloc(satir * sizeof(Canli*));
    for (int i = 0; i < satir; i++) {
        habitat->canli_dizisi[i] = (Canli*)malloc(sutun * sizeof(Canli));
    }
    
    return habitat;
}

void Habitat_yaz(const Habitat habitat) {
    // Oluşturulan canlıları ekrana yazdır
    for (int i = 0; i < habitat->satir_sayisi; i++) {
        for (int j = 0; j < habitat->sutun_sayisi; j++) {
            if (habitat->canli_dizisi[i][j] != NULL) {
                printf("%s ", habitat->canli_dizisi[i][j]->gorunum);
            } else {
                printf("Bos ");
            }
        }
        printf("\n");
    }
}

    



void delete_Habitat(Habitat habitat) {
    if (habitat == NULL) return;
    
    // Bellekleri serbest bırak
    for (int i = 0; i < habitat->satir_sayisi; i++) {
        free(habitat->canli_dizisi[i]);
    }
    free(habitat->canli_dizisi);
    free(habitat);
}
