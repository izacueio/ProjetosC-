#include<stdio.h>
#include<stdlib.h>
#include<string.h>

/*tipo para marca*/

struct marca{

    int codigo; 
    float nota;
    struct marca* prox;

};

/*tipo para carro*/

struct carro{

    char modelo[40];
    int ano;
    int codigo;
    struct carro* prox;    
};

void inserirM(marca*&, int, float);

float buscaMarca(marca* M, int);

void inserirC(carro*&, char*, int, int);

void listagem(marca* , carro*);

void removerM(marca*&, int);

void desalocaMarca(marca*&);

void desalocaCarro(carro*&);

int carroDeMarca(carro*, int);