#include <stdio.h>
#define MAX 100

void insercao(int n, int v[MAX]){


    int i, j, x;

    for(i = 1; i < n; i++){
        x = v[i];
            for(j = i - 1; j >= 0 && v[j] > x; j--){
                v[j+1] = v[j];
                }
        v[j+1] = x;
    } 
    
}

int main(){

    int n;

    scanf("%d", &n);
    int v[n];
    for (int i = 0; i < n; i++){
        scanf("%d", &v[i]);
    }
    insercao(n, v);

    for(int i = 0; i < n; i++){
        printf("%d ", v[i]);
    }


    return 0;

}

