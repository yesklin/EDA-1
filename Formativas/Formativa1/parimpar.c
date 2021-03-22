#include <stdio.h>
#include <stdlib.h>

int main(){
    

    int number_of_rounds, x;
    scanf("%d", &number_of_rounds);

    if(number_of_rounds!=0){
        int matchs = 0;
        do{
            matchs++;
            scanf("%d\n", &x);
            char name1[11], name2[11];
            scanf("%s", name1);
            scanf("%s", name2);
            fflush(stdin);
            printf("Teste %d\n", matchs);
            for(int i = 0; i < number_of_rounds; i++){
                int num1, num2;
                scanf("%d%d", &num1, &num2);
                if((num1+num2)%2==0)printf("%s\n", name1);
                else printf("%s\n", name2);
            }

            scanf("%d", &number_of_rounds);
            if(number_of_rounds!=0)printf("\n");

        }while(number_of_rounds!=0);
    }
}