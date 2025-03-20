#include <stdio.h>
#include <stdlib.h>

int main(){

    int n, soma = 0;
    printf("Digite um número inteiro positivo N: ");
    scanf("%d", &n);
    for(int i = 1; i < n; i++){
        if (n % i == 0){
            soma += i;
        }
    }
    if (soma == n){
        printf("O número %d é perfeito.\n", n);
    } else {
        printf("O número %d não é perfeito.\n", n);
    }
    return 0;
}