/*A potência de um número, escrita como x^n, envolve dois números: a base x e o expoente n. Quando n é um número natural maior do que 1, a potência indica a multiplicação da base a por ela mesma tantas vezes quanto indicar o expoente n.

Podemos calcular a potência x^n de uma maneira mais eficiente. Observe primeiro que se n é uma potência de 2 então x^n pode ser computada usando sequências de quadrados. Por exemplo, x^4 é o quadrado de x^2 e assim x^4 pode ser computado usando somente duas multiplicações ao invés de três. Esta técnica pode ser usada mesmo quando n não é uma potência de 2, usando a seguinte fórmula:*/



#include <stdio.h>
#include <stdlib.h>

int pot(int a, int n){

    if(n == 0)
        return 1;
    else
        return a * pot(a, n-1);

}
int main(){

    int a, n;

    scanf("%d%d", &a, &n);

    printf("%d\n", pot(a,n));

    return 0;

}
