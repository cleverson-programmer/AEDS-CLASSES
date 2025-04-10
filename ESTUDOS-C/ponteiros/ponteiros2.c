#include <stdio.h>

//EM VETORES E MATRIZES SEMPRE USAMOS LAÇO FOR PARA PERCORRER OS ELEMENTOS, MANIPULAR E IMPRIMI-LOS!!!

// Função que dobra os valores de um vetor
// A função recebe um ponteiro para inteiro (int *) e o tamanho do vetor
void dobrarElementos(int *vetor, int tamanho) {
    // Loop que percorre o vetor usando ponteiro
    for (int i = 0; i < tamanho; i++) {
        // *(vetor + i) é equivalente a vetor[i]
        *(vetor + i) = *(vetor + i) * 2;
        //vetor[i] = vetor[i] * 2;
    }
}

int main() {
    // Declaração e inicialização do vetor
    int numeros[] = {1, 2, 3, 4, 5};
    int tamanho = 5;

    // Chamada da função que modifica o vetor
    dobrarElementos(numeros, tamanho);
    //Passamos o endereço do primeiro elemento do vetor para a fn, NÃO PASSAMOS COM &
    // pois o nome do vetor já é um ponteiro para o primeiro elemento do vetor EX: numeros == &numeros[0];
    //Se passamos com &numeros, estaríamos passando o endereço do vetor inteiro, não do primeiro elemento
    //Com isso, causaria um erro de segmentação, pois a função espera um ponteiro para inteiro e não um ponteiro para vetor


    // Impressão dos valores do vetor após modificação
    printf("Vetor após dobrar os valores:\n");
    for (int i = 0; i < tamanho; i++) {
        printf("%d ", numeros[i]);
    }

    return 0;
}


// Função que recebe um ponteiro para um vetor de 5 inteiros
void dobrarElementosVetorCompleto(int (*vetor)[5]) {
    for (int i = 0; i < 5; i++) {
        // Acessa o vetor com a notação (*vetor)[i]
        // Tambem pode ser usado vetor[i] = vetor[i] * 2;
        (*vetor)[i] = (*vetor)[i] * 2;
    }
}

int enderecoVetorInteiro() {
    // Vetor de 5 inteiros
    int valores[5] = {1, 2, 3, 4, 5};

    // Aqui passamos o ENDEREÇO do vetor inteiro
    // Isso significa: um ponteiro para um vetor de 5 inteiros
    dobrarElementosVetorCompleto(&valores);

    // Imprime o vetor modificado
    printf("Vetor após dobrar os valores:\n");
    for (int i = 0; i < 5; i++) {
        printf("%d ", valores[i]);
    }

    return 0;
}