// . Escreva um programa que leia da entrada padrão 5 números reais, que devem ser armazenados
// em um arranjo. Em seguida, gere outro arranjo, cujos valores correspondem ao dobro dos
// respectivos elementos do primeiro arranjo.

#include <stdio.h>

int main(){
    int vetor[5];
    
    for(int i = 0; i < 5; i++){
        printf("Digite o %d° numero: ", i + 1);
        scanf("%d", &vetor[i]);
    }

    int dobro[5];

    for(int i = 0; i < 5; i++){
        dobro[i] = vetor[i] * 2;
    }

    for(int i = 0; i < 5; i++){
        printf("Dobro: %d\n", dobro[i]);
    }

    return 0;
}