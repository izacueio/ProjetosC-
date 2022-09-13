#include <stdio.h>
#include <stdlib.h>

int conta(int n, int W[], int k);

int a = 0; // a quantidade de vezes que a função recursiva sera utilizada baseado no tamanho do vetor W.
int contador = 0; // variavel auxiliar para guardar quantas vezes o K aparece no vetor W.

int main(){

    
    int n, k;
    scanf("%d", &n);
    int W[n];
    for(int i = 0; i < n; i++){
        scanf("%d", &W[i]);
    }
    scanf("%d", &k);
    conta(n, W, k);

}


int conta(int n, int W[], int k){

    if(a < n){ //verifica se a que é o inicio das verificacoes é menor que o tamanho do vetor.
        if(W[a] == k){ //verifica se o vetor W na posicao a que é a primeira é igual a K.
            contador++; // se for igual, soma 1 no contador de vezes que K = W[A];
        }a++; // aumenta 1 em A e diminui o tamanho da distancia de repeticoes do tamanho do vetor
        conta(n, W, k); // executa recursivamente a funcao novamente.
    }else{
        printf("%d", contador); //imprime a quantidade de vezes que K apareceu no vetor
    }
}