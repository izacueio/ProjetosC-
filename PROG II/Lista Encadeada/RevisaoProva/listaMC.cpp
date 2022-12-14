#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#include "listaMC.h"


//Inserir no final da lista

void inserirM(marca*& lista, int codigo, float nota){

    //1º passo: Ponteiro do tipo struct que aponta para o primeiro nó da lista. Ponteiro auxiliar.
    marca *p; //ponteiro para percorrer a lista.
    marca *novo; // ponteiro que aponta para o primeiro nó da lista.

    //2º passo: Alocar memória
    novo = (marca*) calloc(1, sizeof(marca)); //o sistema aloca 1 espaço na memória do tipo struct "marca"
    novo->codigo = codigo; // código que o usuário vai inserir
    novo->nota = nota; // nota que o usuário vai inserir

    //3º passo: Checar se será uma inserção em uma lista vazia.
    if(lista == NULL)
        lista = novo;
    else{
        p = lista;
        while(p->prox != NULL)
            p = p->prox;
        p->prox = novo;
    }
}

//Função busca e mostra a nota de uma marca, consultando pelo seu código. 
float buscaMarca(marca* M, int codigo) 
{
    while(M!= NULL)
    {
        if(M->codigo == codigo)
            return M->nota;

        M = M->prox; //caso não seja igual, ele pula pro próximo nó.
    }

    return 0.0; // retorna 0.0 quando não tem nenhuma marca com o código consultado. 
}


//função do tipo pilha para inserir um novo carro.
void inserirC(carro*& lista, char* modelo, int ano, int codigo){
// função recebe por referência o primeiro nó da lista, recebe o nome do modelo digitado pelo usuário, recebe o ano e o codigo. 

    //1º passo: criar um ponteiro auxliar
    carro *novo;

    //2º passo: alocar memoria

    novo = (carro*) calloc(1, sizeof(carro));
    //como ele só pode ser cadastrado usando uma marca que já exista. Devemos copiar a marca. 
    strcpy(novo->modelo, modelo);
    novo->ano =  ano;
    novo->codigo = codigo;

    novo->prox = lista;
    lista = novo;

}

//Função para listar todos os carros e marcas. 
void listagem(marca* listaM, carro* listaC){

    //1º passo: Criar um ponteiro auxiliar e uma variavel para guardar a nota
    carro *p;
    float nota;

    //2º passo: percorrer a lista de carros

    p = listaC;
    while(p!= NULL){
        nota = buscaMarca(listaM, p->codigo);
        printf("%s %d %.1f\n", p->modelo, p->ano, nota);
        
    //3º passo: continuar percorrendo a lista até que p seja nulo. 

    p = p->prox;

    }

}

// função para remover uma marca, mas só pode remover se não tiver nenhum carro cadastrado com essa marca, para manter a integridade do codigo
void removerM(marca*& listaM, int codigo){

    //1º passo: Criar um ponteiro auxiliar anterior e posterior para remover. 

    marca* ant, * ptr;

    ant = NULL; // ponteiro anterior
    ptr = listaM; //primeiro nó da lista
    
    //lógica = enquanto o primeiro ponteiro é diferente de nulo, ou seja não é o ultimo nó, e o codigo é diferente do código da marca que deseja deletar, ele continua procurando. 
    while(ptr!= NULL && ptr->codigo!= codigo){
    ptr = ptr->prox;
    }

    //caso o ptr chegue no ultimo nó, significa que o PTR ficou "nulo", ou sejam marca não existe para ser deletada.
    if(ptr = NULL){
        printf("Marca nao cadastrada.\n");
    }//se o ptr não for nulo e o codigo procurado para ser deletado foi achado, então segue:
    else{
        if(ant == NULL)// remoção do primeiro NÓ. Caso o valor a ser deletado seja o primeiro da lista
            listaM = listaM->prox;
        else
            ant->prox = ptr->prox;
        
        free(ptr);
    }

}

void desalocaMarca(marca*& listaM){

    marca *aux;

    while(listaM!= NULL){

        aux = listaM;
        listaM = aux->prox;

        free(aux);
    }
}

void desalocaCarro(carro*& listaC){

    carro *aux;

    while(listaC!= NULL){

        aux = listaC;
        listaC = aux->prox;

        free(aux);
    }
}

//função que define se há um carro em uma marca para q a integridade dos dados seja mantida

int carroDeMarca(carro* listaC, int codigo){

    carro* p = listaC; // lista de todos os carros

    while(p!=NULL){
        if(p->codigo == codigo)
        return 1; //há carros cadastrados nessa marca, ela não pode ser excluida.

        p = p->prox;
    }

    return 0; //não há carros cadastrados nessa marca, significa que a marca pode ser excluida

}