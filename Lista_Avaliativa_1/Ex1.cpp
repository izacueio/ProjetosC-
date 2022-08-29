/* Faça um programa para simular uma agenda de compromissos e:
 • Crie e leia um vetor de 5 estruturas de dados com: compromisso (máximo 60 letras) e data, nesta ordem. A data deve ser outra estrutura de dados contendo dia, mês e ano. 
• Leia dois inteiros M e A e mostre todos os compromissos do mês M do ano A. Repita o procedimento até ler M = 0.
Dica: utilize  scanf("%d/%d/%d", &variavel_dia, &variavel_mes, &variavel_ano); para leitura formatada da data.*/

#include <stdio.h>
#define DIM 100
#define MAX 60

struct tipoData{
	int dia;
	int mes;
	int ano;	
};

struct tipoCompromissos{
	char nome[MAX+1];
	tipoData a;
};


// funcao para leitura do vetor
void leitura(tipoCompromissos compromissos[])
{
	for (int i = 0; i < 5; i++) 
	{
		printf(" Compromisso : ");
		scanf(" %[^\n]", compromissos[i].nome);
		printf(" Data do Compromisso: ");
		scanf("%d/%d/%d", &compromissos[i].a.dia, &compromissos[i].a.mes,
		&compromissos[i].a.ano);
	}
}

// funcao para realizar a busca
int consulta(tipoData a, tipoCompromissos compromissos[])
{
	int i;
	int achou = 0;	// nao foram encontrados compromissos
	for (i = 0; i < 5; i++){
		if (compromissos[i].a.mes == a.mes && compromissos[i].a.ano == a.ano)
		{
			printf("%s\n", compromissos[i].nome);
			achou = 1;
		}
	}
	return achou;
}


int main()
{

	tipoCompromissos compromissos[DIM];
	//int n;
    //int i;
	tipoData a;

	//printf("Informe o compromissos: ");
	//scanf("%d", &n);

	// chamada da funcao leitura
	leitura(compromissos);
    //scanf("%d/%d", &a.mes, &a.ano);
    /*for(int i = 0; i < n; i++){
        if(consulta(data, n, compromissos) == 0)
			printf("Nenhum compromisso achado.\n");
        scanf("%d/%d", &data.mes, &data.ano);
    }
    /*while(data.mes != 0 && data.ano != 0){
		if(consulta(data, n, compromissos) == 0)
			printf("Nenhum compromisso achado.\n");
        scanf("%d/%d", &data.mes, &data.ano);
    }*/

	do {
        scanf("%d/%d", &a.mes, &a.ano);
		consulta(a, compromissos);
			//printf("Nenhum compromisso achado.\n");
		    //printf("\nInforme uma data (dd/mm) -- (00/00 para encerrar): ");
	}while(a.mes != 0 && a.ano != 0);

    return 0;
	
}



