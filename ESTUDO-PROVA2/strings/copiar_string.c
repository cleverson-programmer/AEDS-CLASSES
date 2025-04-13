#include <stdio.h>
#include <string.h>

//COPIAR UMA STRING DE UM VETOR PARA OUTRO

void copy(char *destino, char *origem){
    strncpy(destino, origem, 256);

    printf("COPIADO EM OUTRA VARIAVEL: %s", destino);

}

int main(){
    char origem[256], destino[256];

    printf("Digite uma string: ");
    fgets(origem, sizeof(origem), stdin);

    origem[strcspn(origem, "\n")] = '\0';

    copy(destino, origem);

    return 0;
}