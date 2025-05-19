#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
    char nome[50];
    int idade;
    float nota;
}Usuario;


int main(){
    Usuario *usuario = NULL;
    FILE *arquivo;

    int count = 0;
    char c;

    do{
        //Alocação de memória
        Usuario *temp = (Usuario *) realloc(usuario, (count + 1) * sizeof(Usuario));
        if(temp == NULL){
            printf("Erro na alocação");
            free(usuario);
            exit(1);
        }

        usuario = temp;

        //Abrindo arquivo
        arquivo = fopen("usuarios.txt", "a");

        //Testando arquivo
        if(arquivo == NULL){
            printf("Erro ao abrir arquivo!");
            return 1;
        }

        //Limpando buffer entrada padrão
        fflush(stdin);

        //Lendo dados
        printf("Digite o nome do %d° usuário: ", count + 1);
        fgets(usuario[count].nome, sizeof(usuario[count].nome), stdin);
        usuario[count].nome[strcspn(usuario[count].nome, "\n")] = '\0';

        printf("Digite a idade:");
        scanf("%d", &usuario[count].idade);

        printf("Digite a nota: ");
        scanf("%f", &usuario[count].nota);

        //Salvando dados nos arquivos
        fprintf(arquivo, "Nome: %s | Idade: %d | Nota: %.2f\n", usuario[count].nome, usuario[count].idade, usuario[count].nota);

        //Fechando o arquivo
        fclose(arquivo);

        count++;

        while( (getchar()) != '\n');

        printf("Deseja continuar: S/N");
        scanf("%c", &c);

        while( (getchar()) != '\n');

    }while(c == 's' || c == 'S');

    //Liberando memória
    free(usuario);

    return 0;
}