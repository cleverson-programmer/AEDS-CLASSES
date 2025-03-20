#include <stdio.h>
#include <stdlib.h>

int main(){
    float peso, altura, PI, novoPeso;
    char sexo;

    printf("Digite sua altura, peso e sexo (M/F): ");
    scanf("%f %f %c", &altura, &peso, &sexo);

    switch (sexo){
        case 'M':
            PI = (72.7 * altura) - 58;
            if( PI < peso){
                printf("Voce precisa perder %.2f kg\n", peso - PI);
            }else{
                printf("Voce precisa ganhar %.2f kg\n", PI - peso);
            }
            break;
        case 'F':
            PI = (62.1 * altura) - 44.7;
            if( PI < peso){
                printf("Voce precisa perder %.2f kg\n", peso - PI);
            }else{
                printf("Voce precisa ganhar %.2f kg\n", PI - peso);
            }
            break;
        default:
            printf("Sexo invalido\n");
            break;
    }

    return 0;
}