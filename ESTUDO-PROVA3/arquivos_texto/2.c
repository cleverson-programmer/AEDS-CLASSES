#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char nome[50];
    int idade;
    float nota;
} Usuario;

void salvarUsuario();
void lerUsuarios();
void atualizarUsuario();
void excluirUsuario();

int main() {
    int opcao;

    do {
        printf("\n=== MENU ===\n");
        printf("1. Salvar usuário\n");
        printf("2. Ler usuários\n");
        printf("3. Atualizar usuário\n");
        printf("4. Excluir usuário\n");
        printf("5. Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);
        getchar(); // consumir '\n' deixado pelo scanf

        switch (opcao) {
            case 1: salvarUsuario(); break;
            case 2: lerUsuarios(); break;
            case 3: atualizarUsuario(); break;
            case 4: excluirUsuario(); break;
            case 5: printf("Saindo...\n"); break;
            default: printf("Opção inválida.\n");
        }
    } while (opcao != 5);

    return 0;
}

void salvarUsuario() {
    FILE *arquivo = fopen("usuarios.txt", "a"); // "a" para adicionar no final
    if (arquivo == NULL) {
        perror("Erro ao abrir o arquivo");
        return;
    }

    Usuario u;
    printf("Digite o nome: ");
    fgets(u.nome, sizeof(u.nome), stdin);
    u.nome[strcspn(u.nome, "\n")] = '\0'; // remove o '\n'

    printf("Digite a idade: ");
    scanf("%d", &u.idade);

    printf("Digite a nota: ");
    scanf("%f", &u.nota);
    getchar(); // consumir '\n'

    fprintf(arquivo, "%s %d %.2f\n", u.nome, u.idade, u.nota);
    fclose(arquivo);
    printf("Usuário salvo com sucesso!\n");
}

void lerUsuarios() {
    FILE *arquivo = fopen("usuarios.txt", "r");
    if (arquivo == NULL) {
        perror("Erro ao abrir o arquivo");
        return;
    }

    Usuario u;
    printf("\n=== Lista de Usuários ===\n");
    while (fscanf(arquivo, "%s %d %f", u.nome, &u.idade, &u.nota) == 3) {
        printf("Nome: %s | Idade: %d | Nota: %.2f\n", u.nome, u.idade, u.nota);
    }

    fclose(arquivo);
}

void atualizarUsuario() {
    FILE *arquivo = fopen("usuarios.txt", "r");
    if (arquivo == NULL) {
        perror("Erro ao abrir o arquivo");
        return;
    }

    FILE *temp = fopen("temp.txt", "w");
    if (temp == NULL) {
        perror("Erro ao criar arquivo temporário");
        fclose(arquivo);
        return;
    }

    char nomeBusca[50];
    Usuario u;
    int encontrado = 0;

    printf("Digite o nome do usuário a ser atualizado: ");
    fgets(nomeBusca, sizeof(nomeBusca), stdin);
    nomeBusca[strcspn(nomeBusca, "\n")] = '\0';

    while (fscanf(arquivo, "%s %d %f", u.nome, &u.idade, &u.nota) == 3) {
        if (strcmp(u.nome, nomeBusca) == 0) {
            printf("Digite o novo nome: ");
            fgets(u.nome, sizeof(u.nome), stdin);
            u.nome[strcspn(u.nome, "\n")] = '\0';
            printf("Digite a nova idade: ");
            scanf("%d", &u.idade);
            printf("Digite a nova nota: ");
            scanf("%f", &u.nota);
            getchar(); // consumir '\n'
            encontrado = 1;
        }
        fprintf(temp, "%s %d %.2f\n", u.nome, u.idade, u.nota);
    }

    fclose(arquivo);
    fclose(temp);

    remove("usuarios.txt");
    rename("temp.txt", "usuarios.txt");

    if (encontrado)
        printf("Usuário atualizado com sucesso!\n");
    else
        printf("Usuário não encontrado.\n");
}

void excluirUsuario() {
    FILE *arquivo = fopen("usuarios.txt", "r");
    if (arquivo == NULL) {
        perror("Erro ao abrir o arquivo");
        return;
    }

    FILE *temp = fopen("temp.txt", "w");
    if (temp == NULL) {
        perror("Erro ao criar arquivo temporário");
        fclose(arquivo);
        return;
    }

    char nomeBusca[50];
    Usuario u;
    int encontrado = 0;

    printf("Digite o nome do usuário a ser excluído: ");
    fgets(nomeBusca, sizeof(nomeBusca), stdin);
    nomeBusca[strcspn(nomeBusca, "\n")] = '\0';

    while (fscanf(arquivo, "%s %d %f", u.nome, &u.idade, &u.nota) == 3) {
        if (strcmp(u.nome, nomeBusca) != 0) {
            fprintf(temp, "%s %d %.2f\n", u.nome, u.idade, u.nota);
        } else {
            encontrado = 1;
        }
    }

    fclose(arquivo);
    fclose(temp);

    remove("usuarios.txt");
    rename("temp.txt", "usuarios.txt");

    if (encontrado)
        printf("Usuário excluído com sucesso!\n");
    else
        printf("Usuário não encontrado.\n");
}
