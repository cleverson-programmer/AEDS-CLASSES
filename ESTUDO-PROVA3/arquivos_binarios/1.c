//Gravando e lendo de um vetor de STRUCT

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
    int matricula;
    char nome[50];
    float nota;
} Aluno;

int main(){
    FILE *arquivo;
    Aluno *alunos = NULL;
    int qtd = 0;
    char opcao;

    do{
        Aluno *temp = (Aluno *) realloc(alunos, (qtd + 1) * sizeof(Aluno));
        if(temp == NULL){
            printf("Erro ao alocar memória\n");
            free(alunos);
            exit(1);
        }

        alunos = temp;

        printf("Aluno %d: \n", qtd + 1);

        fflush(stdin);

        printf("Nome: ");
        fgets(alunos[qtd].nome, sizeof(alunos[qtd].nome), stdin);

        printf("Matricula: ");
        scanf("%d", &alunos[qtd].matricula);

        printf("Nota: ");
        scanf("%f", &alunos[qtd].nota);

        qtd++;

        while( (getchar()) != '\n');

        printf("Deseja continuar cadastrando? (S/N): ");
        scanf("%c", &opcao);

        while( (getchar()) != '\n');

    } while(opcao == 's' || opcao == 'S');

    //GRAVANDO OS DADOS

    //Abrindo arquivo para escrita
    arquivo = fopen("alunos.bin", "wb"); // "wb" write binary
    if(arquivo == NULL){
        printf("Erro ao abrir arquivo");
        free(alunos);
        exit(1);
    }

    //Alocando/gravando espaço para a quantidade de alunos
    //Grava no ínicio do arquivo a quantidade de alunos para poder ser lido depois
    fwrite(&qtd, sizeof(int), 1, arquivo);

    //Gravando todos os alunos em sequência
    //Passamos o vetor de struct de Alunos, o tamanho de uma struct, a quantidade de elementos (vetores de struct) e o arquivo no qual vamos salvar
    fwrite(alunos, sizeof(Aluno), qtd, arquivo);

    //Fechando o arquivo
    fclose(arquivo);

    //Liberando memória para evitar acesso ilegal de memória
    free(alunos);

    //LENDO OS DADOS

    arquivo = fopen("alunos.bin", "rb"); // "rb" read binary
    if(arquivo == NULL){
        printf("Erro ao abrir arquivo para leitura");
        exit(1);
    }

    //Variável para ler a quantidade de arquivos gravadas no ínicio quando salvamos os dados na struct
    //Se não salvarmos a quantidade podemos ler lixo pois não sabemos ao certo a quantidade de registros no arquivo;
    //Precisa dessa variavel e de salvar a quantidade na hora de gravar os dados pois se reinciarmos o programa perdemos o valor da quantidade salvo na variavel qtd
    int qtd_lida;

    fread(&qtd_lida, sizeof(int), 1, arquivo); // lê quantidade de alunos, agora qtd_lida tem o mesmo valor de qtd pois já tinhamos salvados essa informação no arquivo

    // Aloca memória para ler os dados do arquivo
    //Dessa forma alocamos memória para o tamanho exato em bytes que representa a quantidade de registros que temos gravados
    Aluno *lidos = (Aluno *) malloc(qtd_lida * sizeof(Aluno));
    if (lidos == NULL) {
        printf("Erro ao alocar memória para leitura.\n");
        fclose(arquivo);
        return 1;
    }

    //Lendo os dados
    //Passamos o vetor, o tamanho de uma struct, a quantidade de registros e o arquivo do qual vamos ler
    fread(lidos, sizeof(Aluno), qtd_lida, arquivo); // lê os dados
    fclose(arquivo);

    // ==== Mostrar alunos lidos ====
    printf("\n=== Alunos Lidos do Arquivo ===\n");
    for (int i = 0; i < qtd_lida; i++) {
        printf("ID: %d | Nome: %s | Nota: %.2f\n",
               lidos[i].matricula, lidos[i].nome, lidos[i].nota);
    }

    free(lidos); // libera memória final
    return 0;
}