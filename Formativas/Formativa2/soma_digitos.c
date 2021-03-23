#include <stdio.h>

int sum(char* digits, int initial_index){
  
  if(digits[initial_index]!='\0'){
    int digit_value = digits[initial_index] - '0';
    return(digit_value + sum(digits, initial_index+1));
  }
  else return 0;

}

int main()
{
  long number;
  char digits[20];
  
  scanf("%ld", &number);
  sprintf(digits, "%ld", number);

  int result = sum(digits, 0);
  printf("%d\n", result);

  
}