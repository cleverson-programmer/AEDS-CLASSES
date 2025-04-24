//ANÁLISE DETALHADA --> contagem de operações reais
//ANÁLISE ASSINTÓTICA --> complexidade de tempo


#include <stdio.h>

int contarVogais(char *str);

int main(){
    char str[100]; //1 locação de memória
    printf("Digite uma string: "); // 1printf
    fgets(str, sizeof(str), stdin); // 1 leitura
    str[strcspn(str, "\n")] = '\0'; // 1 atribuição + n chamadas de funções
    int num_vogais = contarVogais(str); // 1 atribuição + 1 chamada de fn
    printf("Número de vogais: %d\n", num_vogais); // 1 printf
    return 0; // 1 operação
}

int contarVogais(char *str) {
    int count = 0; // 1 inicialização
    int lenght = strlen(str); // 1 atribuição e n chamadas de fn
    for(int i = 0; i < lenght; i++) { // 1 atribuição + n comparações + n incrementos
        char c = tolower(str[i]); // ( 1 atribuição + 1 chamada ) * n
        if (strchr("aeiou", c)) { // (1 chamada * 5 ) * n
            count++; // 1 incremento * n
        }
    }
    return count; // 1 operação
}


//Menos performático
// int contarVogais(char *str) {
//     int count = 0;
//     for (int i = 0; i < strlen(str); i++) { //Tem que acessar o tamanho do vetor em cada iteração?
//         char c = tolower(str[i]);
//         if (strchr("aeiou", c)) {
//             count++;
//         }
//     }
//     return count;
// }