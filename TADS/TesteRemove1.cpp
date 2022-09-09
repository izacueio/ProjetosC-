/*Remove: Esta função recebe um vetor e um valor a ser removido nele (primeira
ocorrência).
Por exemplo, para os parâmetros [1,2, 1, 6, 8] e 1 o retorno será [2, 1, 6, 8].
*/


#include <stdio.h>
 
void remove(int n, int *v, int *dig);

int main(){
    int vetorA[5] = {1, 2, 1, 6, 8};
    int dig[5] = {0};
    remove(20, vetorA, dig);
    for(int i = 0; i < 5; i++){
        if(dig[i] != 0){
            printf("%i\n", dig[i]);
        }
    }
}

void remove(int n, int *v, int *dig){
    if(n - 1 >= 0){
        if(v[n - 1] % 2 != 0){
            remove(n - 1, v, dig);
        }
        else{
            pares[n - 1] = v[n - 1];
            // printf("%i", pares[n - 1]);
            remove(n- 1, v, dig);         
        }
    }
}