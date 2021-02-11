#include <stdio.h>

int main(){
    int num, biggest;
    scanf("%d", &biggest);

    while(scanf("%d", &num)!=EOF){
        if(num>biggest)biggest=num;
    }

    printf("%d\n", biggest);
}