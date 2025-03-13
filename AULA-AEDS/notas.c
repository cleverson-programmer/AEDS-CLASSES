#include <stdio.h>
#include <string.h>

int main(){

    char materia[50];
    char nota;

    printf("Digite uma materia: ");
    fgets(materia, sizeof(materia), stdin);

    materia[strcspn(materia, "\n")] = '\0';

    printf("Digite uma nota: [A,B,C,D]: ");
    fgets(nota, sizeof(nota), stdin);


    switch(nota){
        case 'A':
            printf("Voce passou com 100 porcento de acertos em %s ", materia);
            break;
        case 'B':
            printf("Voce passou com 80 porcento de acertos em %s ", materia);
            break;
        case 'C':
            printf("Voce passou com 60 porcento de acertos em %s ", materia);
            break;
        case 'D':
            printf("Voce REPROVOU com 59 porcento ou menos de acertos em %s ", materia);
            break;
        default:
            printf("Nenhuma nota válida!");
            break;
    }
    return 0;
}