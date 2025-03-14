#include <stdio.h>
#include <stdlib.h>

int main(){

    int n, a = 0, b = 1, next;
    printf("Digite um numero inteiro positivo: ");
    scanf("%d", &n);

    if (n == 0) {
        printf("0°: %d\n", a);
    } else if (n == 1) {
        printf("1°: %d\n", b);
    } else {
        for(int i = 2; i <= n; i++){
            next = a + b;
            a = b;
            b = next;
        }
        printf("N-esimo termo: %d\n",b);
    }

    return 0;
}