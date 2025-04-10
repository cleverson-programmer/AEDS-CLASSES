#include <stdio.h>
#include <math.h>

int main() {
    double num;
    printf("Digite um número: ");
    scanf("%lf", &num);
    printf("Raiz quadrada: %.2lf\n", sqrt(num));
    return 0;
}