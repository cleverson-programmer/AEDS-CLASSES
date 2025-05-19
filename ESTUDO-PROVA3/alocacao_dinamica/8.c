//Usuário informando quantidade de linhas e colunas de matriz, alocando memória de forma dinâmica e salvando dados nessa matriz

//ESTRUTURA DESSA MATRIZ: SUPONDO QUE USUARIO DIGITE 2 LINHAS E 3 COLUNAS
// matriz → [ ponteiro A ] → [ 1 ][ 2 ][ 3 ]
//          [ ponteiro B ] → [ 4 ][ 5 ][ 6 ]

#include <stdio.h>
#include <stdlib.h>

int main(){

    int **matriz;   //ponteiro de ponteiros que representa uma matriz
    int linhas, colunas;

    //Solicita o tamanho da matriz
    printf("Digite o número de linhas: ");
    scanf("%d", &linhas);

    printf("Digite o número de colunas");
    scanf("%d", &colunas);

    //Aloca memoria para os ponteiros das linhas, quantidade de linhas EX: 2
    matriz = (int *) malloc(linhas * sizeof(int *));
    if(matriz == NULL){
        printf("Erro ao alocar memória para as linhas.\n");
        return 1;
    }

    //Aloca memoria para cada linha (cada vetor de colunas)
    //Para cada linha percorre o número de colunas e aloca memória para cada posição ex: [0][0] [0][1] etc...
    for(int i = 0; i < linhas; i++){
        matriz[i] = (int *) malloc(colunas * sizeof(int));
        if(matriz[i] == NULL){
            printf("Erro ao alocar memória para a linha %d.\n", i);
            return 1;
        }
    }

    //Preenchendo matriz
    printf("\nDigite os valores da matriz:\n");
    for (int i = 0; i < linhas; i++) {  //Travando linha
        for (int j = 0; j < colunas; j++) { //Percorrendo coluna
            printf("Elemento [%d][%d]: ", i, j);
            scanf("%d", &matriz[i][j]);
        }
    }

    // Impressão da matriz
    printf("\nMatriz:\n");
    for (int i = 0; i < linhas; i++) {
        for (int j = 0; j < colunas; j++) {
            printf("%d\t", matriz[i][j]);
        }
        printf("\n");
    }

    // Liberação da memória
    for (int i = 0; i < linhas; i++) {
        free(matriz[i]);
    }
    free(matriz);

    return 0;

}
