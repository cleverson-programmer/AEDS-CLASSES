#include <stdio.h>
#include <stdlib.h>

int main(){
    int count = 0;
    int i;

    //CONSIDERANDO N = 7 COMO NO EXERCICIO
    for(i = 0; i < 7; i++){
        if(i % 2 == 1) count++;
        printf("Valor final: %d\n", count);
    }

    //RESPOSTA 7A: Valor final da variavel considerando N=7 é 3

    //CONSIDERANDO N = 15 COMO NO EXERCICIO
    for(int i= 1; i <= 15; i*=2){
        if(i % 2 == 1){
            printf("Ola");
        }
    }
}

    // RESPOSTA 7B: 1 vez apenas será imprimido o texto, pois uma única vez na primeira iteração do loop 
    // for a condição if é verdadeira pois o resto da divisão de 1 por 2 é 1. Pois estamos incrementando o i em 2, sempre dando um número par e negando o bloco if.

    //RESPOSTA 1a = No 1° algoritmo temos: 2 declarações. No 2° algoritmo temos:1 declaração.
    //RESPOSTA 1b = No 1° algoritmo temos:11 atribuições. No 2° algoritmo temos: 5 atribuições.

    //RESPOSTA 2a = 1° algoritmo 8 operações, 2° algoritmo 6 operações.
    //RESPOSTA 2b = 1° algoritmo 7 operações, 2° algoritmo 5 operações.
    //RESPOSTA 2c =  1° algoritmo 7 operações, 2° algoritmo 5 operações.
    //RESPOSTA 2d =  1° algoritmo 10 operações, 2° algoritmo 5 operações.