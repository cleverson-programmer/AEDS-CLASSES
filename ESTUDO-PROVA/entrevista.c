#include <stdio.h>
#include <stdlib.h>

int main() {
    int age, like, countM, countF;
    char genero;
    int oldM = 0, oldF = 0;
    int likeM = 0, likeF = 0;
    int total = 0, totalDislike = 0;
    
    do{
        printf("Digite seu genero:\n");
        scanf(" %c", &genero);
        printf("Digite se gosta do produto:\n");
        scanf(" %d", &like);
        printf("Digite sua idade:\n");
        scanf(" %d", &age);

        switch(genero){
            case 'M':
                countM ++;
                if(age > oldM){
                    oldM = age;
                }
                if(like){
                    likeM++;
                }
            break;
            case 'F':
                countF++;
                
                if(age > oldF){
                    oldF = age;
                }
                if(like){
                    likeF++;
                }
            break;
        }
        
        total = countM + countF;
        totalDislike = total - (likeM + likeF);
    }while( age > 0);

    printf("A pessoa mais velha do genero masculino tem: %d\n", oldM);
    printf("A pessoa mais velha do genero feminino tem %d\n", oldF);
    printf("%d mulheres que gostaram do produto\n", countF);
    printf("%d homens que gostaram do produto\n", countM);
    printf("O total de pessoas que não gostaram e: %d\n",  totalDislike);
}