#include <stdio.h>
#define MAX 50
#include <iostream>
#include <cstring>
#include <string>

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


  void consultaCPF(tPessoa v[]){
        string cpf; 
    int achou = 0;    
    printf("Digite o numero do CPF que deseja consultar: \n");
    //cin.ignore();
    scanf( "%s", cpf);
    for(int i = 0; i < 50; i++){
        if(cpf.compare(v[i].cpf)){
            printf("%s %s", v[i].nome, v[i].sexo);
            achou = 1;
        }
    }
        if(achou = 0){
            printf("%s nao encontrado", cpf);
        }
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
    //cin.ignore(); (aprender essa merda de cin)
    scanf( "%s", a[i].nome);

    cout << "cpf: ";
    //cin.ignore();
    scanf("%s", a[i].cpf);

    cout << "sexo: ";
    //cin.ignore();
    scanf("%s", a[i].sexo);

    cout << "altura: ";
    //cin.ignore();
    scanf("%s", a[i].altura);

    cout << "peso: ";
    //cin.ignore();
    scanf("%s", a[i].peso);


        }
        i++;
    }while(true);

    printf("%s", a[0].nome);
    printf("%s", a[0].altura);
    printf("%s", a[0].peso);
    printf("%s", a[0].sexo);

    consultaCPF(a);

   
    return 0;
}
  
 


