#include <stdio.h>
#include <stdlib.h>

int main(){

    float value;
    char letter;

    printf("Digite o valor do produto: ");
    scanf("%f", &value);

    printf("Digite a inicial do estado do produto: MG | SP | RJ | ES");
    scanf(" %c", &letter);

    switch(letter){
        case 'M':
            value += value * 0.07;
            printf("Valor: %.2f", value);
            break;
        case 'S':
            value += value * 0.12;
            printf("Valor: %.2f", value);
            break;
        case 'R':
            value += value * 0.15;
            printf("Valor: %.2f", value);
            break;
        case 'E':
            value += value * 0.08;
            printf("Valor: %.2f", value);
            break;
        default:
            printf("Valores invalidos");
    }
}