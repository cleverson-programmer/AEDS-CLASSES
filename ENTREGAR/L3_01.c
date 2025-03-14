#include <stdio.h>
#include <stdlib.h>

int main(){

    int num, impar, soma = 0;

    printf("Digite un numero: ");
    scanf("%d", &num);

    for(int i = 1; i <= num; i++){
        if( i % 2 != 0){
            impar = i;
            soma += impar;
            printf("Numero impar: %d\n", impar);
        }
    }

    printf("A soma dos numeros impares de 0 a %d e: %d\n", num, soma);

    return 0;
}