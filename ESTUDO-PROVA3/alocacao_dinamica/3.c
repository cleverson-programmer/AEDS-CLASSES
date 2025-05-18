// Leia número de linhas e colunas. Alocar dinamicamente uma matriz de inteiros, preencher, exibir e liberar memória.
//ESTRUTURA DESSA MATRIZ: SUPONDO QUE USUARIO DIGITE 2 LINHAS E 3 COLUNAS
// matriz → [ ponteiro A ] → [ 1 ][ 2 ][ 3 ]
//          [ ponteiro B ] → [ 4 ][ 5 ][ 6 ]

#include <stdio.h>
#include <stdlib.h>

int main(){
    int linhas, colunas;

    printf("Digite a quantidade de linhas:");
    scanf("%d", &linhas);

    printf("Digite a quantidade de colunas:");
    scanf("%d", &colunas);

    //Alocar vetor de ponteiros para linhas
    int **matriz = (int **) malloc(linhas * sizeof(int *));
    if(matriz == NULL){
        printf("Erro de alocação!\n");
        return 1;
    }

    //Aloca cada linha
    for(int i = 0; i < linhas; i++){
        matriz[i] = (int *) malloc(colunas * sizeof(int));
        if(matriz[i] == NULL){
            printf("Erro de alocação");
            return 1;
        }
    }

     // Preenche a matriz
    for (int i = 0; i < linhas; i++) {
        for (int j = 0; j < colunas; j++) {
            printf("Elemento [%d][%d]: ", i, j);
            scanf("%d", &matriz[i][j]);
        }
    }

    // Exibe a matriz
    printf("Matriz:\n");
    for (int i = 0; i < linhas; i++) {
        for (int j = 0; j < colunas; j++) {
            printf("%d ", matriz[i][j]);
        }
        printf("\n");
    }

    // Libera memória
    for (int i = 0; i < linhas; i++) {
        free(matriz[i]);
    }
    free(matriz);

    return 0;
}