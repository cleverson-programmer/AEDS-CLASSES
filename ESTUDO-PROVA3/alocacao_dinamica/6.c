#include <stdio.h>
#include <stdlib.h>

typedef struct{
    float salario;
    int pessoas;
}Habitantes;

void calcularMedia();

int main(){
    calcularMedia();
    return 0;
}

void calcularMedia(){
    int count = 0;
    Habitantes *populacao = NULL;
    float salario;
    int pessoas;

    do{
        //Alocação dinâmica com realloc para quantidade indefinida de dados
        //Estrutura para alocação dinâmica de struct é sempre essa
        //Nome da struct *ponteiro de struct temporario = (Nome da struct *) realloc(instância da struct permanente, (controle para incrementar o tamanho da memoria + 1) * sizeof(nome da struct para incrementar o tamanho de toda a struct))
        Habitantes *temp = (Habitantes *) realloc(populacao, (count + 1) * sizeof(Habitantes));
         if(temp == NULL){
            printf("Erro de alocação de memória\n");
            //Libera memoria para evitar vazamento
            free(populacao);
            //Encerra o programa
            exit(1);
        }

        //Ponteiro principal recebe o temporário para salvar os dados sem perder os antigos já salvos
        populacao = temp;

        printf("%d° Família:\n", count + 1);
        //Usando uma variavel simples para salvar o valor digitado, depois atribuimos a posição correta da nossa struct usando uma váriavel de controle
        printf("Digite o salario familiar: ");
        scanf("%f", &salario);

        //Verificação para encerrar o loop
        if(salario < 0){
            break;
        }

        printf("Digite a quantidade de membros: ");
        scanf("%d", &pessoas);

        //Atribuindo os valores das váriaveis simples as posições corretas do nosso vetor de struct
        populacao[count].salario = salario;
        populacao[count].pessoas = pessoas;

        //Incrementando o count para o próximo loop
        count++;

    }while(salario > 1);

    //Calculando media e exibindo
    float totalSalario = 0;
    for(int i = 0; i < count; i++){
        totalSalario += populacao[i].salario;
    }

    if(count > 0){
        float media = 0;
        media = totalSalario / count;
        printf("A média salarial é: %.2f", media);
    }else {
        printf("Nenhum dado foi inserido");
    }


    //Sempre lembrar de liberar memória no final
    free(populacao);
}