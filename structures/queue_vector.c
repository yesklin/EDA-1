#include <stdio.h>
#include <stdlib.h>

typedef struct queue{
  int beginning;
  int end;
  int size;
  int *vector;
} queue;

queue *create_queue(int size){
  queue *new_queue = malloc(sizeof(queue));
  
  new_queue -> beginning = 0;
  new_queue -> end = 0;

  new_queue -> size = size;
  
  new_queue -> vector = malloc(size*sizeof(int));

  return new_queue;
}

int insert(queue *q, int num){
  
  if((q->end+1)%q->size == q->beginning){
    return 0;
  }

  q -> vector[q->end] = num;
  q -> end = (q->end+1)%q->size;
  return 1;

}

int remmove(queue *q, int *num){
  if(q->end == q->beginning){
    return 0;
  }

  *num = q->vector[q->beginning];
  q->beginning = (q->beginning+1)%q->size;
  return 1;

}

void print_queue(queue *q){
  for(int i = q->beginning; i!=q->end; i = (i+1)%q->size){
    printf("%d ", q->vector[i]);
  }
  printf("\n");
}

int main(){
  queue *f = create_queue(5);
  insert(f, 1);
  insert(f, 2);
  insert(f, 3);
  insert(f, 4);
  if(insert(f, 5) == 0) printf("Cannot insert more!\n");
  print_queue(f);
}