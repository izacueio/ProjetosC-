#include <stdio.h>
#define MAX 20
#define DIM 100

struct alunos{
    char nome[MAX+1];
    int problemas;
};

void leituraNomesPontuacao(int n, alunos a[])
{
    for(int i = 0; i < n ; i++)
    {
        printf("Insira o nome: ", i+1);
        scanf(" %[^\n]", a[i].nome);
        printf("Insira a quantidade de problemas resolvidos: \n");
        scanf("%d", &a[i].problemas);

    }

}

void imprimeReprovado(int n, alunos a[]){

    int i, j, aux;

    for(i = 0; i < n; i++){
       for(j = i+1; j < n; j++){
            if(a[i].problemas >  a[j].problemas){
                aux = a[i].problemas;
                a[i].problemas = a[j].problemas;
                a[j].problemas = aux;

            }
       }
    }
    for(int i = 0; i < n; i++){
        printf("%s", a[i].nome);
    }
}



int main()
{

alunos a[DIM];

int n;
printf("Insira a quantidade de alunos: \n");
scanf("%d", &n);

leituraNomesPontuacao(n, a);
imprimeReprovado(n, a);

/*for(int i = 0; i < n; i++){
    printf("%d", a[i].problemas);
}*/

return 0;

}

   
