#include <stdio.h>
#include <stdlib.h>

int main(){
    int num = 1, impar, limit = 10;

    do {
        if(num % 2 != 0){
            impar = num;
            printf("Impar: %d\n", impar);
        }
        num++;
    } while(num < limit);

    return 0;
}