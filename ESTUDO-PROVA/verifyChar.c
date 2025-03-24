#include <stdio.h>
#include <ctype.h>

//Forma pela tabela ASCII
int verifyChar(char c) {
    if( c >= 'A' && c <= 'Z' || c >= 'a' && c <= 'z') {
        printf("Letra\n");
    } else if( c >= '0' && c <= '9') {
        printf("Dígito\n");
    } else {
        printf("Símbolo especial\n");
    }
    return 0;
}

//**MAIS FACIL**
//Usando lib ctype.h e fn isalpha() e isdigit()
int main() {
    char c;
    printf("Digite um caractere: ");
    scanf(" %c", &c);
    if (isalpha(c)) printf("Letra\n");
    else if (isdigit(c)) printf("Dígito\n");
    else printf("Símbolo especial\n");
    verifyChar(c);
    return 0;
}
