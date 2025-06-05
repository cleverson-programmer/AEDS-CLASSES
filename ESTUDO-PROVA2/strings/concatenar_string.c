#include <stdio.h>
#include <string.h>

// 9. Concatenar strings (com strcat)
void concat(char *str, char *str2){
    //strncat --> primeiro parametro é o DESTINO que é quem recebe a ORIGEM que é o segundo parametro, ultimo e o tamanho da string
    //strncat --> O primeiro parametro vai ficar no começo da concatenação
     // Adiciona um espaço antes da segunda string
    strcat(str, " ");

    // Concatena a segunda string respeitando o espaço restante
    strcat(str, str2); 

    printf("Resultado da concatenação: %s\n", str);

}

int main(){
    char str[100], str2[50];
    printf("Digite um texto:");
    fgets(str, sizeof(str), stdin);

    printf("Digite outro texto:");
    fgets(str2, sizeof(str2), stdin);

    str[strcspn(str, "\n")] = '\0';
    str2[strcspn(str2, "\n")] = '\0';

    concat(str,str2);

    return 0;
}