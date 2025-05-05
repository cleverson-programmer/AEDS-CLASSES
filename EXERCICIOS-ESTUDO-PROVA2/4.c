#include <stdio.h>

int maior(int matriz[3][3]);

int main(){
    int matriz[3][3];

    for(int i = 0; i < 3; i++){ //Trava linha
        printf("%d° linha", i + 1);
        for(int j = 0; j < 3; j++){
            printf("Digite o valor da posição [%d][%d]:", i,j);
            scanf("%d", &matriz[i][j]);
        }
        printf("\n"); //Espaçamento entre blocos de linhas
    }

    printf("O maior é: %d", maior(matriz));

    return 0;

}

int maior(int matriz[3][3]){
    int value = 0;

    for(int i = 0; i < 3; i++){ //Trava linha
        for(int j = 0; j < 3; j++){
            if(matriz[i][j] > value){
                value = matriz[i][j];
            }
        }
    }

    return value;
}