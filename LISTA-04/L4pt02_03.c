#include <stdio.h>

float soma_Equals(int n);

int main(){
    int n;
    printf("Digite um valor: ");
    scanf("%d", &n);

    printf("Soma: %.3lf", soma_Equals(n));

    return 0;
}

float soma_Equals(int n){
    double S = 0.0; //Tem que lembrar de fazer uma divisão real(1.0) se colocar dois inteiros divide e salva apenas a parte inteira.

    for(int i = 1; i <= n; i++){
        S += (1.0 / i); //Tem que lembrar de fazer uma divisão real(1.0) se colocar dois inteiros divide e salva apenas a parte inteira.
    }

    return S;
}