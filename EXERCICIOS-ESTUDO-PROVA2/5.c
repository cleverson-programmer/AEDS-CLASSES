#include <stdio.h>

// Implemente uma função que preencha um vetor de inteiros com valores fornecidos pelo usuário e use ponteiros para acessar os elementos.

void preecher(int *vetor, int tamanho);
void imprimir(int *vetor, int tamanho);

int main(){
    int n;
    printf("Digite a quantidade de itens:");
    scanf("%d", &n);
    int vetor[n];
    int tamanho = sizeof(vetor) / sizeof(vetor[0]);

    preecher(vetor,tamanho);
    imprimir(vetor, tamanho);

    return 0;
}

void preecher(int *vetor, int tamanho){
    for(int i = 0; i < tamanho; i++){
        printf("Digite o %d° valor:", i + 1);
        scanf("%d", &vetor[i]);
    }
}

void imprimir(int *vetor, int tamanho){
    printf("Vetor: ");
    for (int i = 0; i < tamanho; i++) {
        printf("%d ", *(vetor + i));    //Pega o valor percorrendo a posição do vetor
    }
    printf("\n");
}