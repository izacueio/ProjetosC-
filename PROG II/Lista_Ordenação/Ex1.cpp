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
        printf("Insira o nome e a quantidade de problemas resolvidos: ");
        scanf("%s %d", a[i].nome, &a[i].problemas);

    }

}

void imprimeReprovado(int n, alunos a[]){

    int i, j, x, l, k = 0;
    char y[MAX];



    if(a[k].problemas =! a[k+1].problemas){
    for(i = 1; i < n; i++){
        x = a[i].problemas;
        strcpy(y, a[i].nome);
        for(j = i - 1; j >= 0 && a[j].problemas < x; j--){
            a[j+1].problemas = a[j].problemas;
            strcpy(a[j+1].nome, a[j].nome);
                }
        a[j+1].problemas = x;       
        strcpy(a[j+1].nome, y); 
        }
    }else {
        for(k = 1; k < n; k++){
            strcpy(y, a[k].nome);
            for(l = k - 1; l >= 0 && strcmp(a[l].nome, a[k].nome) > 0; j--){
                strcpy(a[k].nome, a[l].nome);
            }
            strcpy(a[l+1].nome, y);        
            }
            
            }
        }


int main()
{

alunos a[DIM];

int i;
int n;
printf("Insira a quantidade de alunos: \n");
scanf("%d", &n);

leituraNomesPontuacao(n, a);
imprimeReprovado(n, a);


for(i = 0; i < n; i++){
    printf("%d %s ", a[i].problemas, a[i].nome);
}

return 0;

}

   
