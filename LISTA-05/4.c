// Peça ao usuário que crie uma senha. Utilize um para armazenar a senha. Valide se a senha
// atende aos critérios de segurança, como ter pelo menos 8 caracteres, conter pelo menos uma
// letra maiúscula, uma letra minúscula, um número e um caractere especial. Imprima se a senha é
// válida ou não.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int verify(char password[], int tamanho);
int main(){
    char password[32];
    int tamanho = sizeof(password) / sizeof(password[0]);

    printf("Digite uma senha: ");
    fgets(password, sizeof(password), stdin);
    password[strcspn(password,"\n")] = '\0';

    if(verify(password, tamanho)){
        printf("Válida");
    }else{
        printf("Senha inválida");
    }

    return 0;
}

int verify(char password[], int tamanho){
    int maisc = 0;
    int minusc = 0;
    int num = 0;
    int especial = 0;

    if( strlen(password) < 8){
        return 0;
    }

    for(int i = 0; i < tamanho; i++){
        if(isupper(password[i])) maisc = 1;
        if(islower(password[i])) minusc = 1;
        if(isdigit(password[i])) num = 1;
        if(!isalnum(password[i])) especial = 1;
    }

    if(maisc && minusc && num && especial){
        return 1;
    }else{
        return 0;
    }
}