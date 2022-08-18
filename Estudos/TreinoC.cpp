// este é um espaço para estudos independentes


#include <stdio.h>
#define MAX 5

int main(){

    float notas[MAX] = {0};
    float total = 0;
    float media = 0;

    printf("Insira 5 notas:\n");

    for(int i = 0; i < MAX; i++){
        scanf("%f", &notas[i]);
    }
    for (int i = 0; i < MAX; i++){
        total+= notas[i];

        media = total/5;

    
    }
            printf("a media e %.2f", media);
        return 0;
 }

