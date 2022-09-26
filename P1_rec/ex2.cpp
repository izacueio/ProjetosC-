
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define DIM 100
#define MAX 50

//registro dos produtos
struct tipoProdutos{
	char nome[MAX+1];
	float valor;
    int quantidadeDisp;
};

void leitura(tipoProdutos produtos[], int m, int n);

	int a = 0;
	int c = 0;


// funcao para leitura dos produtos
void leitura(tipoProdutos produtos[], int n)
{
	if(a < n){
		for (int i = 0; i < n; i++) 
	{
		scanf(" %[^\n]", produtos[i].nome);
		scanf("%1f", &produtos[i].valor);
		}
	}a++;
	leitura(produtos, n);
}

//funcao separada para ler o que ela deseja comprar
void lerProdutosCompra(tipoProdutos compra[], int b){

	if (c < b){
		for(int i = 0; i < b; i++)
		{
			scanf(" %[^\n]", compra[i].nome);
			scanf("%d", &compra[i].quantidadeDisp);
		}

	}c++;
	lerProdutosCompra(compra, b);
}



int main()
{

	tipoProdutos produtos[DIM];
	tipoProdutos compra[DIM];

	int m; //quantidade de vezes que foi a feira
	int n; // quantidade de itens disponiveis na feira
	int b; // quantidade de itens que quer comprar

	scanf("%d", m);
	for(int i = 0; i < m; i++){
	scanf("%d", &n);
	leitura(produtos, n);
	scanf("%d", &b);
	lerProdutosCompra(compra, b);

	//calculo do valor total, comparando o nome do produto 

	double valorTotal = 0;
		for(int i = 0; i < m; i++){
			 if (strcmp(compra[i].nome, produtos[i].nome) == 0 ){
				valorTotal = compra[i].quantidadeDisp * produtos[i].valor;
				}
			}printf("%.2f", valorTotal);
		}	

	return 0;
}

