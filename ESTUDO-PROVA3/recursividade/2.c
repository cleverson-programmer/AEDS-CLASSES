#include <stdio.h>
#include <string.h>

void trocar(char *a, char *b){
    char temp = *a;
    *a = *b;
    *b = temp;
}

//Função recursiva para gerar permutação
void permutar(char *str, int inicio, int fim){
    if(inicio == fim){
        //Qaundo o inicio atinge o final da string temos uma permutação completa
        printf("%s\n", str);
    }else{
        // Itera sobre cada caractere da string para fixá-lo na posição 'inicio'
        for (int i = inicio; i <= fim; i++) {
            // Troca o caractere atual com o da posição 'inicio'
            trocar(&str[inicio], &str[i]);

            // Chamada recursiva com o próximo índice fixo (inicio + 1)
            permutar(str, inicio + 1, fim);

            // Desfaz a troca (backtracking)
            trocar(&str[inicio], &str[i]);
        }
    }
}

int main(){
    char str[100];

    printf("Digite uma string para permutar: ");
    fgets(str, sizeof(str), stdin);

    str[strcspn(str, "\n")] = '\0';

    int tamanho = strlen(str);

    printf("Permutações: \n");
    permutar(str,0, tamanho - 1);

    return 0;
}