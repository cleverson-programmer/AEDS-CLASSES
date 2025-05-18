#include <stdio.h>
#include <stdlib.h>

int main(){
    int n;
    printf("Digite a quantidade de elementos do vetor:");
    scanf("%d", &n);

    int *vetor = (int *) malloc(n * sizeof(int));
    if(vetor == NULL){
        printf("Erro na alocação de memória. \n");
        return 1;
    }
    
    for(int i = 0; i < n; i++){
        printf("Digite o %d elemento:", i + 1);
        scanf("%d", &vetor[i]);
    }

    for(int i = 0; i < n; i++){
        printf("%d\n", vetor[i]);
    }

    free(vetor);
    return 0;
}