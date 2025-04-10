// #include <stdio.h>

// int main(){

//     int n = 99;

//     while(n >= 1){
//         printf("%d\n", n);
//         n -= 2;
//     }

//     return 0;
// }

// int media(){
//     int n, count = 0;
//     float soma = 0;

//     do{
//         printf("Digite um numero: ");
//         scanf("%d", &n);
//             if(n != 0){
//                 soma += n;
//                 count++;
//             }
//     } while(n != 0);

//     printf("A media: %.2f\n", soma/count);
// }

// int primo(){
//     int n, i = 1, count = 0;
//     printf("Digite um numero: ");
//     scanf("%d", &n);

//     while( i <= n){
//         if(n % i == 0){
//             count++;
//         }
//         i++;
//     }

//     if(count == 2){
//         printf("%d eh primo\n", n);
//     } else {
//         printf("%d nao eh primo\n", n);
//     }
//     return 0;
// }

#include <stdio.h>

int main() {
    int n, a = 0, b = 1, next = 0;
    printf("Digite um numero: ");
    scanf("%d", &n);
    printf("1 ");
    for(int i = 2; i <= n; i++) {
        next = a + b;
        a = b;
        b = next;
        printf("%d ", next);
    }
    return 0;
}