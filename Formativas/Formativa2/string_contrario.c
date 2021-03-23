#include <stdio.h>

int count(char *string, int initial_index)
{ 
  if(string[initial_index]!='\0')
  {
    return(1 + count(string, initial_index+1));
  }
  return 0;
}

void print_string(char *string, int initial_index)
{

  if(initial_index>=0)
  {
    printf("%c", string[initial_index]);
    print_string(string, initial_index-1);
  }
}

int main()
{
  char string[502];
  fgets(string, 502, stdin);

  int number_of_letters = count(string, 0);
  print_string(string, number_of_letters-2);
  printf("\n");
}