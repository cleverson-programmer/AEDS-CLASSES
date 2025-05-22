// Crie um programa que escreva de 1 até 10 em um
// arquivo binário, armazenando um número por linha.

#include <stdio.h>
#include <stdlib.h>

int main(){
    FILE *arquivo = fopen("dados.bin", "wb");
    if(arquivo == NULL){
        printf("Erro ao abrir o arquivo.\n");
        return 1;
    }

    for(int i = 1; i <= 10; i++){
        fwrite(&i, sizeof(int), 1, arquivo);
    }

    fclose(arquivo);
    return 0;
}
