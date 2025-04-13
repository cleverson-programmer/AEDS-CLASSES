#include <stdio.h>
#include <string.h>
//STRING EM C --> char nome[] = "João"; // {'J', 'o', 'ã', 'o', '\0'}

//Para ler os dados de string que o usuário digitar vamos usar o fgets()
// fgets(vetor, sizeof(vetor), stdin); ---> o vetor aonde sera armazenado, o tamanho e por fim da onde vem a entrada, que no caso é a padrão TECLADO!

//strlen() – Retorna o tamanho da string (sem contar o \0)
int strlenFn() {
    char nome[] = "Maria";
    printf("Tamanho: %lu\n", strlen(nome)); // Saída: 5
}

//strcpy(destino, origem) --> Copia uma string em outra
//strncpy(destino, origem, N) --> Copia até N caracteres
int strcpyFn(){
    char destino[50];
    char origem[] = "Olá mundo";
    strcpy(destino, origem); //Pode ter estouro de memória se o vetor de destino não tiver tamanho suficiente
    strncpy(destino, origem, 4); // copia "Olá " Não coloca o \0 se o tamanho for limitado!
}

int strncpyFn() {
    char destino[50];
    char origem[] = "Olá mundo";

    // Copia segura com limite
    strncpy(destino, origem, sizeof(destino) - 1); // Copia até 49 caracteres
    destino[sizeof(destino) - 1] = '\0'; // Garante que haja '\0' no final

    printf("strncpy segura: %s\n", destino);

    return 0;
}

//strcat() – Concatena (junta) strings
//strncat(destino, origem, N) – Concatena até N caracteres

int strcatFn() {
    char destino[50] = "Bom ";
    char origem[] = "dia";

    strcat(destino, origem); // Concatena
    printf("Concatenação: %s\n", destino); // Saída: Bom dia

    char destino2[50] = "Good ";
    char origem2[] = "Morning";
    strncat(destino2, origem2, 4); // Concatena até 4 caracteres
    printf("Concatenação com limite: %s\n", destino2); // Saída: Good Morn --> primeiros 4 caracteres da string de origem
    return 0;
}

//strcmp() – Compara duas strings
// Retorno:

// 0 → iguais

// < 0 → primeira menor

// > 0 → primeira maior

//strncmp(s1, s2, N) – Compara até N caracteres

int strcmpFn() {
    char str1[] = "abc";
    char str2[] = "abc";
    char str3[] = "abcd";

    int resultado1 = strcmp(str1, str2); // 0
    int resultado2 = strcmp(str1, str3); // < 0
    int resultado3 = strcmp(str3, str1); // > 0

    printf("Resultado 1: %d\n", resultado1);
    printf("Resultado 2: %d\n", resultado2);
    printf("Resultado 3: %d\n", resultado3);

    return 0;
}

//strcspn() – Retorna o tamanho da parte inicial de uma string que não contém caracteres de outra string
int strcspnFunction(char *word){
    word[strcspn(word, "\n")] = '\0';//Trocar o \n que pega no enter por \0 que identifica o fim da string
}

//strchr() – Procura primeira ocorrência de um caractere
//strrchr() – Procura última ocorrência de um caractere
//strstr() – Procura primeira ocorrência de uma substring
//strpbrk() – Procura primeira ocorrência de qualquer caractere de um conjunto
//strspn() – Retorna o tamanho da parte inicial de uma string que contém caracteres de outra string
//strtok() – Divide uma string em partes (tokens) com base em delimitadores

int strchrFn() {
    char str[] = "Hello, world!";
    char *ptr = strchr(str, 'o'); // Procura o primeiro 'o'
    if (ptr != NULL) {
        printf("Primeira ocorrência de 'o': %s\n", ptr); // Saída: o, world!
    }
    return 0;
}

int strrchrFn() {
    char str[] = "Hello, world!";
    char *ptr = strrchr(str, 'o'); // Procura o último 'o'
    if (ptr != NULL) {
        printf("Última ocorrência de 'o': %s\n", ptr); // Saída: o!
    }
    return 0;
}

int strstrFn() {
    char str[] = "Hello, world!";
    char *ptr = strstr(str, "world"); // Procura a substring "world"
    if (ptr != NULL) {
        printf("Ocorrência de 'world': %s\n", ptr); // Saída: world!
    }
    return 0;
}

int strpbrkFn() {
    char str[] = "Hello, world!";
    char *ptr = strpbrk(str, "aeiou"); // Procura a primeira vogal
    if (ptr != NULL) {
        printf("Primeira vogal: %c\n", *ptr); // Saída: e
    }
    return 0;
}

int strcspnFn() {
    char str[] = "Hello, world!";
    char *ptr = strpbrk(str, "aeiou"); // Procura a primeira vogal
    if (ptr != NULL) {
        size_t length = ptr - str; // Tamanho até a primeira vogal
        printf("Tamanho até a primeira vogal: %zu\n", length); // Saída: 1
    }
    return 0;
}

int strspnFn() {
    char str[] = "Hello, world!";
    char *ptr = strpbrk(str, "aeiou"); // Procura a primeira vogal
    if (ptr != NULL) {
        size_t length = ptr - str; // Tamanho até a primeira vogal
        printf("Tamanho até a primeira vogal: %zu\n", length); // Saída: 1
    }
    return 0;
}

int strtokFn() {
    char str[] = "Hello, world!";
    char *token = strtok(str, ", "); // Divide a string em partes
    while (token != NULL) {
        printf("Token: %s\n", token); // Saída: Hello e world!
        token = strtok(NULL, ", ");
    }
    return 0;
}

int main(){
    strlenFn();
    strcpyFn();
    strncpyFn();
    strcatFn();
    strcmpFn();
    strchrFn();
    strrchrFn();
    strstrFn();
    strpbrkFn();
    strcspnFn();
    strspnFn();
    strtokFn();
    return 0;
}