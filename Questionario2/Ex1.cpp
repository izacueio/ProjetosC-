#include <stdio.h>
#define MAX 100
#define MIN 2
int main(void){

    int a;
    scanf("%d", &a); 
    int L[a];
    int aux = 0;
    int auxf = 0;

    for(int i = 0; i < a; i++){
        scanf("%d", &L[i]);
    }

    for(int i = 0; i < a; i++){
        for(int j = i+1; j < a; j++){
            if(L[i] >= L[j]){
                aux++;
            }else{
                auxf++;
            }
        }
            }       if(aux > auxf){
                    printf("falso");
            }else if(auxf > aux){
                    printf("verdadeiro");
            }
    return 0;
}
    


