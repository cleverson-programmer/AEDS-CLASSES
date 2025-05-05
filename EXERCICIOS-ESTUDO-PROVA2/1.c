#include <stdio.h>

// Escreva uma função que receba dois inteiros por referência, troque seus valores entre si e mostre o resultado na função principal.

void trocar(int *a, int *b);

int main(){
    int a,b;

    printf("Digite o valor de A:");
    scanf("%d", &a);
    printf("Digite o valor de B:");
    scanf("%d", &b);

    trocar(&a, &b);

    return 0;
}

void trocar(int *a, int *b){
    int temp = 0;
    temp = *a;
    *a = *b;
    *b = temp;
    printf("O valor de A: %d\nO valor de B: %d", *a, *b);
}