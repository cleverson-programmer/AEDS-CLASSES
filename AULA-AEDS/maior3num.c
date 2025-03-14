#include <stdio.h>
#include <stdlib.h>

int main(){

    int num, limit =4, i = 1, temp;

    do{
        printf("Digite o %d numero:\n", i++);
        scanf("%d", &num);

        if(num >= temp) temp = num;

    }while(i < limit);

}