#include <stdio.h>

int matrizLinha();

int main(){
    int matriz[2][3]; //2 linhas e 3 colunas
    //Vai preencher em colunas
    /*
    1 3 5
    2 4 6
    */

    //TRAVAR A LINHA PREENCHE EM LINHAS --> Linha fixa e percorre coluna
    //TRAVAR A COLUNA PREENCHE EM COLUNAS --> Coluna fixa e percorre linha


    for (int j = 0; j < 3; j++) {         // colunas
        for (int i = 0; i < 2; i++) {     // linhas
            printf("Digite o valor para matriz[%d][%d]: ", i, j);
            scanf("%d", &matriz[i][j]);
        }
    }

    printf("Matriz:\n");
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 3; j++) {
            printf("%d ", matriz[i][j]);
        }
        printf("\n");
    }

    printf("LINHAS");
    matrizLinha();

    return 0;
}

int matrizLinha() {
    int matriz[2][3]; //2 linhas e 3 colunas
    //Vai preencher em linha
    /*
    1 2 3
    4 5 6
    */
    for (int i = 0; i < 2; i++) {         // de 0 até 1 (2 linhas)
        for (int j = 0; j < 3; j++) {     // de 0 até 2 (3 colunas)
            printf("Digite o valor para matriz[%d][%d]: ", i, j);
            scanf("%d", &matriz[i][j]);
        }
    }

    printf("Matriz:\n");
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 3; j++) {
            printf("%d ", matriz[i][j]);
        }
        printf("\n");
    }

    return 0;
}