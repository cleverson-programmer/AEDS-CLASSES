#include <stdio.h>
#include <string.h>

typedef struct{
    char nome[50];
    float nota;
} Aluno;

void media(Aluno alunos);

int main(){
    int n;

    printf("Digite a quantidade de alunos:");
    scanf("%d", &n);
    getchar(); //SEMPRE USAR getchar(); depois de ler com scanf pois ele deixa o enter no buffer que é pego pelo fgets()

    Aluno alunos[n];

    for(int i = 0; i < n; i++){
        printf("Media aluno %d\n", i + 1);
            printf("Digite o nome do aluno:\n");
            fgets(alunos[i].nome, sizeof(alunos[i].nome), stdin);
            alunos[i].nome[strcspn(alunos[i].nome, "\n")] = '\0';
            printf("Digite a média do aluno: ");
            scanf("%f", &alunos[i].nota);
            getchar();
    }

    for(int i = 0; i < n; i++){
        media(alunos[i]);
    }

    return 0;
}

void media(Aluno alunos){
    float media = alunos.nota;

    printf("%s\t", alunos.nome);

    if(media <= 39){
        printf("F\n");
    }else if(media >= 40 && media <= 59){
        printf("E\n");
    }else if(media >= 60 && media <= 69){
        printf("D\n");
    }else if(media >= 70 && media <= 79){
        printf("C\n");
    }else if(media >= 80 && media <= 89){
        printf("B\n");
    }else if(media > 90){
        printf("A\n");
    }
}