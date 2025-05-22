#include <stdio.h>
#include <locale.h>

void quadrado(int matriz[3][3]);
void quadrado2(int matriz[3][3]);

int main(){
    setlocale(LC_ALL, "Portuguese");
    int matriz[3][3];

    for(int i = 0; i < 3; i++){ //Linha, percorre coluna
        for(int j = 0; j < 3; j++){
            printf("Digite o valor da matriz na posição: [%d][%d]: ", i, j);
            scanf("%d", &matriz[i][j]);
        }
    }

    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            printf("%d ", matriz[i][j]);
        }
        printf("\n");
    }

    printf("Matriz quadrado da diagonal\n");
    quadrado(matriz);
    quadrado2(matriz);

    return 0;
}

void quadrado(int matriz[3][3]){
    int vetor[3];
    int matrizR[3][3];

    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            matrizR[i][j] = matriz[i][j];
            if(i == j){
                vetor[i] = matriz[i][j] * matriz[i][j];
                matrizR[i][j] = vetor[i];
            }
        }
        printf("\n");
    }

    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            printf("%d ", matrizR[i][j]);
        }
        printf("\n");
    }
}

void quadrado2(int matriz[3][3]){

    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            if(i == j){
                printf("%d", matriz[i][j] * matriz[i][j]);
            }
        }
        printf("\n");
    }
}