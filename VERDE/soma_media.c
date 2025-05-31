#include <stdio.h>
#include <math.h>

int main() {
    int n1, n2, n3, n4, n5;
    scanf("%d %d %d %d %d", &n1, &n2, &n3, &n4, &n5);

    int soma = n1 + n2 + n3 + n4 + n5;
    double media = soma / 5.0;
    int mediaArredondada = (int)ceil(media);

    printf("%d\n", soma);
    printf("%d\n", mediaArredondada);

    return 0;
}

