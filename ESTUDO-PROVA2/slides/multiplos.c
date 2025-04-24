#include <stdio.h>

int main() {
    int numeros[20];
    int mult2 = 0, mult3 = 0, naoMult2ou5 = 0;

    for (int i = 0; i < 20; i++) {
        printf("Digite o %d° número: ", i + 1);
        scanf("%d", &numeros[i]);

        int num = numeros[i]; // Evita acessar várias vezes o mesmo índice

        if (num % 2 == 0) {
            mult2++;
        }
        if (num % 3 == 0) {
            mult3++;
        }
        if (num % 2 != 0 && num % 5 != 0) {
            naoMult2ou5++;
        }
    }

    printf("\nMúltiplos de 2: %d\n", mult2);
    printf("Múltiplos de 3: %d\n", mult3);
    printf("Não múltiplos de 2 nem de 5: %d\n", naoMult2ou5);

    return 0;
}