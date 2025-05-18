// Solicite ao usuário que insira duas palavras. Utilize vetores para armazenar as palavras.
// Verifique se as duas palavras são anagramas uma da outra (ou seja, se contêm as mesmas
// letras, independentemente da ordem). Imprima se as palavras são anagramas ou não.

#include <stdio.h>
#include <string.h>

// Função para ordenar letras de uma palavra (bubble sort simples)
void ordenar(char str[]) {
    int i, j;
    int tamanho = strlen(str);
    char temp;

    for (i = 0; i < tamanho - 1; i++) {
        for (j = i + 1; j < tamanho; j++) {
            if (str[i] > str[j]) {
                temp = str[i];
                str[i] = str[j];
                str[j] = temp;
            }
        }
    }
}

void anagrama(char palavra1[], char palavra2[]){

    // Verifica se têm o mesmo tamanho
    if (strlen(palavra1) != strlen(palavra2)) {
        printf("Não são anagramas.\n");
    }

    // Cria cópias das palavras para ordenar
    char copia1[32], copia2[32];
    strcpy(copia1, palavra1);
    strcpy(copia2, palavra2);

    // Ordena as letras de cada palavra
    ordenar(copia1);
    ordenar(copia2);

    // Compara as palavras ordenadas
    if (strcmp(copia1, copia2) == 0) {
        printf("São anagramas.\n");
    } else {
        printf("Não são anagramas.\n");
    }
}

int main(){
    char str[32];
    char *palavras[50]; //Vetor de ponteiros para armazenar palavras
    int count = 0; //Contador para percorrer os indices e salvar as palavaras

    printf("Digite 2 palavras: ");
    fgets(str, sizeof(str), stdin);

    str[strcspn(str, "\n")] = '\0';

    char *token = strtok(str, " ");

    while(token != NULL){
        palavras[count] = token;
        count++;
        token = strtok(NULL, " ");//Pega o proximo token
    }

    printf("Quantidade de palavras: %d\n", count);

    for(int i = 0; i < count; i++){
        printf("%d°- %s\n", i + 1, palavras[i]);
    }


    //ANAGRAMA
    anagrama(palavras[0], palavras[1]);

    return 0;
}