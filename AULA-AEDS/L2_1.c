#include <stdio.h>
#include <stdlib.h>

int main(){
    int a, b, c, temp;

    printf("Digite o primeiro numero: ");
    scanf("%d", &a);
    printf("Digite o segundo numero: ");
    scanf("%d", &b);
    printf("Digite o terceiro numero: ");
    scanf("%d", &c);

    if(a > b) {
        temp = a; 
        a = b; 
        b = temp;
    }
    if(a > c){
        temp = a; 
        a = c; 
        c = temp;
    }
    if(b > c ){
        temp = b; 
        b = c; 
        c = temp;
    }

    printf("Menor: %d\n", a);
    printf("Meio: %d\n", b);
    printf("Maior: %d\n", c);
    return 0;
}