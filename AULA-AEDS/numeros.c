#include <stdio.h>
#include <stdlib.h>

int main(){
    int limit = 16, i = 0;
    int num, maior= 0, menor= 0;

    do{
        printf("Digite o %d número: ", i + 1);
        scanf("%d", &num);
        if(num > maior) maior = num;
        if(num < menor || i == 0) menor = num;
        i++;
    } while(i < limit);
    printf("Maior: %d\nMenor: %d\n", maior, menor);

}