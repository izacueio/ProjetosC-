#include <stdio.h>
#include <stdlib.h>

int temPrimo(int n, int W[]);

int a = 0; 
int contador = 0;
int contaprimos = 0;

int main(){

    
    int n;
    scanf("%d", &n);
    int W[n];
    for(int i = 0; i < n; i++){
        scanf("%d", &W[i]);
    }
    temPrimo(n, W);

    if(contaprimos > 0){
        printf("Sim");
    }else
        printf("Nao");

}


int temPrimo(int n, int W[]){

    if(a < n){
            for(int i = 0; i < a; i++){ 
                if(W[a] % (a+1) == 0){
                contador++; 
                }
            }if(contador == 2){
                contaprimos++;
        }a++;
        temPrimo(n, W); 
    }
}