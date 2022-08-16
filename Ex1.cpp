#include <stdio.h>
#define MAX 50
#include <iostream>
#include <cstring>

using namespace std;

//criando o registro dos dados do aluno 

struct alunoMatNome {
    string nome;
    string matricula;
    string nota1;
    string nota2;  

};

calculoMedia(double media){

}


int main()
{
    struct alunoMatNome a[MAX];
    int i = 0;
    int cod;

//menu com do while para o programa identificar se é um novo aluno ou deseja sair 
    do{
        printf("1 - Cadastro novo Aluno\n2- Sair\n");
        scanf("%d", &cod);
        if(cod == 2 || i > 49){
            break;
        }else if(cod == 1){ // se selecionar para cadastrar um novo aluno, abaixo le os dados 
    cout << "nome: "; 
    cin.ignore();
    getline( cin, a[i].nome);

    cout << "matricula: ";
    cin.ignore();
    getline( cin, a[i].matricula);

    cout << "nota1: ";
    cin.ignore();
    getline( cin, a[i].nota1);

    cout << "nota2: ";
    cin.ignore();
    getline( cin, a[i].nota2);
        }
        i++;
    }while(true);

// após capturar todos os dados, calculo da média das notas de todos os alunos inseridos





    return 0;
}


