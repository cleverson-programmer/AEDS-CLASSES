#include <stdio.h>

int main(){
    int n, total = 0, quant = 0, R = 0, S= 0, C= 0;
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
                break;
            case 'S':
                S += quant;
                break;
            case 'C':
                C += quant;
                break;
            default:
                printf("Caracteres inválidos");
        }

    }

    printf("Total: %d cobaias\n", total);
    printf("Total de coelhos: %d\n", C);
    printf("Total de ratos: %d\n", R);
    printf("Total de sapos: %d\n", S);

    float resultC = total;
    float resultR = total;
    float resultS = total;
    printf("Percentual de coelhos: %.2f\n", C / resultC * 100);
    printf("Percentual de ratos: %.2f\n", R / resultR * 100);
    printf("Percentual de sapos: %.2f\n", S / resultS * 100);

    return 0;
}