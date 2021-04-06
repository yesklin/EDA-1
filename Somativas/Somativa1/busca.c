#include <stdlib.h>
#include <stdio.h>
#include <math.h>


typedef struct cloud{
  long old_position;
  int value;
}cloud;

void swap(cloud *a, cloud *b){
  //changing values
  int aux = a->value;
  a->value = b->value;
  b->value = aux;

  //changing old_positions
  long aux_position = a ->old_position;
  a->old_position = b->old_position;
  b->old_position = aux_position;

}

int split(cloud *array, long low, long high){
  long pivor = array[high].value;
  long aux = (low-1);
  for(long j = low; j <= high-1; j++){
    if(array[j].value < pivor){
      aux++;
      swap(&array[aux], &array[j]);
    }
  }
  swap(&array[aux+1], &array[high]);
  return aux+1;

}

void quickSort(cloud *array, long low, long high){
  if(high > low){

    long pivor = split(array, low, high);

    quickSort(array, low, pivor-1);
    quickSort(array, pivor+1, high);

  }
}


long binary_search(int search, cloud *array, long bottom, long top){
  
  while(bottom <= top){
    long middle_index = floor((bottom+top)/2);
    
    if(array[middle_index].value == search) return array[middle_index].old_position;
    
    else if(array[middle_index].value < search) bottom = middle_index+1;

    else top = middle_index-1;
  }

  return -1;

}


int main(){
  long set_size, number_of_searchs;
  scanf("%ld %ld", &set_size, &number_of_searchs);


  struct  cloud *set = malloc(sizeof(cloud)*set_size);
  for(long i = 0; i < set_size; i++){
    scanf("%d", &set[i].value);
    set[i].old_position = i;
  }

  quickSort(set, 0, set_size-1); //working

  /*for(long i = 0; i < set_size; i++){//testing quickSort
    printf("%d ", set[i].value);
  }
  printf("\n");*/

  int search;
  for(long i = 0; i < number_of_searchs; i++){
    scanf("%d", &search);
    printf("%ld\n", binary_search(search, set, 0, set_size-1));
  }

  free(set);

}