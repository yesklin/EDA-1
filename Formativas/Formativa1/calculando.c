#include <stdio.h>

int main(){
    int number_of_digits, x;

    scanf("%d", &number_of_digits);
    scanf("%d\n", &x);

    if(number_of_digits!=0){
        do{ 
            int sum = 0;
            int num1, num2;
            char op;
            for(int i = 0; i < number_of_digits; i++){
                scanf("%d", &num1);
                scanf("%c", &op);
                scanf("%d", &num2);
                if(op=='+')sum +=num1+num2;
                else sum += num1-num2;
            }

            printf("Results is %d", sum);   
        
        }while(number_of_digits!=0);
    }
    
}