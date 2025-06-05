#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char modelo[50];
    char fabricante[50];
    float autonomia;
    float capacidade;
} Carro;

void salvarBinario(const char *nomeArquivo, Carro melhor) {
    FILE *f = fopen(nomeArquivo, "wb");
    if (!f) {
        printf("Erro ao abrir o arquivo para escrita.\n");
        return;
    }
    fwrite(&melhor, sizeof(Carro), 1, f);
    fclose(f);
    printf("Carro com melhor km/L salvo em %s\n", nomeArquivo);
}

void visualizarBinario(const char *nomeArquivo) {
    FILE *f = fopen(nomeArquivo, "rb");
    if (!f) {
        printf("Erro ao abrir o arquivo para leitura.\n");
        return;
    }
    Carro c;
    fread(&c, sizeof(Carro), 1, f);
    fclose(f);

    float rendimento = c.autonomia / c.capacidade;
    printf("\nCarro com melhor rendimento:\n");
    printf("Modelo: %s\n", c.modelo);
    printf("Fabricante: %s\n", c.fabricante);
    printf("Autonomia: %.2f km\n", c.autonomia);
    printf("Capacidade do tanque: %.2f L\n", c.capacidade);
    printf("Rendimento: %.2f km/L\n", rendimento);
}

int main() {
    Carro carros[5];
    const char *arquivo = "carro_melhor.bin";

    printf("Cadastro de 5 carros:\n");
    for (int i = 0; i < 5; i++) {
        printf("\nCarro %d:\n", i + 1);
        printf("Modelo: ");
        fgets(carros[i].modelo, sizeof(carros[i].modelo), stdin);
        carros[i].modelo[strcspn(carros[i].modelo, "\n")] = '\0';

        printf("Fabricante: ");
        fgets(carros[i].fabricante, sizeof(carros[i].fabricante), stdin);
        carros[i].fabricante[strcspn(carros[i].fabricante, "\n")] = '\0';

        printf("Autonomia (km): ");
        scanf("%f", &carros[i].autonomia);

        printf("Capacidade do tanque (L): ");
        scanf("%f", &carros[i].capacidade);
        while (getchar() != '\n');
    }

    int melhorIndice = 0;
    float melhorKmL = carros[0].autonomia / carros[0].capacidade;

    for (int i = 1; i < 5; i++) {
        float atualKmL = carros[i].autonomia / carros[i].capacidade;
        if (atualKmL > melhorKmL) {
            melhorKmL = atualKmL;
            melhorIndice = i;
        }
    }

    salvarBinario(arquivo, carros[melhorIndice]);

    char opcao;
    printf("\nDeseja visualizar os dados do carro com melhor km/L? (s/n): ");
    scanf(" %c", &opcao);
    if (opcao == 's' || opcao == 'S') {
        visualizarBinario(arquivo);
    }

    return 0;
}

