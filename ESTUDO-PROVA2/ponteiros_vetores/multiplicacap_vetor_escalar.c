// 5. Multiplicação de vetor por escalar
// Crie uma função void multiplicaEscalar(int *vet, int n, int escalar) que multiplica cada elemento do vetor por um número, usando apenas ponteiros e laços.

#include <stdio.h>

void multiplicaEscalar(int *vetor, int n, int tamanho){

    for(int i = 0; i < tamanho; i++){
        vetor[i] = vetor[i] * n;
    }

}

int main(){
    int n;
    int vetor[] = {1,2,3,4,5};
    printf("Digite o número multiplicador:");
    scanf("%d", &n);

    int tamanho = sizeof(vetor) / sizeof(vetor[0]);
    multiplicaEscalar(vetor, n, tamanho);
    for(int i = 0; i < tamanho ; i++){
        printf("%d\n",vetor[i]);
    }

    return 0;
}

//OUTRA SOLUÇÃO COMPLETA

// void multiplicaEscalar2(int *vet, int n, int escalar) {
//     for (int i = 0; i < n; i++) {
//         *(vet + i) = *(vet + i) * escalar;
//     }
// }

// int teste() {
//     int vetor[] = {1, 2, 3, 4, 5};
//     int escalar;

//     printf("Digite o número multiplicador: ");
//     scanf("%d", &escalar);

//     //Calcula o tamanho do vetor. 
//     //sizeof(vetor) --> retorna o tamanho total do vetor em bytes, EX: 5 elementos inteiros cada inteiro tem 4 bytes: 5 x 4 = 20 bytes
//     //sizeof(vetor[0]) --> retorna o tamanho do primeiro elemento do vetor, como só podemos declarar valores do tipo que definimos no vetor, todos vão ser o mesmo tamanho.
//     //EX: 20 / 4 = 5; ONDE 20 É O TAMANHO TOTAL E 4 É O TAMANHO DE UM ELEMENTO DO VETOR QUE NO CASO É INTEIRO.
//     int tamanho = sizeof(vetor) / sizeof(vetor[0]);
//     multiplicaEscalar2(vetor, tamanho, escalar);

//     for (int i = 0; i < tamanho; i++) {
//         printf("%d\n", vetor[i]);
//     }

//     return 0;
// }