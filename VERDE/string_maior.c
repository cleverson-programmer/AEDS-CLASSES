#include <stdio.h>
#include <string.h>

int main() {
    int n;
    scanf("%d", &n);
    getchar();

    char strings[n][201];

    for (int i = 0; i < n; i++) {
        fgets(strings[i], 201, stdin);

        size_t len = strlen(strings[i]);
        if (len > 0 && strings[i][len - 1] == '\n') {
            strings[i][len - 1] = '\0';
        }
    }

    char maiorComprimento[201];
    char maiorLexico[201];
    strcpy(maiorComprimento, strings[0]);
    strcpy(maiorLexico, strings[0]);

    for (int i = 1; i < n; i++) {
        if (strlen(strings[i]) > strlen(maiorComprimento)) {
            strcpy(maiorComprimento, strings[i]);
        }
        if (strcmp(strings[i], maiorLexico) > 0) {
            strcpy(maiorLexico, strings[i]);
        }
    }

    printf("%s\n", maiorComprimento);
    printf("%s\n", maiorLexico);

    return 0;
}
