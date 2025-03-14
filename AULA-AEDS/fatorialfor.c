#include <stdio.h>
#include <stdlib.h>

int main(){
    int num;
    long int fatorial = 1;

    printf("Digite um numero: ");
    scanf("%d", &num);
    if(num < 0){
        printf("Fatorial de numero negativo nao existe.\n");
        return 1;
    }

    for(int i = 1; i <= num; i++){
        fatorial *= i;
    }

    printf("O fatorial de %d eh: %ld\n", num, fatorial);
    return 0;
}