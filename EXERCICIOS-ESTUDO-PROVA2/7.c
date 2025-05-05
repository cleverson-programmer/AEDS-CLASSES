#include <stdio.h>
#include <string.h>

// Faça uma função que receba duas strings e concatene a segunda ao final da primeira usando strcat.

void concat(char *str1, char *str2);

int main(){
    char str1[256];
    char str2[50];

    printf("Digite a primeira string:");
    fgets(str1, sizeof(str1), stdin);

    str1[strcspn(str1, "\n")] = '\0';

    printf("Digite a segunda string:");
    fgets(str2, sizeof(str2), stdin);

    str2[strcspn(str2, "\n")] = '\0';

    concat(str1, str2);

    return 0;
}

void concat(char *str1, char *str2){
    printf("%s", strcat(str1, str2));
}