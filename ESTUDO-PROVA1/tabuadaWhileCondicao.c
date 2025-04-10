#include <stdio.h>

int main(){
    int n, count = 1;

    printf("Digite um número: ");
    scanf("%d", &n);

    do{
        if (n < 0){
            printf("Número inválido!\n");
            break;
        }
        printf("%d x %d = %d\n", n, count, n * count);
        count++;
    }while( count <= 10);

    return 0;
}