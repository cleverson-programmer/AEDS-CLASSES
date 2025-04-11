// 6. Inverter um vetor
// Escreva uma função void inverter(int *vet, int n) que inverta os elementos do vetor no próprio vetor usando ponteiros.

#include <stdio.h>

void inverter(int *vet, int n) {
    int *inicio = vet;
    int *fim = vet + n - 1;
    int temp;

    while (inicio < fim) {
        temp = *inicio;
        *inicio = *fim;
        *fim = temp;

        inicio++;
        fim--;
    }
}

int main() {
    int n;
    printf("Digite a quantidade de elementos: ");
    scanf("%d", &n);

    int vetor[n];

    for (int i = 0; i < n; i++) {
        printf("Digite o elemento %d: ", i + 1);
        scanf("%d", &vetor[i]);
    }

    inverter(vetor, n);

    printf("Vetor invertido:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", vetor[i]);
    }
    printf("\n");

    return 0;
}


//Outras formas de resolver

void inverter2(int *vet, int n) {
    int temp;

    //Percorremos o vetor somente ate a metade, por isso n / 2
    for (int i = 0; i < n / 2; i++) {
        int *inicio = vet + i;  //Ponteiro de inicio recebe o vetor na posição atual, começando na posição 0
        int *fim = vet + (n - 1 - i); //Ponteiro de final recebe na posição final que é sempre é 'n -1', menos a posição atual do laço

        temp = *inicio; //temp recebe o valor de inicio
        *inicio = *fim; // inicio recebe o fim
        *fim = temp; // fim recebe temp que contém o valor de inicio
    }

    //EX: 
    //n = 4;
    //Entrada vetor[n] = {4,3,2,1};
    // for --> 0 < 4 ? sim
    //*inicio --> endereço da posicao
    //*fim --> endereço da posicao
    //temp = endereço do inicio
    //*inicio = endereço do fim
    //*fim = temp que contém o endereço do inicio como valor

    // vet[i] --> int --> Valor do elemento na posição i
    // vet + i --> int * --> Endereço da posição i
    // *(vet + i) --> int -->Valor da posição i (igual a vet[i])
}

void inverter3(int *vet, int n) {
    int temp;

    for (int i = 0; i < n / 2; i++) {
        temp = *(vet + i);                         // pega valor da posição i
        *(vet + i) = *(vet + n - 1 - i);           // copia o valor espelhado do fim para o início
        *(vet + n - 1 - i) = temp;                 // coloca o valor original no final
    }
}