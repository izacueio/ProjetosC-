#include <stdio.h>
#include <stdlib.h>
#define MAX 12

//achar o menor numero de um vetor usando recursividade

int maior(int v[], int tamanho, int a){
    if(tamanho == 0)
        return v[a];
    else{
        if(v[tamanho-1] < v[a])
            return maior(v, tamanho - 1, tamanho -1);
        else
            return maior(v, tamanho - 1, a);
    }



}


int main (){

    int vet[MAX] = {2,0,1,9,1,9,0,2,0,1,0,1};

    printf("O menor numero do RGA e: %d\n", maior(vet, 12, 0)); 

}

