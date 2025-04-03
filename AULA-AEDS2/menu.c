#include <stdio.h>

void menu(){
    printf("Escolha qual operação:\n");
    printf("1- Soma:\n");
    printf("2- Subtração: \n");
    printf("3- Multiplicação: \n");
    printf("4- Divisão: \n");
}

int soma(int n1, int n2){
    return printf("%d + %d = %d", n1, n2, n1 + n2);
}

int subtracao(int n1, int n2){
    return printf("%d - %d = %d", n1, n2, n1 - n2);
}

int multiplicacao(int n1, int n2){
    return printf("%d * %d = %d", n1, n2, n1 * n2);
}

int divisao(int n1, int n2){
    return printf("%d / %d = %d", n1, n2, n1 / n2);
}

int main(){
    int opcao, n1, n2;

    printf("Digite um numero: ");
    scanf("%d", &n1);
    printf("Digite o segundo numero: ");
    scanf("%d", &n2);

    menu();
    scanf("%d", &opcao);

    switch(opcao){
        case 1:
            soma(n1, n2);
            break;
        case 2:
            subtracao(n1, n2);
            break;
        case 3:
            multiplicacao(n1, n2);
            break;
        case 4:
            divisao(n1, n2);
            break;
    }

    return 0;
}

//PROCEDIMENTO --> É UMA FUNÇÃO QUE NÃO TEM RETORNO