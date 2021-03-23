#include <stdio.h>

void regua(int num){
  if(num!=0){
    regua(num -1);
    printf(".");
    for(int i = 0; i<num;i++) printf("-");
    printf("\n");
    regua(num - 1);
  }
}

int main(){
  int num;
  scanf("%d", &num);

  regua(num);

}