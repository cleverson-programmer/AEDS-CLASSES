#include <stdio.h>
#include <stdlib.h>

int main(){
    int n1, n2, mdc;

    printf("Digite dois números inteiros positivos N1 e N2: ");
    scanf("%d %d", &n1, &n2);

    for(int i = 1; i <= n1 && i <= n2; i++){
        if (n1 % i == 0 && n2 % i == 0){
            mdc = i;
        }
    }
    printf("O MDC de %d e %d é: %d\n", n1, n2, mdc);
    return 0;
}