#include <stdio.h>

int main() {
    int M, A, B, C, maior;

    scanf("%d", &M);
    scanf("%d", &A);
    scanf("%d", &B);

    C = M - (A + B);

    maior = A;
    if (B > maior) {
        maior = B;
    }
    if (C > maior) {
        maior = C;
    }

    printf("%d\n", maior);

    return 0;
}
