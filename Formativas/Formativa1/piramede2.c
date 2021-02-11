#include <stdio.h>

int main(){
    int num;
    scanf("%d", &num);

    for(int i = 0; i < num; i++){
        int number_of_stars = 1 + i*2;
        int number_of_blank_spaces = num-1-i;
        for(int j = 0; j <  number_of_blank_spaces; j++)printf(" ");
        for(int j = 0; j < number_of_stars; j++)printf("*");
        printf("\n");
    }
}