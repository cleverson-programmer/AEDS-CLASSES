#include <stdio.h>

void troca(int *x, int *y); // assinatura da fn que espera dois ponteiros como parametro

int main(){
    int a = 5, b = 2;   //delcaração atributiva
    troca(&a, &b);  //Passando endereço da variável para fn que espera receber um ponteiro
    printf("\n%i, %i", a, b);   //IMPRIME "2,5" depois da troca

    //%i no printf --> funciona da mesma forma que o %d imprimindo um inteiro
    //%i no scanf --> na leitura ele pode lê decimal, octal (se começa com 0) ou hexadecimal (se começa com 0x).
}

void troca(int *x, int *y) {
    int aux;    //declarando variavel
    aux = *x;   // aux recebe o  valor apontado por x que é 5
    *x = *y;    //ponteiro de x recebe o valor do ponteiro de y que é 2 então x = 2
    *y = aux;   //ponteiro de y recebe o valor da variavel temporária para trocar aux que é 5 então y = 5
    //Como são ponteiros que apontam respectivamente para a e b fica a=2 e b=5;
}