#include <stdio.h>

int main(){
    int num;
    scanf("%d", &num);

    for(int i = 1; i <= num; i++){
        for(int j = 0; j < i; j++){
            printf("%02d ", i);
        }
        printf("\n");
    }
    printf("\n");

    for(int i = 1; i <=num; i++){
        for(int j = 0; j < i; j++){
            printf("%02d ", j+1);
        }
        printf("\n");
    }

}