#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#define MAX 9

int main()
{
    int  cpf1[11], soma, qtde, i, j, resto;
    char resp;

    srand(time(NULL));
    do{
        printf("******************** GERADOR DE CPF ********************\n\n");
        do{
           printf("Deseja gerar quantos CPFs seguidos? <MAX 99>:\t");
           scanf("%d", &qtde);
        }while(qtde > 99 || qtde < 1);
        printf("\n");

        for(j = 0; j < qtde; j++){
           soma = 0;
           for(i = 0; i < 9; i++){
               cpf1[i] = (rand() % MAX);
               soma += cpf1[i] * (10 - i);
           }
           resto = 11 - (soma % 11);
           if(resto > 9)
                resto = 0;
           cpf1[9] = resto;

           soma = 0;
           for(i = 0; i < 10; i++){
                soma += cpf1[i] * (11 - i);
           }

           resto = 11 - (soma % 11);
           if(resto > 9) {
                resto = 0;
           }
           cpf1[10] = resto;

           printf("CPF %d:\t  ", j + 1);
           for(i = 0; i < 11; i++)
           {
               if(i == 3 || i == 6)
                   printf(".");
               if(i == 9)
                   printf("-");
               printf("%d", cpf1[i]);
           }
           printf("\n");

        }
        printf("\n\n");
        do{
           fflush(stdin);
           printf("Deseja fazer novamente? <s/n>:\t");
           scanf("%c", &resp);
        }while(resp != 's' && resp != 'S' && resp ! = 'n' && resp != 'N');
        if(resp == 's' || resp == 'S')
            printf("\n_______________________________________________________\n\n\n");
    }while(resp == 's' || resp == 'S');
    getch();
}
