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

// 5. Multiplicação de vetor por escalar
// Crie uma função void multiplicaEscalar(int *vet, int n, int escalar) que multiplica cada elemento do vetor por um número, usando apenas ponteiros e laços.

// 6. Inverter um vetor
// Escreva uma função void inverter(int *vet, int n) que inverta os elementos do vetor no próprio vetor usando ponteiros.

// 7. Alocação dinâmica e média
// Crie uma função que use malloc para alocar um vetor de n posições, leia n valores do usuário e calcule a média.

// 8. Concatenar duas strings
// Faça uma função void concatena(char *dest, char *src) que concatene src no final de dest. Use apenas ponteiros, sem strcat.

// 9. Função que preenche e imprime matriz
// Crie duas funções:

// void preencher(int **mat, int lin, int col) para preencher a matriz dinamicamente.

// void imprimir(int **mat, int lin, int col) para exibir.

// Utilize ponteiros para ponteiros (int **), alocação dinâmica com malloc, e laços de repetição.

// 10. Lista encadeada simples
// Implemente uma estrutura de lista encadeada com:

// Inserção de novo elemento (void inserir(Node **inicio, int valor)),

// Impressão dos elementos (void imprimir(Node *inicio)).