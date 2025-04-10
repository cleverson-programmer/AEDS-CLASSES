#include <stdio.h>


void trocar(int *a, int *b){
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}
int main(){
    int n1, n2;
    int *a = &n1, *b = &n2;

    printf("Digite um valor:");
    scanf("%d", &n1);

    printf("Digite outro valor:");
    scanf("%d", &n2);

    trocar(a, b);

    printf("Os valores trocados são: %d %d", *a, *b);

    return 0;
}

//FORMA MAIS SIMPLES DE FAZER, SEM CRIAR O PONTEIRO NO MAIN E JÁ PASSANDO O ENDEREÇO DIRETO PARA A CHAMADA DA FUNÇÃO.

// #include <stdio.h>

// void trocar(int *a, int *b){
//     int temp;
//     temp = *a;
//     *a = *b;
//     *b = temp;
// }

// int main(){
//     int n1, n2;

//     printf("Digite um valor: ");
//     scanf("%d", &n1);

//     printf("Digite outro valor: ");
//     scanf("%d", &n2);

//     trocar(&n1, &n2);

//     printf("Os valores trocados são: %d %d\n", n1, n2);

//     return 0;
// }