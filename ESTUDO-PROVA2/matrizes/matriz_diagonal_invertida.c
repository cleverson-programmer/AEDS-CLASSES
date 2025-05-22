//REGRA DA DIAGONAL INVERTIDA: Se a matriz é de ordem n (EX: 3X3), então a diagonal invertida está nos elementos matriz[i][n - 1 - i]

/*
int n = 3;
for (int i = 0; i < n; i++) {
    printf("%d ", matriz[i][n - 1 - i]);
}
*/

/*
1   2   3
4   5   6
7   8   9
*/

/*
3 (posição [0][2])
5 (posição [1][1])
7 (posição [2][0])
*/

#include <stdio.h>
#include <stdlib.h>

void diagonal_invertida(int linhas, int colunas, int matriz[linhas][colunas]);

int main(){
    int colunas;
    int linhas;

    printf("Digite a quantidade de linhas: ");
    scanf("%d", &linhas);

    printf("Digite a quantidade de colunas: ");
    scanf("%d", &colunas);

    int matriz[linhas][colunas];

    printf("Preencha a matriz\n");

    for(int i = 0; i < linhas; i++){
        for(int j = 0; j < colunas; j++){
            printf("Matriz[%d][%d]: ", i,j);
            scanf("%d", &matriz[i][j]);
        }
    }

    diagonal_invertida(linhas, colunas, matriz);

    return 0;
}

void diagonal_invertida(int linhas, int colunas, int matriz[linhas][colunas]){
    for (int i = 0; i < linhas; i++) {
        printf("%d ", matriz[i][colunas - 1 - i]);
    }
}


