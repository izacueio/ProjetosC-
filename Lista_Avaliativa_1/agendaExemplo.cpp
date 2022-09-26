#include <stdio.h>
#define DIM 100
#define MAX 50
/* Recebe um inteiro positivo n e n nomes, telefones e datas de
aniversário, recebe uma data de consulta e mostra os nomes
e telefones das pessoas que aniversariam nesta data */

struct tipoData{
	int dia;
	int mes;
	int ano;	
};

struct tipoAgenda{
	char nome[MAX+1];
	int telefone;
	tipoData aniver;
};


// funcao para leitura do vetor
void leitura(int n, tipoAgenda agenda[])
{
	for (int i = 0; i < n; i++) 
	{
		printf("\nAmigo(a): %3d\n", i+1);
		printf(" Nome : ");
		scanf(" %[^\n]", agenda[i].nome);
		printf(" Telefone : ");
		scanf("%d", &agenda[i].telefone);
		printf(" Aniversário: ");
		scanf("%d/%d/%d", &agenda[i].aniver.dia, &agenda[i].aniver.mes,
		&agenda[i].aniver.ano);
	}
}

// funcao para realizar a busca
int consulta(tipoData data, int n, tipoAgenda agenda[])
{
	int i;
	int achou = 0;	// nao foram encontrados aniversariantes
	for (i = 0; i < n; i++){
		if (agenda[i].aniver.dia == data.dia && agenda[i].aniver.mes == data.mes)
		{
			printf("%-50s %8d\n", agenda[i].nome, agenda[i].telefone);
			achou = 1;
		}
	}
	return achou; // se achou algum compromisso naquela data especifica
}


int main()
{
	tipoAgenda agenda[DIM];
	int i, n;
	tipoData data;

	printf("Informe a quantidade de amigos: ");
	scanf("%d", &n);
	
	// chamada da funcao leitura
	leitura(n, agenda);

	printf("\nInforme uma data (dd/mm) -- (00/00 para encerrar): ");
	scanf("%d/%d", &data.dia, &data.mes);
	while( data.dia != 0 && data.mes != 0){
		if(consulta(data, n, agenda) == 0)
			printf("Nenhum aniversariante foi encontrado.\n");
		
		printf("\nInforme uma data (dd/mm) -- (00/00 para encerrar): ");
		scanf("%d/%d", &data.dia, &data.mes);
	}
	
	return 0;
}



