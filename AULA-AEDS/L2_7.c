#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(){
    //(ax² + bx + c = 0)
    int a, b, c;
    double raiz1, raiz2;

    printf("Digite o valor de a: ");
    scanf("%d", &a);
    printf("Digite o valor de b: ");
    scanf("%d", &b);
    printf("Digite o valor de c: ");
    scanf("%d", &c);
    if(a == 0){
        printf("Valor de a invalido\n");
        return 1;
    }

    int delta = (pow(b, 2)) - (4 * a * c);
    raiz1 = (-b + sqrt(delta)) / (2 * a);
    raiz2 = (-b - sqrt(delta)) / (2 * a);
    printf("Raiz 1: %.2lf\n", raiz1);
    printf("Raiz 2: %.2lf\n", raiz2);
    return 0;
}