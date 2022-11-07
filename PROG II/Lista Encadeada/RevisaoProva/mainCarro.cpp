#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#include "listaMC.h"


int main(){

    int op; //operação que o usuario deseja realizar
    char modelo[40]; //marca do carro
    float nota; //nota da marca
    int codigo; //codigo da marca
    int ano;

    marca *listaM = NULL; //ponteiro do primeiro nó da lista, lista vazia de marcas.
    carro *listaC = NULL; //ponteiro do primeiro nó da lista, lsita vazia de carros.

    //Criando a lista de operações com do-while.

    do{
        printf("\n1 - Cadastrar marca");
        printf("\n2 - Cadastrar carro");
        printf("\n3 - Listagem de carros");
        printf("\n4 - Exclusão de uma marca");
        printf("\n5 - Sair");
        printf("\nEscolha uma opcao:");
        scanf("%d", &op);

    //Chamando as funções corretas, criadas na listaMC.cpp

    if(op == 1){
        printf("Digite codigo e nota da marca: ");
        scanf("%d %f", &codigo, &nota);

        inserirM(listaM, codigo, nota);

        printf("Marca cadastrada com sucesso!");
        }
    else if(op == 2){
        printf("Digite o codigo da marca: ");
        scanf("%d", &codigo);
        nota = buscaMarca(listaM, codigo);
            if(nota = 0.0)
                printf("Marca nao encontrada.");
            else{
                printf("Digite o modelo do carro: ");
                scanf("%[^\n]", modelo);
                printf("Digite o ano do carro: ");
                scanf("%d", &ano);

                inserirC(listaC, modelo, ano, codigo);
                printf("Carro cadastrado com sucesso!");
            }
        
       }
    else if(op == 3){
        listagem(listaM, listaC);
        
       }
    else if(op == 4){
        printf("Codigo da marca: ");
        scanf("%d", &codigo);

        if(carroDeMarca(listaC, codigo) == 1){
            printf("Existe ao menos 1 carro cadastrado, marca não pode ser removida.");
        }else{
            removerM(listaM, codigo);
            printf("Marca removida com sucesso!\n");
        }
    }   
    }while(op != 5);
        desalocaCarro(listaC);
        desalocaMarca(listaM);
 }
