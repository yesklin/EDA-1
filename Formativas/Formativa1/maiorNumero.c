#include <stdio.h>

int main(){
    int biggest, num;
    scanf("%d", &biggest);
    for(int i = 0; i<3; i++){
        scanf("%d", &num);
        if(num >= biggest) biggest = num;
    }

    printf("%d\n", biggest);
}