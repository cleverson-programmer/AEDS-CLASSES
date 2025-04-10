#include <stdio.h>

int main() {
    int num, maior = 0;
    
    do {
        printf("Digite números (negativo para parar): ");
        scanf("%d", &num);
        if (num > maior) maior = num;
    } while (num >= 0);
}