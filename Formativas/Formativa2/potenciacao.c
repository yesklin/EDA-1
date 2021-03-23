#include <stdio.h>

float power(int base, int expoent){
  if(expoent!=0)
    return(base*power(base, expoent-1));
  
  else
    return 1;
}

int main(){
  int base, expoent; 
  scanf("%d%d", &base, &expoent);
  float result;

  if(base==0 && expoent==0) printf("indefinido\n");
  else{
    if(expoent<0){
      expoent = -1*expoent;
      result = 1/power(base, expoent);
      printf("%0.3f\n", result);
    }
    else{
      result = power(base, expoent);
      printf("%0.1f\n", result);
  }
  }


}