// Solicite ao usuário que insira uma frase. Utilize vetores para armazenar as palavras da frase.
// Inverta a ordem das palavras na frase (sem inverter a ordem das letras em cada palavra).
// Imprima a frase com as palavras invertidas.

#include <stdio.h>
#include <string.h>

int main(){
    
    char str[256];
    char *palavras[50]; //Vetor de ponteiros para armazenar as palavras
    int contador = 0; //Percorrer as posições do ponteiro de palavras armazenando uma palavra por posição do vetor

    printf("Digite uma frase: ");
    fgets(str, sizeof(str), stdin);

    // Remove o '\n' do final, se existir
    str[strcspn(str, "\n")] = '\0';

    //Quebra a frase em palavras usando o espaço como delimitador
    char *token = strtok(str, " ");

    while(token != NULL){
        palavras[contador++] = token; //Armazena o ponteiro para a palavra
        token = strtok(NULL, " "); // Pega o próximo token
    }

    printf("Frase com palavras invertidas:\n");
    //Percorre o vetor de palavras de trás para frente
    for (int i = contador - 1; i >= 0; i--) {
        printf("%s ", palavras[i]);
    }

    printf("\n");

    return 0;
}