//MAXIMO DIVISOR COMUM

#include <stdio.h>

int divisorcomum(int a, int b){

    if(a%b == 0){

        return b;
    }else {

        return divisorcomum(b, (a%b));
    }

}

int main (){

    int a, b, resultado;

    scanf("%d %d", &a, &b);
    resultado = divisorcomum(a,b);
    printf("%d", resultado);
    printf("\n");

    return 0;

}
