#include <stdio.h>

int numbers(int vetor[3]);

int main(){
    int vetor[3];

    for(int i = 0; i < 3; i++){
        printf("Digite o %d° valor: ", i + 1);
        scanf("%d", &vetor[i]);
    }

    printf("O menor %d:", numbers(vetor));

    return 0;
}

int numbers(int vetor[3]){
    int menor = vetor[0];
    for(int i = 1; i < 3; i++){
        if(vetor[i] < menor){
            menor = vetor[i];
        }
    }
    return menor;
}