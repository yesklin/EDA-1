#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct house{
  int old_position;
  long house_number;
}house;


void swap(house *a, house *b){
  //swaping old_positions
  int aux_position = a->old_position;
  a->old_position = b->old_position;
  b->old_position = aux_position;

  //swaping house_number
  long aux_house_number = a->house_number;
  a->house_number = b->house_number;
  b->house_number = aux_house_number;
}


long split(house *rua, long low, long high){
  long pivor = rua[high].house_number;
  long aux = (low-1);

  for(long j  = low; j <= high-1; j++){
    if(rua[j].house_number < pivor){
      aux++;
      swap(&rua[aux], &rua[j]);
    }
  }

  swap(&rua[aux+1], &rua[high]);
  return(aux+1);
}


void quickSort(house *rua, long low, long high){
  if(low < high){

    long pivor = split(rua, low, high);

    quickSort(rua, low, pivor-1);
    quickSort(rua, pivor+1, high);
  }
}

int search(long house_number, house *rua, int bottom, int top){
  while(bottom <= top){
    int middle_position = floor((top+bottom)/2);

    if(rua[middle_position].house_number == house_number) return rua[middle_position].old_position;

    else if(rua[middle_position].house_number > house_number) top = middle_position-1;

    else  bottom = middle_position+1;
  }
}

int main(){
  int number_of_houses, number_of_packages;
  scanf("%d %d", &number_of_houses, &number_of_packages);

  struct house *rua = malloc(sizeof(house)*number_of_houses);
  
  for(int i = 0; i < number_of_houses; i++) {//reading
    scanf("%ld", &rua[i].house_number);
    rua[i].old_position = i;
  }

  quickSort(rua, 0, number_of_houses-1);


  int current_position = 0;
  int time=0;
  long house_number;
  for(int i = 0; i < number_of_packages; i++){ //calculating time
    scanf("%ld", &house_number);
    int target_position = search(house_number, rua, 0, number_of_houses-1);
    time = time + abs(target_position-current_position);
    current_position = target_position;
  }

  printf("%d\n", time);

  free(rua);
}