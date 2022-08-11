/* PROGRAMA LE 5 NOTAS, CALCULA A MEDIA ARITMETICA ENTRE ELAS,
CALCULA QUANTAS NOTAS ESTAO ACIMA E ABAIXO DA MEDIA*/
#include <stdio.h> 

int main()
{
   int i, menor, maior;
   float nota[5], soma, media;

   // leitura
   for (i = 0; i < 5; i++)
      scanf("%f", &nota[i]);

   soma = 0.0;
   for (i = 0; i < 5; i++)
         soma = soma + nota[i];
   
   // calculo da media
   media = soma / 5;

   // inicializacao de variaveis
   menor = 0;
   maior = 0;

   for (i = 0; i < 5; i++) 
   { 
      if (nota[i] < media)
         menor++;
      if (nota[i] > media)
         maior++;
   }
   printf("\n%2.2f %d %d\n", media, menor, maior); 
   return 0;
}