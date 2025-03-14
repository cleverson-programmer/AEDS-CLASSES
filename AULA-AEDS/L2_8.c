#include <stdio.h>
#include <stdlib.h>

int main(){
    float tempo, velocidade;
    char caracter;
    printf("Digite o tempo em ms: ");
    scanf("%f", &tempo);
    printf("Digite o caracter: ");
    scanf(" %c", &caracter);
    if(tempo < 0){
        printf("Tempo invalido\n");
        return 1;
    }
    switch(caracter){
        case 't':
            velocidade = 9.8 * (tempo / 1000);
            printf("Velocidade em m/s: %.4f\n", velocidade);
            break;
        case 'v':
            velocidade = 8.87 * (tempo / 1000);
            printf("Velocidade em m/s: %.4f\n", velocidade);
            break;
        case 'm':
            velocidade = 3.7 * (tempo / 1000);
            printf("Velocidade em m/s: %.4f\n", velocidade);
            break;
        default:
            printf("Caracter invalido\n");
            return 1;
    }
}