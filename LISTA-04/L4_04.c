#include <stdio.h>

float equals(int n);

int main(){
    int n;
    printf("Digite o valor de n:");
    scanf("%d", &n);

    printf("Resultado: %.2f", equals(n));
    return 0;
}

float equals(int n){
    float E = 1.0;
    int fatorial = 1;

    for(int i = 1; i <= n; i++){
        fatorial *= i;
        E += 1.0 / fatorial;
    }

    return E;
}