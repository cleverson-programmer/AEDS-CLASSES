#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(){
    int n,quadrado =0;
    printf("Digite um número inteiro positivo N: ");
    scanf("%d", &n);

    quadrado = sqrt(n);
    if( pow(quadrado, 2) == n){
        printf("O número %d é um quadrado perfeito.\n", n);
    } else {
        printf("O número %d não é um quadrado perfeito.\n", n);
    }
}