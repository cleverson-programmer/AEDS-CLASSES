#include <stdio.h>

int main(){
    int n, total = 0, quant = 0, R = 0, S= 0, C= 0;
    float resultR= 0, resultS = 0, resultC = 0;
    char c;

    printf("Digite a quantidade que deseja:");
    scanf("%d", &n);

    for(int i = 1; i <= n; i++){

        printf("Digite uma quantia e o caractere:");
        scanf("%d %c", &quant, &c);
        if(quant < 1 && quant > 15){
            printf("Valores inválidos");
            break;
        }

        total += quant;

        switch(c){
            case 'R':
                R += quant;
                fflush(stdin);
                break;
            case 'S':
                S += quant;
                fflush(stdin);
                break;
            case 'C':
                C += quant;
                fflush(stdin);
                break;
            default:
                printf("Caracteres inválidos");
        }

    }

    printf("Total: %d cobaias\n", total);
    printf("Total de coelhos: %d\n", C);
    printf("Total de ratos: %d\n", R);
    printf("Total de sapos: %d\n", S);

    resultC = C / total * 100;
    resultR = R / total * 100;
    resultS = S / total * 100;
    printf("Percentual de coelhos: %.2f\n", resultC);
    printf("Percentual de ratos: %.2f\n", resultR);
    printf("Percentual de sapos: %.2f\n", resultS);

    return 0;
}