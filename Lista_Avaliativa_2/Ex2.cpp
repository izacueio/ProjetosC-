#include <stdio.h>
#include <stdlib.h>

int ciclo(int n);
    int a = 0;

int main(){

    int n;
    scanf("%d", &n);
    ciclo(n);
    printf("%d ", a+1);



}

int ciclo(int n){

    //printf("%d ", n);
    if(n > 1){
        if(n % 2 == 0){
            printf("%d ", n);
            n = n / 2;
            a++;
            ciclo(n);
        }else {
            printf("%d ", n);
            n = n * 3 + 1;
            a++;
            ciclo(n); 
        }

        }else { printf("1 ");
}
}