// Implemente um procedimento preencheValores que preencha um vetor X de 10 elementos. Na
// sequência, faça um procedimento copiaNegativos que receba um vetor preenchido, teste e copie
// todos os valores negativos deste vetor para um novo vetor, sem deixar elementos vazios entre os
// valores copiados. O vetor contendo números negativos deve conter até 10 elementos - após o
// último número negativo (caso não existam 10 número negativos) o vetor deve conter o número
// 0. Faça um programa (main) que acione os procedimentos e imprima o vetor de números
// negativos, sem imprimir o valor zero

#include <stdio.h>
#include <time.h>

void preencher(int vetor[], int length);
void copiarNegativos(int vetor[], int length);

int main(){
    int vetor[10];
    int tamanho = sizeof(vetor) / sizeof(vetor[0]);
    preencher(vetor, tamanho);


    return 0;
}

void preencher(int vetor[], int length){

    srand(time(0));

    for(int i = 0; i < length; i++){
        //Numeros aleatorios entre -20 e +20
        vetor[i] = (rand() % 41) -20;
    }

    printf("\nVetor INICIAL\n");
    for(int i = 0; i < length; i++){
        printf("%d\n", vetor[i]);
    }

    copiarNegativos(vetor, length);
}

void copiarNegativos(int vetor[], int length){
    int vetorNeg[length];
    int j = 0;
    for(int i = 0; i < length; i++){
        if(vetor[i] < 0){
            vetorNeg[j] = vetor[i];
            j++;
        }
    }

    if(j != 9){
        vetorNeg[j] = 0;
    }

    printf("\nVetor negativo\n");
    for(int i = 0; i != j + 1; i++){
        printf("%d ", vetorNeg[i]);
    }

}