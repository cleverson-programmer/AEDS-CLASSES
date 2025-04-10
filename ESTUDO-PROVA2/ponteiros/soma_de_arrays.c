#include <stdio.h>

int soma(int *vetor, int tamanho){
    int soma = 0;

    // Usamos i < tamanho porque vetores em C não têm um terminador automático (exceto strings, que usam '\0')
    for(int i = 0; i < tamanho; i++){
        //PODEMOS USAR A VERSÃO DE ARITMÉTICA DE PONTEIROS:
        //soma += *(vetor + i);
        soma += vetor[i];
    }

    return soma;
}

int main(){
    int vetor[] = {1,2,3,4,5};
    int tamanho = 5;

    printf("A soma é: %d", soma(vetor, tamanho));

    return 0;
}

//VERSÃO PEDINDO OS DADOS DO USUÁRIO E UTILIZANDO ARITMÉTICA DE PONTEIROS
// Função que recebe um ponteiro para o vetor e o tamanho
// int soma(int *vet, int n) {
//     int total = 0;

//     // Percorre o vetor usando ponteiros
//     for (int i = 0; i < n; i++) {
//         total += *(vet + i);  // soma o valor apontado
//     }

//     return total;
// }

// int main() {
//     int vetor[100], n;

//     // Solicita o tamanho do vetor
//     printf("Digite a quantidade de elementos do vetor: ");
//     scanf("%d", &n);

//     // Leitura dos elementos
//     for (int i = 0; i < n; i++) {
//         printf("Digite o elemento %d: ", i + 1);
//         scanf("%d", &vetor[i]);
//     }

//     // Chamada da função soma
//     int resultado = soma(vetor, n);

//     // Exibe o resultado
//     printf("A soma dos elementos do vetor é: %d\n", resultado);

//     return 0;
// }