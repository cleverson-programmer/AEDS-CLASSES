#include <stdio.h>

int soma( int num[5]){
    int soma = 0;

    for(int i = 0; i < 5; i++){
        soma += num[i];
    }
    return soma;
}
int main(){
    int num[5];
    for(int i = 0; i < 5; i++){
        printf("Digite o %d numero: ", i + 1);
        scanf("%d", &num[i]);
    }
    soma( num[5]);
    printf("A soma dos numeros é: %d\n", soma);
}