#include <stdio.h>

struct eletrodomestico{
    char nome[15];
    double potencia;
    double tempo;
};

double calculaConsumototal(eletrodomestico e[5], double tempo);
double porcentagem(double valorTotal, double valorParcial);

int main(){
    eletrodomestico eletrodomesticos[5];
    int tempoLigado;
    double consumo;
    double valorParcial;
    double porcentagemConsumo;

    for(int i = 0; i < 5;i++){
        scanf("%s", eletrodomesticos[i].nome);
        scanf("%lf %lf", &eletrodomesticos[i].potencia, &eletrodomesticos[i].tempo);
    }
    scanf("%d", &tempoLigado);

    consumo = calculaConsumototal(eletrodomesticos, tempoLigado);
    printf("%.2lf\n", consumo);

    for(int i = 0; i < 5; i++){
        valorParcial = eletrodomesticos[i].potencia * eletrodomesticos[i].tempo * tempoLigado;
        porcentagemConsumo = porcentagem(consumo, valorParcial);
        printf("%.2lf\n", porcentagemConsumo);
    }
}

double porcentagem(double valorTotal, double valorParcial){
    double auxiliarMultiplicacaoCruzada;
    double porcentagemValorParcial;
    int cem = 100;
    auxiliarMultiplicacaoCruzada = valorParcial * cem;
    porcentagemValorParcial = auxiliarMultiplicacaoCruzada / valorTotal;
    return porcentagemValorParcial;
}

double calculaConsumototal(eletrodomestico e[5], double tempo){
    double resultado = 0;
    for(int i = 0; i < 5; i++){
        resultado = resultado + e[i].potencia * e[i].tempo;
    }
    // printf("%lf", &resultado);
    return resultado * tempo;
}