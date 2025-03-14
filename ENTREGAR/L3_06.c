#include <stdio.h>
#include <stdlib.h>

int main(){

    do{
        int opcao;
        printf("Escolha uma das opções do menu:\n 1- Novo Salario\n 2-Ferias\n 3-Decimo Terceiro\n 4-Sair\n");
        scanf("%d", &opcao);
        switch(opcao){
            case 1: {
                float salario, percentual;
                printf("Digite o salario: ");
                scanf("%f", &salario);
                if(salario <= 999.99){
                    percentual = 0.15;
                    printf("Novo salario: %.2f\n", salario + (salario * percentual));
                }
                else if(salario > 1000 && salario < 2000){
                    percentual = 0.10;
                    printf("Novo salario: %.2f\n", salario + (salario * percentual));
                }
                else if(salario >= 2000){
                    percentual = 0.05;
                    printf("Novo salario: %.2f\n", salario + (salario * percentual));
                }
                break;
            }
            case 2: {
                float salario;
                printf("Digite o salario: ");
                scanf("%f", &salario);
                printf("Ferias: %.2f\n", salario + (salario / 3));
                break;
            }
            case 3: {
                float salario, meses;
                printf("Digite o salario: ");
                scanf("%f", &salario);
                printf("Digite o numero de meses trabalhados: ");
                scanf("%f", &meses);
                if(meses < 0 || meses > 12){
                    printf("Meses invalidos\n");
                    break;
                }
                printf("Decimo terceiro: %.2f\n", (salario / 12) * meses);
                break;
            }
            case 4: {
                printf("Saindo do programa...\n");
            }
            default: {
                printf("Opcao invalida! Tente novamente.\n");
                break;
            }
        }
    } while(1);

    return 0;
}