#include <stdio.h>
#include <locale.h>

//Imprimir cada linha de trás para frente
void espelho(int matriz[3][4]);

int main(){
    int matriz[3][4];

    for(int i = 0; i < 3; i++){ //Travando linha e percorrendo coluna
        for(int j = 0; j < 4; j++){
            printf("Digite o valor da matriz na posição [%d][%d]: ", i, j);
            scanf("%d", &matriz[i][j]);
        }
    }

    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 4; j++){
            printf("%d ", matriz[i][j]);
        }
        printf("\n");
    }

    espelho(matriz);

    return 0;
}

void espelho(int matriz[3][4]){
    int matrizR[3][4];
    printf("espelho\n");
    for(int i = 0; i < 3; i++){
        
        for(int j = 0; j < 4; j++){
            matrizR[i][j] = matriz[i][4 - 1 - j];//Como a matriz e tamanho fixo e estamos fixos na linha e percorrendo as colunas, podemos pegar sempre o último elemento da linha pelo indíce atual da coluna que estamos percorrendo EX: 0 1 2 3 --> 1°= 3 - 0= 3 elemento (último) 2°= 3-1 = 2 elemento (penultimo) ....
        }
        printf("\n");
    }

    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 4; j++){
            printf("%d ", matrizR[i][j]);
        }
        printf("\n");
    }

}