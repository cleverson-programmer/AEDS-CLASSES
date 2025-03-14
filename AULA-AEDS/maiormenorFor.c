#include <stdio.h>
#include <stdlib.h>

int main(){
    int num, limit = 5;
    int menor, maior = 0;

    for(int i = 0; i < limit; i++){
        printf("Digite o %d numero: ", i + 1);
        scanf("%d", &num);
        if(num < menor) menor = num;
        if(num > maior) maior = num;
    }

    printf("O menor numero digitado foi: %d\n", menor);
    printf("O maior numero digitado foi: %d\n", maior);
    return 0;
}