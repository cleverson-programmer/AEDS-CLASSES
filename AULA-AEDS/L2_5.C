#include <stdio.h>
#include <stdlib.h>

int main(){
    int a, b, c, temp;
    printf("Digite o valor de a: ");
    scanf("%d", &a);
    printf("Digite o valor de b: ");
    scanf("%d", &b);
    printf("Digite o valor de c: ");
    scanf("%d", &c);

    if(c % a == 0 && c % b == 0) temp = 1;
    else if(c % a == 0 || c % b == 0) temp = 0;
    else temp = -1;

    switch(temp){
        case 1:
            printf("O valor de c eh divisivel por a e b\n");
            break;
        case 0:
            printf("O valor de c eh divisivel por a ou b\n");
            break;
        case -1:
            printf("O valor de c nao eh divisivel por a nem b\n");
            break;
        default:
            printf("Valor invalido\n");
            break;
    }

    return 0;
}