#include <stdio.h>

int main(){
    int count = 0;
    int num;
    while(scanf("%d", &num)!=EOF){
        count++;
    }
    printf("%d\n", count);
}