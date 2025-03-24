#include <stdio.h>

int main() {
    for (int i = 1; i <= 100; i++) {
        if (i % 2 == 0 && i % 10 != 0) {
            printf("%d\n", i);
        }
    }

    //** OUTRA FORMA DE RESOLVER **
    // for (int i = 2; i <= 100; i += 2) {
    //     if (i % 10 != 0) printf("%d ", i);
    // }
}