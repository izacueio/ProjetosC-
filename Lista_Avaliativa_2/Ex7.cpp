// escreva um algoritmo que receba um inteiro qualquer e retorne o piso desse LogN na base 2

#include <stdio.h>
#include <stdlib.h>

int piso_log2(int n);
    int a = 0;

int main(){

    int n;
    scanf("%d", &n);
    piso_log2(n);

    return 0;
}

int piso_log2(int n){
   // int a = 0;
        if(n >= 2){
            n = n/2;
            a++;
            piso_log2(n);
        }else {
            printf("%d", a);
        
        }
}