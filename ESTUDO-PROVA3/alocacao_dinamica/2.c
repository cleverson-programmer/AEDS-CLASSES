#include <stdio.h>
#include <stdlib.h>
// Implemente um programa que leia um número indefinido de notas (floats), 
// usando realloc para aumentar dinamicamente o vetor conforme o usuário insere novas notas. 
// O programa termina quando o usuário digitar um número negativo. Mostre todas as notas e a média final. Libere a memória com free.


int main(){
    int qtd = 0;
    float *notas = NULL;
    float nota;

    while(1){
        printf("Digite a %d nota:", qtd + 1);
        scanf("%f", &nota);
        
        if( nota < 0){
            break;
        }

        float *temp = realloc(notas, (qtd + 1) * sizeof(float));
        if( temp == NULL){
            printf("Erro de alocação\n");
            free(notas);
            return 1;
        }
        notas = temp;
        notas[qtd] = nota;
        qtd++;

    }

    float soma = 0;
    for (int i = 0; i < qtd; i++) {
        soma += notas[i];
    }

    
    if (qtd > 0) {
        printf("Média das notas: %.2f\n", soma / qtd);
    } else {
        printf("Nenhuma nota foi inserida.\n");
    }

    free(notas);
    return 0;
}