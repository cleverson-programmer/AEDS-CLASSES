// Escreva um programa para preencher um vetor com 20 vinte valores inteiros (os valores podem
// ser lidos do teclado ou gerados automaticamente). Em seguida, o sistema deve solicitar ao
// usuário um valor, que deve ser pesquisado no vetor. Imprima as posições do vetor que armazena
// o valor informado

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void valores(int vetor[], int n);

int main(){
    int vetor[20];
    int n;

    srand(time(0));

    for(int i = 0; i < 20; i++){
        vetor[i] = rand() % 100;
    }

    for(int i = 0; i < 20; i++){
        printf("%d\n", vetor[i]);
    }

    printf("Digite um valor:");
    scanf("%d", &n);
    
    valores(vetor, n);

}

void valores(int vetor[], int n){

    for(int i = 0; i < 20; i++){
        if(vetor[i] == n){
            printf("%d ", i);
        }
    }
}