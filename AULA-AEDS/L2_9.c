#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(){
    int w, x, y, z;

    printf("Digite o valor de w: ");
    scanf("%d", &w);
    printf("Digite o valor de x: ");
    scanf("%d", &x);
    printf("Digite o valor de y: ");
    scanf("%d", &y);
    printf("Digite o valor de z: ");
    scanf("%d", &z);

    float geometrica = sqrt(w * x * y * z);
    printf("Media geometrica: %.2f\n", geometrica);

    float ponderada = (w + 2*x + 3*y + 4*z) / (1 + 2 + 3 + 4);
    printf("Media ponderada: %.2f\n", ponderada);

    float harmonica = 4 / ((1.0/w) + (2.0/x) + (3.0/y) + (4.0/z));
    printf("Media harmonica: %.2f\n", harmonica);

    float aritmetica = (w + x + y + z) / 4.0;
    printf("Media aritmetica: %.2f\n", aritmetica);

    return 0;
}