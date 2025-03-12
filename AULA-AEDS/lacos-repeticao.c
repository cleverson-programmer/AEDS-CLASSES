#include <stdio.h>
#include <stdlib.h>

int main(){
//   EXERCICIO 1
//   int num;
//   printf("Digite um numero: \n");
//   scanf("%d", &num);
//   if(num % 2 == 0) return printf("O numero e par!");
//   else return printf("O numero e impar");

//   EXERCICIO 2
//   int n1,n2,n3;

//   printf("Digite 3 numeros:");
//   scanf("%d %d %d", &n1, &n2, &n3);

//   if(n1 > n2 && n2> n3) return printf("O maior numero e %d", n1);
//   else if(n2 > n1 && n1 > n3) return printf("O maior numero e %d", n2);
//   else return printf("O maior numero e %d", n3);

//   EXERCICIO 3
//   int num;

//   printf("Digite um numero ");
//   scanf("%d", &num);
//   printf("Tabuada\n");
  
//   for( int i = 1; i <= 10; i++){
//     printf("%d * %d = %d\n", num, i, num * i);
//   }

//   EXERCICIO 4
//   int num, temp = 0;

//   printf("Digite um numero que sera somado ate quando voce digitar 0:");

//   while(1){
//     scanf("%d", &num);
//     if (num == 0) break;
//     temp += num;
//   }
//   printf("O resultado e: %d", temp);


//   EXERCICIO 5
//   int num, fat = 1;
  
//   printf("Digite um numero positivo");
//   scanf("%d", &num);

//   int i = num;
//   do {
//     if (i > 0) {
//         fat *= i;
//         i--;
//     }
//   } while (i > 0);

//   printf("Fatorial de %d é %d\n", num, fat);

  //EXERCICIO 6
  int num, primo = 1;

  printf("Digite um número: ");
  scanf("%d", &num);

  if (num < 2) {
      primo = 0;
  } else {
      for (int i = 2; i <= num / 2; i++) {
          if (num % i == 0) {
              primo = 0;
              break;
          }
      }
  }

  if (primo)
      printf("%d é um número primo.\n", num);
  else
      printf("%d não é um número primo.\n", num);
}