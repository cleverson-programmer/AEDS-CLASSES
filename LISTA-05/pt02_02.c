// Escreva um programa que preencha um vetor de tamanho 100 com os 100 primeiros números
// naturais que não são múltiplos de 6 e que não terminam com 6.
// Atenção: todas as 100 posições do vetor devem ser preenchidas

#include <stdio.h>

int main(){
    int vetor[100];
    int j = 0;
    for(int i = 0; j != 100; i++){
        if(i % 6 != 0 && i % 10 != 6){
            vetor[j] = i;
            j++;
        }
    }

    for(int i = 0;  i < 100; i++){
        printf("%d°:\t%d\n", i + 1, vetor[i]);
    }
}