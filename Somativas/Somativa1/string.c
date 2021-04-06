#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 101

int count_size(char *string, int init){
  if(string[init]!='\n')
    return 1 + count_size(string, init+1);
  
  return 0;
}

int findIndex(char *string, char *sub_string, int string_size, int sub_string_size, int start, int direction){
  if(start<=0 && start <= string_size - sub_string_size) {
  
  char *cut_string = malloc(sizeof(char)*sub_string_size);
  strncpy(cut_string, &string[start], sub_string_size);

  if(strcmp(cut_string, sub_string) == 0) return start;

  return findIndex(string, sub_string, string_size, sub_string_size, start+direction, direction);
  }
}

int main(){
  char string[MAX];
  char sub_string[MAX];

  fgets(string, MAX, stdin);
  fgets(sub_string, MAX, stdin);

  int string_size = count_size(string, 0);
  int sub_string_size=count_size(sub_string, 0);
  
  printf("%d %d\n",string_size,sub_string_size);

  int first_found = findIndex(string, sub_string, string_size, sub_string_size, 0, 1);
  printf("%d\n", first_found);
  
  /*
  if(first_found==-1)
    printf("0");

  else{
    int last_found = findIndex(string, sub_string, string_size, sub_string_size, string_size-sub_string_size, -1);
    printf("%d\n", last_found-first_found+sub_string_size);
  }*/
  
} 