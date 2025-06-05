#include <stdio.h>
#include <string.h>

int compare( char *str, char *str2){
    
    return strcmp(str, str2);
}

int main(){
    char str[256], str2[256];
    printf("Digite um texto:");
    fgets(str, sizeof(str), stdin);
    
    printf("Digite outro texto:");
    fgets(str2, sizeof(str2), stdin);

    str[strcspn(str, "\n")] = '\0';
    str2[strcspn(str2, "\n")] = '\0';

    int result = compare(str, str2);
    printf("\n%d\n", result);

    return 0;
}