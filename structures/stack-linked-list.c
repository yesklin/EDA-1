#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
  int data;
  struct node *next;

} node;


node *create_stack(){
  node *new_stack = malloc(sizeof(node));
  new_stack -> next =  NULL;
  return new_stack;
}

int push(node *stk, int number){
  node *new_node = malloc(sizeof(node));
  new_node -> data = number;
  new_node -> next = stk->next;
  stk -> next = new_node;

  return 1;
}

int pop(node *stk, int *number){
  if(stk -> next != NULL){
    *number = stk -> next -> data;
    node *garbage = stk->next;
    stk -> next = stk -> next -> next;
    free(garbage);
  }
}

void print_stack(node *stk){
  if(stk -> next != NULL){
    printf("%d ", stk -> next -> data);
    print_stack(stk -> next);
  }
  else{
    printf("\n");
  }
}


int main(){
  node *pilha = create_stack();
  
  push(pilha, 10);
  push(pilha, 20);
  push(pilha, 30);

  print_stack(pilha);
  int num;
  pop(pilha, &num);
  printf("Unstacked %d\n", num);

  push(pilha, 30);
  push(pilha, 40);
  push(pilha, 50);

  print_stack(pilha);
}