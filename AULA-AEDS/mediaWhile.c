#include <stdio.h>
#include <stdlib.h>

int main(){
    int notas, i = 0;
    float media = 0;

    while(i < 10){
        printf("Digite a nota %d: ", i + 1);
        scanf("%d", &notas);
        media += notas;
        i++;
    }

    printf("Media: %.2f\n", media / 10);
}