#include <stdlib.h>
#include <stdio.h>

typedef struct Node{
  int data;
  struct Node *next;
} Node;

Node *create_node(){
  Node *new_node = malloc(sizeof(Node));
  new_node->next = NULL;
  return new_node;
}

int push_node(Node *head, int data){ //puts new node in the beggining.
  Node *new_node = create_node();
  
  if(new_node==NULL)return 0; //if it fails to create new node;
  new_node -> data = data;
  new_node -> next = head -> next;

  head -> next = new_node;
  return 1;
}

int pop_node(Node *head, int *number){ //removes first node.
  if(head->next==NULL) return 0;
  
  *number = head->next->data;
  Node *to_free = head ->  next;

  head ->  next = head ->next->next;
  free(to_free);
 
  return 1;
}

void reverse_list(Node *list){
}

void print_list(Node *list){
  if(list->next!=NULL){
    printf("%d ", list->next->data);
    print_list(list->next);
  }
}

void print_reverse_list(Node *list){
  if(list->next!=NULL){
    print_reverse_list(list->next);
    printf("%d ", list->next->data);
  }
}


int main(){
  Node *list = create_node();

  push_node(list, 30);
  push_node(list, 20);
  push_node(list, 10);
  print_reverse_list(list);

}
