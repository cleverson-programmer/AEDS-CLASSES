#include <stdio.h>
#include <locale.h>

void matrizMult(int matriz[2][3]);

//TRAVAR A LINHA PREENCHE EM LINHAS --> Linha fixa e percorre coluna
//TRAVAR A COLUNA PREENCHE EM COLUNAS --> Coluna fixa e percorre  linha

int main(){
    int matriz[2][3];
    setlocale(LC_ALL, "Portuguese");

    //Quando trava a linha preeche por linha
    for(int i = 0; i < 2; i++){     //Travando linha
        for(int j = 0; j < 3; j++){
            printf("Digite o elemento da matriz [%d][%d]:", i, j);
            scanf("%d", &matriz[i][j]);
        }
    }

    printf("Matriz ORIGINAL\n");
    //Vai ler da direita para esquerda, de "lado" em "linha"
    for(int i = 0; i < 2; i++){ //Travando a linha
        for(int j = 0; j < 3; j++){
            printf("%d ", matriz[i][j]);
        }
        printf("\n");
    }

    printf("Matriz MULTIPLICADA\n");
    //Na hora de passar o parametro não precisa passar os [], apenas no argumento na assinatura e declaração da função
    matrizMult(matriz);

    return 0;
}

void matrizMult(int matriz[2][3]){
    int maior = matriz[0][0];
    int matrizR[2][3];
    
    //Pegando maior elemento
    for(int i = 0; i < 2; i++){ //Travando linha
        for(int j = 0; j < 3; j++){
            if(maior < matriz[i][j]){
                maior = matriz[i][j];
            }
        }
    }

    //Guardando valores multiplicados na nova matriz
    for(int i = 0; i < 2; i++){    //Travando linha
        for(int j = 0; j < 3; j++){
            matrizR[i][j] = matriz[i][j] * maior;
        }
    }

    //Print da nova matriz multiplicada
    for(int i = 0; i < 2; i ++){    //Travando linha
        for(int j = 0; j < 3; j ++){
            printf("%d ", matrizR[i][j]);
        }
        printf("\n");
    }
}