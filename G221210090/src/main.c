#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Habitat.h"
#include "Bitki.h"
#include "Bocek.h"
#include "Pire.h"
#include "Sinek.h"
#include "Canli.h"
#include "CanliX.h"


int main() {

    int satir_sayisi = 0;
    int sutun_sayisi = 0;
    char *satir = NULL;
    size_t uzunluk = 0;
    char* dosya_ad = "Veri.txt";
   
    FILE *dosya = fopen(dosya_ad, "r");
    if (dosya == NULL) {
        printf("Dosya açılamadı.\n");
        exit(1);
    }

    while (getline(&satir, &uzunluk, dosya) != -1) {
        satir_sayisi++;

        // İlk satırın uzunluğunu kullanarak sütun sayısını belirle
        if (satir_sayisi == 1) {
            char* token = strtok(satir, " ");
            while (token != NULL) {
                sutun_sayisi++;
                token = strtok(NULL, " ");
            }
        }
    }

    // Dosyayı tekrar başa al
    fseek(dosya, 0, SEEK_SET);

     //  Habitat yapısı oluştur
    Habitat savana = new_Habitat(satir_sayisi, sutun_sayisi);

    

    //iki boyutlu int canli dizisi oluştur 
        int** canli_dizisix = malloc(satir_sayisi*sizeof(int*));
        for (int i =0;i<satir_sayisi;i++){
            canli_dizisix[i]=malloc(sutun_sayisi*sizeof(int));
        }
   
        for (int i = 0; i < satir_sayisi; i++) {
        for (int j = 0; j < sutun_sayisi; j++) {
            if (fscanf(dosya, "%d", &canli_dizisix[i][j]) != 1) {
                printf("Error reading file.\n");
                fclose(dosya);
                return 1;
                }
            }
        }
             for (int i = 0; i < satir_sayisi; i++) {
        for (int j = 0; j < sutun_sayisi; j++) {
            int sayi = canli_dizisix[i][j];
            if (sayi >= 1 && sayi <= 9) {
               savana->canli_dizisi[i][j] =  (Canli)bitki_yarat("B", sayi);
            } else if (sayi >= 10 && sayi <= 20) {
                savana->canli_dizisi[i][j] =  (Canli)bocek_yarat("C", sayi);
            } else if (sayi >= 21 && sayi <= 50) {
                savana->canli_dizisi[i][j] =   (Canli)sinek_yarat("S", sayi);
            } else if (sayi >= 51 && sayi <= 99) {
                savana->canli_dizisi[i][j] =  (Canli)pire_yarat("P", sayi);
            } else if(sayi=100) {
                savana->canli_dizisi[i][j]  = (Canli)CANLIX_yarat("X",sayi); // Geçersiz sayı
            }
            else{
                savana->canli_dizisi[i][j] = NULL;
            
            }
        }
    }


    int size = satir_sayisi * sutun_sayisi;
        int* sayili_dizi = (int*)malloc(size*sizeof(int));
        int index = 0;
        for(int i = 0; i < satir_sayisi;i++){
            for(int j =0;j<sutun_sayisi;j++){

            sayili_dizi[index++] = canli_dizisix[i][j];

            }
        }




    printf("\n");
    Habitat_yaz(savana);  
    printf("\n");  
     printf("Enter a bas...\n");
    getchar();
    system("cls");


        

        //sayilidizi ilk okuduğumuz canldizisix teki iki boyutlu int değerleri aktardığımız tek boyutlu dizi 
        //sayilidiziL ise sayili_dizi nin kopyasıdır. bunu da ölen canlıların kontrolünü sağlamak için kullanıyorum 

        int sizeL = satir_sayisi * sutun_sayisi;
        int* sayili_diziL = (int*)malloc(sizeL*sizeof(int));

        for(int i =0;i<size;i++){
            sayili_diziL[i]=sayili_dizi[i];
        }





        int* kazanan;
        int x ;
        kazanan = &sayili_dizi[0];
        int* arac;

      //asıl döngü
        for(int i=0;i<size;i++ ){//0 1 
            if(i+1==size) break;
           int* kaybeden = &sayili_dizi[i+1];//1 2 
            int anlik_kazanan =-1;
            
            for(int a =0;a<size;a++){
                if(&sayili_dizi[a] == kazanan){
                    anlik_kazanan = a;   
                }
            }
             
            arac = canli_dongu(kazanan,kaybeden);
            if(arac == kazanan){
                sayili_diziL[i+1]=100;

            }
            if(arac == kaybeden){
                sayili_diziL[anlik_kazanan] = 100;   
                kazanan = arac;


            }
                

        }
        

       //canlidizisix e sayilidiziL yi aktar
        int indexL=0;
        for(int i = 0; i < satir_sayisi;i++){
            for(int j =0;j<sutun_sayisi;j++){

            canli_dizisix[i][j] = sayili_diziL[indexL++];


            }
        }
     
     for (int i = 0; i < satir_sayisi; i++) {
        for (int j = 0; j < sutun_sayisi; j++) {
            int sayi = canli_dizisix[i][j];
            if (sayi >= 1 && sayi <= 9) {
               savana->canli_dizisi[i][j] =  (Canli)bitki_yarat("B", sayi);
            } else if (sayi >= 10 && sayi <= 20) {
                savana->canli_dizisi[i][j] =  (Canli)bocek_yarat("C", sayi);
            } else if (sayi >= 21 && sayi <= 50) {
                savana->canli_dizisi[i][j] =   (Canli)sinek_yarat("S", sayi);
            } else if (sayi >= 51 && sayi <= 99) {
                savana->canli_dizisi[i][j] =  (Canli)pire_yarat("P", sayi);
            } else if(sayi=100) {
                savana->canli_dizisi[i][j]  = (Canli)CANLIX_yarat("X",sayi); // Geçersiz sayı
            }
            else{
                savana->canli_dizisi[i][j] = NULL;
            
            }
        }
    }



  /* for(int i =0;i<sizeL;i++){

        printf("yazdizisa:%d \n",sayili_diziL[i]);
    }*/

   printf("\n");
    Habitat_yaz(savana);

     int kazanan_index = -1;

        for(int i = 0;i<size;i++){

            if(&sayili_dizi[i]==kazanan){

                kazanan_index = i;
                break;

            }

        }
       
        int kz;
        kz =*kazanan;

        if(kz>=1 && kz <=9)
        {
            Canli B =(Canli)bitki_yarat("B",kz);
           
            printf("Kazanan : %s :",B->gorunum);
        }
        else if(kz>=10 && kz<=20)
        {
             Canli C =(Canli)bocek_yarat("C",kz);
            printf("Kazanan : %s : ",C->gorunum);
        }
        else if(kz>=21 && kz <=50)
        {
            Canli S =(Canli)sinek_yarat("S",kz);
            printf("Kazanan : %s :",S->gorunum);
        }
        else if(kz>=51 && kz <=99)
        {
             Canli P =(Canli)pire_yarat("P",kz);
            printf("Kazanan : %s :",P->gorunum);
        }
        else
        printf(" Kazanan, %d \n", kz);
       

         if(kazanan_index!=-1){

            int row = kazanan_index / sutun_sayisi;
            int col = kazanan_index % satir_sayisi;
            //printf("Kazananin indis: %d \n",kazanan_index);
            printf("(%d,%d)",row,col);
            printf("\n");
        }else{
            printf("Kazanan bulunamadi.\n");
            
        }



    delete_Habitat(savana);

    fclose(dosya);
    free(sayili_dizi);
    free(satir);
    free(sayili_diziL);
    free(canli_dizisix);
   
    

    return 0;
}
