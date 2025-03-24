#include <stdio.h>
#include <math.h>

int fatorial() {
    int num;
    long int fatorial = 1;
    printf("Digite um número: ");
    scanf("%d", &num);
    for (int i = 1; i <= num; i++) {
        fatorial *= i;
        if (fatorial > 1000000) {
            printf("Fatorial ultrapassou 1.000.000!\n");
            break;
        }
    }
    if (fatorial <= 1000000) printf("Fatorial: %ld\n", fatorial);
    return 0;
}

int main() {
    float graus;
    printf("Digite um ângulo em graus: ");
    scanf("%f", &graus);
    float radianos = graus * 3.14 / 180.0;
    printf("Seno: %.2f\n", sin(radianos));
    return 0;
}
