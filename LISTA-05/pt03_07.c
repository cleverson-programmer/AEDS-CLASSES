// Peça ao usuário que crie uma senha. Utilize vetores para armazenar a senha. Valide se a senha
// atende aos critérios de segurança, como ter pelo menos 8 caracteres, conter pelo menos uma
// letra maiúscula, uma letra minúscula, um número e um caractere especial. Imprima se a senha
// é válida ou não

#include <stdio.h>
#include <string.h>
#include <ctype.h>

void verify(char password[]);

int main(){
    char password[32];

    printf("Digite uma senha: ");
    fgets(password, sizeof(password), stdin);

    password[strcspn(password, "\n")] = '\0';

    verify(password);
    
    return 0;
}

void verify(char password[]){
    int length = 0, digit = 0, maisc = 0, minusc = 0, especial = 0;

    if(strlen(password) >= 8){
        length++;
    }

    for(int i = 0; password[i] != '\0'; i++){
        if(isupper(password[i])) maisc ++;
        if(islower(password[i])) minusc ++;
        if(isdigit(password[i])) digit ++;
        if(isalpha(password[i])) especial ++;
    }

    if(length && digit && maisc && minusc && especial){
        printf("Senha válida!");
    }else{
        printf("Senha inválida!");
    }
}