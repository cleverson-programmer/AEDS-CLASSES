//3. Contar números pares
// Escreva uma função int contarPares(int *vet, int n) que conte quantos elementos pares existem em um array.
#include <stdio.h>

int contarPares(int *vetor, int n){
    int count = 0;
    for( int i = 0; i < n ; i++){
        if (vetor[i] % 2 == 0){
            count ++;
        }
    }

    return count;
}
int main(){
    int n;
    int vetor[5];
    printf("Digite o tamanho do vetor: ");
    scanf("%d", &n);
    for(int i = 0; i < n; i++){
        printf("Digite o elemento %d: ", i + 1);
        scanf("%d", &vetor[i]);
    }
    int result = contarPares(vetor, n);

    printf("A quantidade de numeros pares é: %d", result);
}

// 8. Concatenar duas strings
// Faça uma função void concatena(char *dest, char *src) que concatene src no final de dest. Use apenas ponteiros, sem strcat.

// 10. Lista encadeada simples
// Implemente uma estrutura de lista encadeada com:

// Inserção de novo elemento (void inserir(Node **inicio, int valor)),

// Impressão dos elementos (void imprimir(Node *inicio)).