#include <stdio.h>

void inverter_vetor(int n, int *vetor);

int main(){
    int n;
    printf("Digite a quantidade de itens: ");
    scanf("%d", &n);

    int vetor[n];

    for(int i = 0; i < n; i++){
        printf("Digite o %d° elemento: ", i + 1);
        scanf("%d", &vetor[i]);
    }

    inverter_vetor(n, vetor);

    for(int i = 0; i < n; i++){
        printf("%d ", vetor[i]);
    }
    return 0;
}

void inverter_vetor(int n, int *vetor){
    int temp;

    for(int i = 0; i < n / 2; i++){
        temp = vetor[i];
        vetor[i] = vetor[n - 1 - i];
        vetor[n - 1 - i] = temp;
    }
    
}