#include <stdio.h>
#define MAX 50
#include <iostream>
#include <cstring>

using namespace std;

//criando o registro dos dados da pessoa


struct tPessoa {
    string nome;
    string cpf;
    string altura;
    string peso;
    string imc;
    string sexo;
      

};


int main()
{
    struct tPessoa a[MAX];
    int i = 0;
    int cod;

//menu com do while para o programa identificar se é uma nova pessoa ou deseja sair 
    do{
        printf("1 - Cadastro nova Pessoa\n2- Sair\n");
        scanf("%d", &cod);
        if(cod == 2 || i > 49){
            break;
        }else if(cod == 1){ // se selecionar para cadastrar um novo aluno, abaixo le os dados 
    cout << "nome: "; 
    cin.ignore();
    getline( cin, a[i].nome);

    cout << "cpf: ";
    cin.ignore();
    getline( cin, a[i].cpf);

    cout << "sexo: ";
    cin.ignore();
    getline( cin, a[i].sexo);

    cout << "altura: ";
    cin.ignore();
    getline( cin, a[i].altura);

    cout << "peso: ";
    cin.ignore();
    getline( cin, a[i].peso);


        }
        i++;
    }while(true);

    void consultaCPF(int n, tPessoa v[], string cpf)

     { int achou = 0;    
    printf("Digite o numero do CPF que deseja consultar: \n");
    cin.ignore();
    getline( cin, a[i].cpf);
    for(int i = 0; i < 50; i++){
        if(strcmp(v[i].cpf, cpf)){
            printf("%s %s %s", v[i].nome, v[i].sexo);
            achou = 1;
        }
    }
        if(achou = 0){
            printf("%s não encontrado", cpf);
        }


    

    return 0;
   }
 }


