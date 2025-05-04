#include <stdio.h>
#include <locale.h>


void troca_linha(int matriz[4][4]);

int main(){
    int matriz[4][4];
    setlocale(LC_ALL, "Portuguese");

    for(int i = 0; i < 4; i++){
        for(int j = 0; j < 4; j++){
            printf("Digite o valor da matriz na posição [%d][%d]: ", i,j);
            scanf("%d", &matriz[i][j]);
        }
    }

    troca_linha(matriz);
    return 0;

}

void troca_linha(int matriz[4][4]){
    int matrizR[4][4];

    for(int i = 0; i < 4; i++){
        for(int j = 0; j < 4; j++){
            matrizR[i][j] = matriz[3-i][j];//Tem que passar o último indice e não o tamanho da linha da matriz
        }
    }

    for(int i = 0; i < 4; i++){
        for(int j = 0; j < 4; j++){
            printf("%d ", matrizR[i][j]);
        }
        printf("\n");
    }
}