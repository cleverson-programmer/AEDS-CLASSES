#include <stdio.h>
#include <stdlib.h>


//ACESSAR O VALOR DE ENDEREÇO APONTADO POR UM PONTEIRO USA O *
//ACESSAR O ENDEREÇO DO PONTEIRO USA O &

void incrementa(int *n) { //Fn espera como parametro um ponteiro para inteiro
    (*n)++; // incrementa o valor do inteiro apontado por n

}

int main(){

    //PONTEIRO
    int x = 10;
    int *p;      // declara um ponteiro para inteiro
    p = &x;      // p recebe o endereço de x

    printf(" CONTEÚDO DE X ATRAVÉS DO *p: %d\n", *p);  // imprime o conteúdo de x, que é 10
    printf(" ENDEREÇO DO X ATRAVES DO p: %p\n", p);   // imprime o endereço de x
    printf("ENDEREÇO DO X ATRAVES DO &x: %p\n", &x);  // imprime o endereço de x
    printf(" ENDEREÇO DO P ATRAVES DO &p: %p\n", &p);  // imprime o endereço de p

    //PONTEIRO APONTANDO PARA OUTRO PONTEIRO
    int x = 10;
    int *p = &x; // declara um ponteiro para inteiro que aponta para o endereço de x
    int **pp = &p; // declara um ponteiro para ponteiro que aponta para o endereço de p que é um ponteiro para x

    printf("IMPRIMINDO O PONTEIRO QUE APONTA PARA OUTRO PONTEIRO QUE POR SUA VEZ APONTA PARA O ENDEREÇO DE UMA VARIÁVEL%d", **pp); // imprime 10

    //FUNÇÕES COM PASSAGEM POR REFERÊNCIA

    // A passagem por referência é feita através do uso de ponteiros, onde o endereço da variável é passado para a função. Isso permite que a função modifique o valor da variável original. Sem isso, a função só teria acesso a uma cópia do valor da variável, e qualquer modificação feita dentro da função não afetaria o valor original.
    // A passagem por referência é útil quando se deseja modificar o valor de uma variável dentro de uma função, ou quando se deseja passar grandes estruturas de dados (como arrays ou structs) para uma função sem fazer uma cópia completa delas.
    // A passagem por referência é feita através do uso de ponteiros, onde o endereço da variável é passado para a função. Isso permite que a função modifique o valor da variável original.
    int a = 5;
    incrementa(&a); //passando o endereço de 'a' para a função
    printf("%d", a); // imprime 6


    return 0;
}
