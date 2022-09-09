/*Remove: Esta função recebe um vetor e um valor a ser removido nele (primeira
ocorrência).
Por exemplo, para os parâmetros [1,2, 1, 6, 8] e 1 o retorno será [2, 1, 6, 8].
*/
//izabella coelho - 201919020101

#include <stdio.h>
 
void remove(int n, int *v, int *dig);

int main(){
    int vetorA[5] = {1, 2, 1, 6, 8};
    int dig[5] = {0};
    remove(5, vetorA, dig);
    for(int i = 0; i < 5; i++){
        if(dig[i] != 0){
            printf("%i\n", dig[i]);
        }
    }
}
// nessa parte ele remove todos que são iguais a 1, não consegui fazer de uma maneira com que ele removesse apenas a primeira vez que o 1 aparece. 

void remove(int n, int *v, int *dig){
    if(n - 1 >= 0){
        if(v[n - 1] % 2 != 0){
            remove(n - 1, v, dig);
        }
        else{
            dig[n - 1] = v[n - 1];
            remove(n- 1, v, dig);         
        }
    }
}