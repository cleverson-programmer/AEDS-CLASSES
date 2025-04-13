#include <stdio.h>
#include <string.h>
#include <ctype.h>

// Inverter string
// Crie uma função que receba uma string e a inverta.

int inverter_string(char *str){
    int length = strlen(str);
    char temp;
    //MACA
    for(int i = 0; i < length / 2; i++){
        temp = str[i];

        //Tem que subtrair 1 pois o último elemento do vetor sempre é o \0
        str[i] = str[length - i - 1];
        str[length - i - 1] = temp;
    }

    printf("%s\n", str);
}

int main(){
    char nome[256];
    printf("Digite um nome para inverter:");
    //Forma correta de ler string!
    fgets(nome, sizeof(nome), stdin);

    inverter_string(nome);

    return 0;
}
