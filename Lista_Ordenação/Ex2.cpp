#include <stdio.h>
#define MAX 20
#define DIM 100

struct numeros{

    int x;
};


void leituraNumeros(int n, numeros a[])
{
    for(int i = 0; i < n ; i++)
    {
        scanf("%d", &a[i].x);

    }

}

void OrdenaNumeros(int n, numeros a[]){

    int i, j, x;


    for(i = 1; i < n; i++){
        x = a[i].x;
        for(j = i-1; j >= 0 && a[j].x < x; j--){
            a[j+1].x = a[j].x;
                }
        a[j+1].x = x;       
    }


  }



int main()
{

numeros a[DIM];


int i;
int n;

scanf("%d", &n);

leituraNumeros(n, a);
OrdenaNumeros(n, a);

for(i = 0; i < n; i++){
printf("%d ", a[i].x);
}


return 0;

    }


   
