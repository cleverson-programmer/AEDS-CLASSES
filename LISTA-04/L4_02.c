#include <stdio.h>
#include <ctype.h>

typedef struct{
    float salario;
    int pessoas;
} Habitantes;

void calcularMedia();

int main(){
    calcularMedia();
    return 0;
}

void calcularMedia(){
    Habitantes populacao[100];

    int count = 0;
    int membros;
    float salario;

    do{
        printf("Familia %d:\n", count + 1);
        printf("Digite o salário familiar: ");
        scanf("%f", &salario);

        if(salario < 1){
            break;
        }

        printf("Digite a quantidade de membros da familia: ");
        scanf("%d", &membros);

        populacao[count].pessoas = membros;
        populacao[count].salario = salario;
        count ++;

        if (count >= 100) {
            printf("Limite de famílias atingido.\n");
            break;
        }

    }while(salario > 1);

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
}