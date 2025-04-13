#include <stdio.h>
#include <string.h>
#include <ctype.h> // Para tolower

// Contar vogais
// Escreva uma função que conte e retorne o número de vogais em uma string.

//JEITO MAIS DIFICIL E MENOS PERFORMÁTICO
// int contar_vogais(const char *str) {
//     int count = 0;
//     for(int i = 0; str[i] != '\0'; i++) {
//         char c = str[i];
//         // Verifica se o caractere é uma vogal (minúscula ou maiúscula)
//         if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' ||
//             c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U') {
//             count++;
//         }
//     }
//     return count;
// }

//JEITO IDEAL, MAIS FÁCIL!!!!!
int contarVogais(char *str) {
    int count = 0;
    for (int i = 0; i < strlen(str); i++) {
        char c = tolower(str[i]);
        if (strchr("aeiou", c)) {
            count++;
        }
    }
    return count;
}

//SEGUNDO JEITO MAIS FÁCIL
int contar_vogais(const char *str) {
    int count = 0;
    for(int i = 0; str[i] != '\0'; i++) {
        char c = tolower(str[i]); // Converte o caractere para minúscula
        // Verifica se o caractere é uma vogal (minúscula)
        if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') {
            count++;
        }
    }
    return count;
}

int main(){
    char str[100];
    printf("Digite uma string: ");
    fgets(str, sizeof(str), stdin); // Lê a string do usuário
    str[strcspn(str, "\n")] = 0; // Remove o caractere de nova linha
    int num_vogais = contarVogais(str);
    printf("Número de vogais: %d\n", num_vogais);
    return 0;
}