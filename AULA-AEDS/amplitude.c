#include <stdio.h>
#include <stdlib.h>

int main(){
    int num,maior, menor, i = 1,limit = 6;
    int at;

    do{
        printf("Digite o %d numero:", i++);
        scanf("%d", &num);

        if(num > maior) maior = num;
        if(num < menor || i == 0) menor = num;
    }while(i < limit);

    at = maior - menor;

    printf("A amplitude e: %d", at);

    return 0;
}


