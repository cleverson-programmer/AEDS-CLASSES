// Escreva um programa que receba do usuário dois vetores, A e B, com 10 números inteiros cada.
// Crie um novo vetor, C, calculando C = A - B. Mostre na tela os dados do vetor C.

#include <stdio.h>
#include <time.h>

int main(){
    int a[10], b[10], c[10];

    srand(time(0));

    for(int i = 0; i < 10; i++){
        a[i] = rand() % 100;
        b[i] = rand() % 100;
    }

    for(int i = 0; i < 10; i++){
        c[i] = a[i] - b[i];
    }

    for(int i = 0; i < 10; i++){
        printf("%d\t%d\n", a[i], b[i]);
    }


    for(int i = 0; i < 10; i++){
        printf("%d ", c[i]);
    }

    return 0;
}