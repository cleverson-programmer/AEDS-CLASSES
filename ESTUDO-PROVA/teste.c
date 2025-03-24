#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(){

    double n;

    printf("Digite um numero:");
    scanf("%lf", &n);
    printf("O numero ao quadrado e %.2lf", pow(n,2));
    printf("\nO numero ao cubo e %.2lf", pow(n,3));
}

int fahrenheit() {
    float celsius;
    printf("Digite a temperatura em Celsius: ");
    scanf("%f", &celsius);
    printf("Fahrenheit: %.2f\n", celsius * 9.0 / 5.0 + 32);
    return 0;
}