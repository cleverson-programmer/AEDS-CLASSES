#include <stdio.h>

int main(){

    int n, count = 0;
    printf("Digite um numero inteiro positivo: ");
    scanf("%d", &n);
    for(int i = 1; i <= n; i++){
        if(n % i == 0){
            count++;
        }
    }
    if(count == 2){
        printf("%d eh primo\n", n);
    } else {
        printf("%d nao eh primo\n", n);
    }

    //MESMA LOGICA, MAS COM WHILE
    //int n, count = 0;
    // printf("Digite um numero inteiro positivo: ");
    // scanf("%d", &n);
    //int i = 1;
    // while( i <= n){
    //     if( n % i == 0){
    //         count++;
    //     }
    //     i++;
    // }
    // if(count == 2){
    //     printf("%d e primo\n", n);
    // }else{
    //     printf("%d nao e primo\n", n);
    // }
    return 0;
}