#include <stdio.h>

#include <stdlib.h>


typedef struct stack
{
  int top, size;
  int *v;

} stack;


stack *create_stack(int size){
  stack *new_stack = malloc(sizeof(stack));
  new_stack -> top  = -1;
  new_stack -> v = malloc(new_stack->size*sizeof(int));
  new_stack -> size = size;
}


int unstack_it(stack *stk, int *num){
  
  if(stk->top == -1) return 0;

  *num = stk->v[stk->top];
  stk->top--;
  
  return 1;

}

int stack_it(stack *stk, int num){
  if(stk->top == stk->size-1){
    stk->v = realloc(stk->v, stk->size*2*sizeof(int));
    stk -> size *= 2;
  }
  stk -> top++;
  stk ->v[stk->top] = num;
}

void print_stack(stack *stk){
  for(int i = 0; i < stk-> top+1; i++){
    printf("%d ", stk->v[i]);
  }
  printf("\n");
}

int main(){ 
  stack *pilha = create_stack(3);
  
  stack_it(pilha, 10);
  stack_it(pilha, 20);
  stack_it(pilha, 30);

  print_stack(pilha);

  int num;
  unstack_it(pilha, &num);
  printf("Unstacked: %d\n", num);
  print_stack(pilha);
  stack_it(pilha, 30);
  stack_it(pilha, 40);
  printf("Stacked 30 and 40\n");
  print_stack(pilha);
}
