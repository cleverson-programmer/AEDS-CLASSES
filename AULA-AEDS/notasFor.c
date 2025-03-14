#include <stdio.h>
#include <stdlib.h>

int main(){
    float media, notas;
    int soma = 0, limit = 10;


    for(int i = 0; i <= limit; i++){
        printf("Digite a nota do aluno:\n");
        scanf("%f", &notas);
        soma += notas;
        media = soma / limit;
    }

    printf("A média do aluno é: %.2f\n", media);

    return 0;
}