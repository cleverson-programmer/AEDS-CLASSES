#include <stdio.h>

//Mostra a tabuada de 1 a 10 do número que o usuário digitar
int main() {
    int num;

    printf("Digite um número para ver a tabuada: ");
    scanf("%d", &num);

    for (int i = 1; i <= 10; i++) {
        printf("%d x %d = %d\n", num, i, num * i);
    }

    return 0;
}
