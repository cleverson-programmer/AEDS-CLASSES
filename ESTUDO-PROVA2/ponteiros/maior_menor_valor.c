// 4. Maior e menor valor
// Faça uma função void maiorMenor(int *vet, int n, int *maior, int *menor) que receba um vetor e retorne, por ponteiros, o maior e o menor valor.
#include <stdio.h>

void maiorMenor( int *vetor, int n, int *maior, int *menor){

}

int main(){
    int n;
    int vetor[n];

    printf("Digite o tamanho do vetor: %d");
    scanf("%d", &n);

    for(int i = 0; i <= n; i ++){
        printf("Digite o elememto %d", i + 1);
        scanf("%d", &vetor[i]);
    }
    return 0;
}