#include <stdio.h>
#include <math.h>

// Crie uma função que receba um número float e um ponteiro para float, e armazene o quadrado do número no ponteiro.

void quadrado(float n, float *ptr);

int main(){
    float n, ptr;

    printf("Digite o valor de N:");
    scanf("%f", &n);

    quadrado(n, &ptr);
    printf("%.2f", ptr);

    return 0;
}

void quadrado(float n, float *ptr){
    *ptr = n * n;
}