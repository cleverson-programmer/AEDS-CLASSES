#include <stdio.h>
#include <stdlib.h>

int main(){
    int n, soma = 0;
    printf("Digite um numero inteiro positivo: ");
    scanf("%d", &n);

    if (n < 0) {
        printf("Numero invalido. Por favor, insira um numero inteiro positivo.\n");
        return 1;
    }

    for(int i = 0; i <= n; i++){

        if(i % 3 == 0 && i % 5 == 0){
            continue;
        }
        if(i % 3 == 0 || i % 5 == 0){
            soma += i;
            printf("%d\n", i);
        }
    }

    printf("Soma: %d", soma);

    return 0;
}