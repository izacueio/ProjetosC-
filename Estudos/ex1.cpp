#include <stdio.h>
#define MAX 30

int temPrimo(int a, int vet[]){
    
    int i, contador = 0;
        for(i = 1; i <= a; i++){
            if(vet[a] % i == 0){
            contador++;
        }
    }
        if(contador == 2)
            return 1;
        else
            return 0;
}

int main(){

    
    int a;
    scanf("%d", &a);
    int vet[a];
    for(int i = 0; i < a; i++){
        scanf("%d", &vet[a]);
    }
    if(temPrimo(a, vet) == 0){
        printf("Sim");
    }else
         printf("Não");
 }

