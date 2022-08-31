/*Construa uma estrutura tAluno com número de matrícula, 
nome (com até 30 caracteres) e curso (com até 30 caracteres), 
nesta ordem. 
Leia do usuário as informações de 5 alunos e armazene em vetor dessa estrutura. 
Em seguida, leia um nome de curso, pesquise e liste todos os alunos (a matrícula e nome) que fazem o curso..*/

#include <stdio.h>
#define DIM 100
#define MAX 30
#include<stdlib.h>
#include<string.h>

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
		printf(" matricula : ");
		scanf(" %d", &alunos[i].matricula);
		printf(" nome: ");
		scanf(" %[^\n]", alunos[i].nome);
		printf(" curso: ");
		scanf(" %[^\n]", alunos[i].curso);
		
	}
}

// funcao para realizar a busca
void consulta(tAluno alunos[])
{
	int i;
	//int achou = 0;	// sem alunos
	for (i = 0; i < 5; i++){
		    printf("%s\n%d\n", alunos[i].nome, alunos[i].matricula);
		//if (strcmp(&alunos[i].curso, &alunos.curso) == 0);
		//	printf("%s\n%d\n", alunos[i].nome, alunos[i].matricula);
		//	achou = 1;
		}return;
	}
	


int main()
{

	tAluno alunos[DIM];

	// chamada da funcao leitura
	leitura(alunos);
    consulta(alunos);

	/*do {
        scanf(" %[^\n]", alunos[i].curso);
		consulta(alunos);
		
	}while(alunos[i].curso =! 0);
    */return 0;
	
} 
