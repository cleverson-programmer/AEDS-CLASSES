#include <stdio.h>
#include <locale.h>

void soma(int matriz[5][2]);

//TRAVAR A LINHA PREENCHE EM LINHAS --> Linha fixa e percorre coluna
//TRAVAR A COLUNA PREENCHE EM COLUNAS --> Coluna fixa e percorre linha

int main(){
    int matriz[5][2];
    setlocale(LC_ALL, "Portuguese");

    for(int i= 0; i < 5; i++){ //travando linha
        for(int j = 0; j < 2; j++){
            printf("Digite o valor de [%d][%d]", i, j);
            scanf("%d", &matriz[i][j]);
        }
    }

    printf("MATRIZ ORIGINAL\n");
    for(int i= 0; i < 5; i++){ //travando linha
        for(int j = 0; j < 2; j++){
            printf("%d ", matriz[i][j]);
        }

        printf("\n");
    }

    soma(matriz);

    return 0;
}

void soma(int matriz[5][2]){
    int vetor[5];
    int matrizR[5][2];

    for(int i= 0; i < 5; i++){ //travando linha

        int soma = 0; //Sempre que uma variável depende do escopo de um loop (como uma soma por linha), ela precisa ser inicializada dentro do laço externo, para reiniciar a contagem corretamente.
        for(int j = 0; j < 2; j++){
            soma+= matriz[i][j];
        }
        vetor[i] = soma;
    }

    printf("VETOR COM AS SOMAS POR LINHA\n");
    for(int i = 0; i < 5; i++){ //Travando por linha percorrendo coluna
        for(int j = 0; j < 2; j++){
            matrizR[i][j] = matriz[i][j] * vetor[i];
        }
    }

    printf("MATRIZ RESULTANTE DA MULTIPLICAÇÃO DOS VALORES PELA SOMA DE CADA LINHA\n");
    for(int i = 0; i < 5; i++){ //Travando por linha percorrendo coluna
        for(int j = 0; j < 2; j++){
            printf("%d ", matrizR[i][j]);
        }
        printf("\n");
    }

}