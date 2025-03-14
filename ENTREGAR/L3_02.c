#include <stdio.h>
#include <stdlib.h>

int main(){
    int num;
    long int fatorial =1;
    printf("Digite um numero: ");
    scanf("%d", &num);
    for(int i = 1; i <= num; i++){
        fatorial *= i;
    }
    printf("O fatorial de %d e: %ld\n", num, fatorial);
    return 0;
}