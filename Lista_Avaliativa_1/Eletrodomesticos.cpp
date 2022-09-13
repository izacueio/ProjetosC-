/*Faça um programa que controla o consumo de energia dos eletrodomésticos de uma casa e:
• Crie e leia 5 eletrodomésticos que contém nome (máximo 15 letras), potência (real, em kW) e tempo ativo por dia (real, em horas).
• Leia um tempo t (em dias), calcule e mostre o consumo total na casa e o consumo relativo de cada eletrodoméstico (consumo/consumo total) nesse período de tempo. Apresente este último dado em porcentagem.

Dica: utilize %.2f para impressão dos valores reais com duas casas decimais.*/


#include <stdio.h>
#define MAX 15
#define DIM 100

double soma = 0;
struct Tipoeletrodomesticos {

    char nome[MAX+1];
    double pot = 0;
    double tempo = 0;
};

double leitura(Tipoeletrodomesticos eletrodomesticos[]){

    for(int i = 0; i < 5; i++){
        //printf("Insira o primeiro eletrodomestico! ");
        printf("Nome: ");
        scanf(" %[^\n]", eletrodomesticos[i].nome);
        printf("Potencia em KW: ");
        scanf("%f", &eletrodomesticos[i].pot);
        printf("Tempo Ativo: ");
        scanf("%f", &eletrodomesticos[i].tempo);
    }
}

double calculaConsumo(Tipoeletrodomesticos eletrodomesticos[5], int n){
    
    double soma;
    //int valorConsumoIndividual[5];
    for(int i = 0; i < n; i++){
        //valorConsumoIndividual[i] ++;
        soma++;
    }

}

int main(){

    Tipoeletrodomesticos eletrodomesticos[DIM];

    leitura(eletrodomesticos);

    int n;
    printf("Insira o numero em dias de consumo: ");
    scanf("%d", &n);
    calculaConsumo(eletrodomesticos, n);
    printf("%.2f", soma);

}