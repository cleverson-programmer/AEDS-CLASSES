//Implemente um procedimento preencheValores que preencha 2 vetores X e Y, com 10
// elementos cada com valores aleatórios entre 10 e 20. Implemente um procedimento que receba
// os dois vetores previamente preenchidos e gere um novo vetor Z com os elementos desses 2
// vetores intercalados de tal forma que nas posições ímpares do novo vetor estejam os elementos
// do primeiro vetor e nas posições pares os elementos do segundo vetor recebido por parâmetro.
// Faça um procedimento que receba e exiba o conteúdo de um vetor. Implemente um programa
// que faça as devidas declarações e acione os módulos para exemplificar o seu uso.

#include <stdio.h>
#include <stdlib.h>
#include <time.h>


void preencherValores(int x[], int y[], int tamanho);
void intercala(int x[], int y[], int tamanho);
void exibir(int z[], int tamanho);

int main(){
    int x[10], y[10];

    int tamanho = sizeof(x) / sizeof(x[0]);

    preencherValores(x, y, tamanho);

    return 0;
}

void preencherValores(int x[], int y[], int tamanho){

    //comando para gerar numeros aleatorios
    srand(time(0));

    for(int i = 0; i < tamanho; i++){
        x[i] = rand() % 11 + 10;    //10 a 20
        y[i] = rand() % 11 + 10; 
    }

    intercala(x, y, tamanho);
}

void intercala(int x[], int y[], int tamanho){
    int z[20];

    for(int i = 0; i < tamanho; i ++){
            z[2 * i] = x[i]; //Pares 0,2,4
            z[ 2 * i + 1] = y[i];//impares 1,3,5
    }

    exibir(z, 20);
}

void exibir(int z[], int tamanho){
    for(int i = 0; i < tamanho; i++){
        printf("%d ", z[i]);
    }
}



