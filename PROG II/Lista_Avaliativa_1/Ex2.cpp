/*Construa uma estrutura tAluno com número de matrícula, 
nome (com até 30 caracteres) e curso (com até 30 caracteres), 
nesta ordem. 
Leia do usuário as informações de 5 alunos e armazene em vetor dessa estrutura. 
Em seguida, leia um nome de curso, pesquise e liste todos os alunos (a matrícula e nome) que fazem o curso..*/

#include <stdio.h>
#define DIM 100
#define MAX 50
#include<stdlib.h>
#include<string.h>
#include<conio.h>

struct tAluno{
	int matricula;
	char nome[MAX+1];
	char curso[MAX+1];	
};

// funcao para leitura do vetor
void leitura(tAluno alunos[])
{
	for (int i = 0; i < 5; i++) 
	{
		//printf(" matricula : ");
		scanf(" %d", &alunos[i].matricula);
		//printf(" nome: ");
		scanf(" %[^\n]", alunos[i].nome);
		//printf(" curso: ");
		scanf(" %[^\n]", alunos[i].curso);
		
	}
}

// funcao para realizar a busca
int consulta(tAluno alunos[])
{
	int i;
	int achou = 0;	// sem alunos
	for (i = 0; i < 5; i++){
		if(strcmp(alunos[i].curso, alunos[i].curso) == 0)
		{
		printf("%d %s", &alunos[i].matricula, alunos[i].nome);
		achou = 1;
		}
	}
		return achou;
}
	


int main()
{

	tAluno alunos[DIM];
	int i;
	// chamada da funcao leitura
	leitura(alunos);
    	scanf(" %[^\n]", alunos[i].curso);
		consulta(alunos);
	return 0;
}
