// 4. Maior e menor valor
// Faça uma função void maiorMenor(int *vet, int n, int *maior, int *menor) que receba um vetor e retorne, por ponteiros, o maior e o menor valor.
#include <stdio.h>

void maiorMenor( int *vetor, int n, int *maior, int *menor){
    //Iniciando o ponteiro com o valor do primeiro elemento do array que por ser o primeiro vai ser o menor e o maior;
    *maior = vetor[0];
    *menor = vetor[0];

    //No laço for o i deve sempre ser "n - 1" pois vetores sempre vão de 0 ate n -1 por isso sempre deve usar i < n
    for(int i = 0; i < n; i++){
        if(vetor[i] > *maior){
            *maior = vetor[i];
        }
        if(vetor[i] < *menor){
            *menor = vetor[i];
        }
    }
}

int main(){
    int n, maior, menor;

    printf("Digite o tamanho do vetor:");
    scanf("%d", &n);

    //Tem que declarar o vetor depois de ler o valor da váriavel senão retorna erro!
    int vetor[n];

    for(int i = 0; i < n; i++){
        printf("Digite o elememto %d: ", i + 1);
        scanf("%d", &vetor[i]);
    }

    //Passando o endereço das variáveis pois a fn espera ponteiro. O vetor já é por si só um ponteiro.
    maiorMenor(vetor, n, &maior, &menor);

    printf("O maior: %d\n O menor: %d", maior, menor);
    return 0;
}