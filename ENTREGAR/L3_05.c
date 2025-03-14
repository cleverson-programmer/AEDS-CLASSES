#include <stdio.h>
#include <stdlib.h>

int main(){
    int n, a= 0, b = 1, next;
    printf("Digite um numero inteiro positivo: ");
    scanf("%d", &n);

    for(int i = 0; i <= n; i++){
        if (i == 0) {
            printf("%d° termo: %d\n", i, a);
            continue;
        }
        if (i == 1) {
            printf("%d° termo: %d\n", i, b);
            continue;
        }
        next = a + b;
        a = b;
        b = next;

        printf("%d° termo: %d\n", i, b);
    }
}