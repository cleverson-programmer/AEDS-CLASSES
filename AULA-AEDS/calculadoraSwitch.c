#include <stdio.h>
#include <stdlib.h>

int main(){
    int n1, n2, operator;
    float result;

    printf("Digite um numero inteiro: ");
    scanf("%d", &n1);

    printf("Digite outro numero inteiro: ");
    scanf("%d", &n2);

    printf("Digite o número da operação que você deseja:\n [1] Adição\n [2] Subtração\n [3] Multiplicação\n [4] Divisão\n [5] Sair\n");
    scanf("%d", &operator);

    if( n1 == 0 && n2 == 0 && operator == 4) return printf("Resultado indefinido\n");

    switch (operator)
    {
    case 1:
        result = n1 + n2;
        printf("%d + %d = %.2f", n1, n2, result);
        break;
    case 2:
        result = n1 - n2;
        printf("%d - %d = %.2f", n1, n2, result);
        break;
    case 3:
        result = n1 * n2;
        printf("%d x %d = %.2f", n1, n2, result);
        break;
    case 4:
        result = n1 / n2;
        printf("%d / %d = %.2f", n1, n2, result);
        break;
    case 5:
        break;
    default:
        printf("Nenhuma das opções válidas");
        break;
    }

    return 0;
}