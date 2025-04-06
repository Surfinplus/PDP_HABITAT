#include "Canli.h"
#include "Bitki.h"
#include "Bocek.h"
#include "Sinek.h"
#include "Pire.h"
#include "CanliX.h"
#include "Habitat.h"

    


 int* canli_dongu(int* canli1, int* canli2){

    if ((*(int*)canli1 <= 20 && *(int*)canli1 >= 10) && (*(int*)canli2 <= 20 && *(int*)canli2 >= 10)){
        if (*(int*)canli1 > *(int*)canli2){
            
            return canli1;
        }
            
        else if (*(int*)canli1 == *(int*)canli2){
            
            return canli1;
        }
            
         else if (*(int*)canli1 < *(int*)canli2){
            
            return canli2;
         }
            
        
    
    }

    if ((*(int*)canli1 <= 9 && *(int*)canli1 >= 1) && (*(int*)canli2 <= 9 && *(int*)canli2 >= 1)){
        if (*(int*)canli1 > *(int*)canli2){
            
            return canli1;
        }
            
        else if (*(int*)canli1 == *(int*)canli2){
            
             return canli1;
        }
           
        else if (*(int*)canli1 < *(int*)canli2){
            
            return canli2;
        }
            
    }

    if ((*(int*)canli1 <= 50 && *(int*)canli1 >= 21) && (*(int*)canli2 <= 50 && *(int*)canli2 >= 21)){
        if (*(int*)canli1 > *(int*)canli2){
            
             return canli1;
        }
           
        else if (*(int*)canli1 == *(int*)canli2){
            
            return canli1;
        }
            
        else if (*(int*)canli1 < *(int*)canli2){
            
            return canli2;
        }
            
    }
    
    if ((*(int*)canli1 <= 99 && *(int*)canli1 >= 51) && (*(int*)canli2 <= 99 && *(int*)canli2 >= 51)){
        if (*(int*)canli1 > *(int*)canli2){
            
            return canli1;
        }
            
        else if (*(int*)canli1 == *(int*)canli2){
            
            return canli1;
        }
            
        else if (*(int*)canli1 < *(int*)canli2){
            
            return canli2;
        }
                
    }

     if ((*(int*)canli1<=9 && *(int*)canli1>=1) && (*(int*)canli2<=99 && *(int*)canli2 >= 51)){
        
    return canli1;
     }
    

     if ((*(int*)canli1 <= 20 && *(int*)canli1 >= 10) && (*(int*)canli2<=9 && *(int*)canli2 >= 1)){
        
         return canli1;
     }
   

     if ((*(int*)canli1<=50 && *(int*)canli1 >=21) && (*(int*)canli2<=99 && *(int*)canli2 >= 51)){
        
         return canli1;
     }
    

     if ((*(int*)canli1<=9 && *(int*)canli1>=1) && (*(int*)canli2<=50 && *(int*)canli2 >=21)){
        
         return canli1;
     }
    

     if ((*(int*)canli1<=50 && *(int*)canli1 >=21) && (*(int*)canli2<=20 && *(int*)canli2 >= 10)){
        
         return canli1;
     }
    

     if ((*(int*)canli1 <= 20 && *(int*)canli1 >= 10) && (*(int*)canli2<=99 && *(int*)canli2 >= 51)){
        
         return canli1;
     }
    

     if ((*(int*)canli1<=99 && *(int*)canli1>=51) && (*(int*)canli2<=9 && *(int*)canli2 >= 1)){
        
        return canli2;
     }
    

     if ((*(int*)canli1<=9 && *(int*)canli1>=1) && (*(int*)canli2<=20 && *(int*)canli2 >= 10)){
        
        return canli2;
     }
  

     if ((*(int*)canli1<=99 && *(int*)canli1>=51) && (*(int*)canli2<=50 && *(int*)canli2 >=21)){
        
        return canli2;
     }
    

    if ((*(int*)canli1<=50 && *(int*)canli1 >=21) && (*(int*)canli2<=9 && *(int*)canli2 >= 1)){
        
        return canli2;
    }
    

     if ((*(int*)canli1 <= 20 && *(int*)canli1 >= 10) && (*(int*)canli2<=50 && *(int*)canli2 >=21)){
        
        return canli2;
     }
    

     if ((*(int*)canli1<=99 && *(int*)canli1>=51) && (*(int*)canli2<=20 && *(int*)canli2 >= 10)){
        
        return canli2;
     }
    
}




























Canli new_Canli(int value){
    Canli this;
    this = (Canli)malloc(sizeof(struct Canli));
    this->value = value;
    this->get_deger = &get_deger;
    this->yoket= &delete_Canli;
    return this;
}

int get_deger(const Canli this){
    return this->value;
}
void delete_Canli(Canli this){
    if(this==NULL) return;
    free(this);
}

char* gorunum_goster(const Canli this,void* p){
    int toplamUzunluk =100;
    toplamUzunluk += strlen(this->gorunum(p));
    char* str = (char*)malloc(sizeof(char)*toplamUzunluk+1);
    sprintf(str,"%s",this->gorunum(p));
    

    return str;
}