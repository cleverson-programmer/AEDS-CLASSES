#include <stdio.h>
#include <string.h>
#include <ctype.h>

typedef struct{
    char nome[50];
    float nota;
} Notas;

void reading();

float average(int n, Notas notas[]);

void print(float media);

int main(){

    reading();
    
    return 0;
}

void reading(){
    int n;
    printf("Digite a quantidade de alunos:");
    scanf("%d", &n);
    getchar();

    Notas notas[n];

    for(int i = 0; i < n; i++){
        printf("%d° aluno:", i + 1);
        fgets(notas[i].nome, sizeof(notas[i].nome), stdin);// Primeiro passa a struct com sua posição no vetor de struct e seu membro. Depois passa o sizeof da mesma e por fim o stdin indicando a entrada padrão que é o teclado.
        printf("Digite a nota do aluno :");
        scanf("%f", &notas[i].nota);
        getchar(); //Sempre usar getchar depois de ler com scanf
    }

    average(n, notas);
}

float average(int n, Notas notas[]){
    float soma = 0;
    float media = 0;
    int count = 0;
    for(int i = 0; i < n; i++){
        if(notas[i].nota >= 6){
            soma += notas[i].nota;
            count ++;
        }
    }

    media = soma / count;

    print(media);
    return media;
}

void print(float media){
    printf("A média dos alunos aprovados é: %.2f", media);
}