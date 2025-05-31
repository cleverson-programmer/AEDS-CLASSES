#include <stdio.h>
#include <string.h>

#define MAX_N 20000
#define MAX_LEN 11

int main() {
    int n;
    char senhas[MAX_N][MAX_LEN];

    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%s", senhas[i]);
    }

    int contador = 0;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i != j && strstr(senhas[j], senhas[i]) != NULL) {
                contador++;
            }
        }
    }

    printf("%d\n", contador);
    return 0;
}
