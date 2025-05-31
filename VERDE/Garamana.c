#include <stdio.h>
#include <string.h>

int main() {
    char P[101], A[101];
    int freqP[26] = {0};
    int freqA[26] = {0};
    int coringa = 0;

    // Ler as palavras
    scanf("%s", P);
    scanf("%s", A);

    int tamanho = strlen(P);

    for (int i = 0; i < tamanho; i++) {
        freqP[P[i] - 'a']++;
    }

    for (int i = 0; i < tamanho; i++) {
        if (A[i] == '*') {
            coringa++;
        } else {
            freqA[A[i] - 'a']++;
        }
    }

    int precisa = 0;
    for (int i = 0; i < 26; i++) {
        if (freqA[i] > freqP[i]) {
            printf("N\n");
            return 0;
        }
        precisa += freqP[i] - freqA[i];
    }

    if (precisa == coringa) {
        printf("S\n");
    } else {
        printf("N\n");
    }

    return 0;
}
