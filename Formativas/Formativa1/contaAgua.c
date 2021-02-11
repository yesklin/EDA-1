#include <stdio.h>

int main(){
    int num, bill;
    scanf("%d", &num);

    if(num <= 10) bill = 7;
    else if(num > 10 && num <= 30){
        bill = 7 + num-10;
    }
    else if(num > 30 && num <= 100){
        bill = 27 + (num-30)*2;
    }
    else if(num > 100){
        bill = 167 + (num - 100)*5;
    }

    printf("%d\n", bill);
}