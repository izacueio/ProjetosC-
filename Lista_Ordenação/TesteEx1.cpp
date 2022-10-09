#include <stdio.h>
#define MAX 20
#define DIM 100
#include <string.h>

struct alunos{
    char nome[MAX+1];
    int problemas;
};


//alunos a[MAX];

void leituraNomesPontuacao(int n, alunos a[])
{
    for(int i = 0; i < n ; i++)
    {
        //printf("Insira o nome e a quantidade de problemas resolvidos: ");
        scanf("%s %d", a[i].nome, &a[i].problemas);

    }

}

void imprimeReprovado(int n, alunos a[]){

    int i, j, x;
    char y[MAX];


    for(i = 1; i < n; i++){
        x = a[i].problemas;
        strcpy(y, a[i].nome);
        for(j = i-1; j >= 0 && a[j].problemas < x; j--){
            a[j+1].problemas = a[j].problemas;
            strcpy(a[j+1].nome, a[j].nome);
                }
        a[j+1].problemas = x;       
        strcpy(a[j+1].nome, y); 
    }

    for(i = 1; i < n; i++){
        x = a[i].problemas;
        strcpy(y, a[i].nome);
        for(j = i - 1; j >= 0 && a[j].problemas == x && (strcmp(y,a[j].nome) < 0); j--){
            strcpy(a[j+1].nome, a[j].nome);
        }
        strcpy(a[j+1].nome, y);
    }


  }



int main()
{

alunos a[DIM];


int i;
int n;
char d[MAX];

//printf("Insira a quantidade de alunos: \n");
scanf("%d", &n);

leituraNomesPontuacao(n, a);
imprimeReprovado(n, a);

for(i = 0; i < n; i++){
printf("%s ", a[i].nome);
}


return 0;

    }


   
