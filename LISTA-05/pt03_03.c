// Peça ao usuário que insira duas strings. Utilize vetores para armazenar as duas strings.
// Concatene as duas strings em uma terceira. Imprima a string resultante

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
    char str1[32];
    char str2[32];
    char str3[64];

    printf("Digite a primeira string: ");
    fgets(str1, sizeof(str1), stdin);

    str1[strcspn(str1, "\n")] = '\0';

    printf("Digite a segunda string: ");
    fgets(str2, sizeof(str2), stdin);

    str2[strcspn(str2, "\n")] = '\0';

    //destino origem --> conteudo da str1 vai para a str3
    strcpy(str3, str1);

    //destno origem --> conteúdo da str2 vai para str3 que é a nova string que contém o conteúdo inicial da str1.
    strcat(str3, str2);

    printf("String: %s\n", str3);

    return 0;
}