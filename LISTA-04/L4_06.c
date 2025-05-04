#include <stdio.h>

//Passar uma struct por vez para a fn tem que percorrer o vetor de struct com for e passar o indice da struct, para ler os membros da struct na fn não precisa passar o índice já que estamos passando apenas uma única struct do vetor para a fn.

//Se quiser passar todas as structs de uma vez tem que passar [] na assinatura da função e construção da função, indicando que está passando um vetor de structs, para ler essas structs e acessar seus membros na fn tem que percorrer com for e passar o indice pois estamos passando para a fn um vetor com várias structs.
typedef struct{
    int x;
    int y;
    int z;
} Lines;

void isTriangle(Lines triangle, int index);

int main(){
    int n;
    printf("Digite a quantidade de triângulos que deseja verificar:");
    scanf("%d", &n);

    Lines triangle[n];

    for(int i = 0; i < n; i++){
        printf("%d° triangulo\n", i + 1);

        printf("Digite o valor de x: ");
        scanf("%d", &triangle[i].x);

        printf("Digite o valor de y: ");
        scanf("%d", &triangle[i].y);

        printf("Digite o valor de z: ");
        scanf("%d", &triangle[i].z);
    }

    for(int i = 0; i < n; i++){
        isTriangle(triangle[i], i + 1);
    }

    return 0;

}

void isTriangle(Lines triangle, int index){
        int a = triangle.x;
        int b = triangle.y;
        int c = triangle.z;
        int compare = 0;

        printf("%d° triângulo\n", index);

        if (a + b > c && a + c > b && b + c > a) {
            if (a == b && b == c) {
                compare = 1; // equilátero
            } else if (a == b || a == c || b == c) {
                compare = 2; // isósceles
            } else {
                compare = 3; // escaleno
            }
        } else {
            printf("Não é um triângulo!\n");
            return;
        }

        switch(compare){
            case 1:
                printf("Equilatero\n");
            break;
            case 2:
                printf("Isóceles\n");
            break;
            case 3:
                printf("Escaleno\n");
            break;
        }
}

//Tem como usar a lógica de salvar os valores da struct em um vetor
// for(int j = 0; j < 3; j++){
//     printf("Digite o %d° valor: ", j + 1);
//     scanf("%d", triangle[i].vetor[j]);
// }
