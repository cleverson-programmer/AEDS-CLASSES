#include <stdio.h>
#include <stdlib.h>

int main(){
    int folhas;
    float price = 0.25, total;

    printf("Digite o total de cópias desejadas:");
    scanf("%d", &folhas);

    if(folhas <= 0){
        printf("Número de cópias inválido.\n");
        return 1;
    }

    if(folhas > 100){
        price = 0.20;
        total = folhas * price;
        printf("O valor total é: R$ %.2f\n", total);
    } else{
        total = folhas * price;
        printf("O valor total é: R$ %.2f\n", total);
    }
    return 0;

}