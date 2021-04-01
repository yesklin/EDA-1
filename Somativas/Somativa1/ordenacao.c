#include <stdio.h>
#include <stdlib.h>

void print_arr(int *arr, int num){
  for(int i = 0; i < num; i++){
    printf("%d ", arr[i]);
  }
  printf("\n");
}

int main(){
  int number_of_elements;
  scanf("%d", &number_of_elements);
  
  if(number_of_elements>0){
    int *numbers = malloc(sizeof(int)*number_of_elements);
    
    //counting sorting.
    //reading => working.
    int biggest_number = 0;
    for(int i = 0; i < number_of_elements; i++){
      scanf("%d", &numbers[i]);
      if(numbers[i] >= biggest_number) biggest_number = numbers[i];
    }
    /////////////////////
    

    //creating an array with (biggest_number+1) elements and fill it with zeros => working.
    int *ocurrences_array = malloc(sizeof(int)*biggest_number+1);
    int *position_array = malloc(sizeof(int)*biggest_number+1);
    int *sorted_array = malloc(sizeof(int)*number_of_elements);  

    for(int i = 0; i <= biggest_number; i++){
      position_array[i] = 0;
      ocurrences_array[i] = 0;
    }


    
    //putting in each key the number of repetitions of each element => working
    for(int i = 0; i < number_of_elements; i++){
      position_array[numbers[i]]++;
      ocurrences_array[numbers[i]]++;
    }

    
    //couting for each element the numbers smaller elments => I think its workings
    for(int i = 1; i <= biggest_number; i++){
      position_array[i] = position_array[i] + position_array[i-1];
    }
    
    //print_arr(ocurrences_array, biggest_number+1);

    //print_arr(position_array, biggest_number+1);

    
    //creating sorted array
    for(int i = number_of_elements-1; i >= 0; i--){
      int final_position = position_array[numbers[i]]-1;
      int number_of_ocurrences = ocurrences_array[numbers[i]];

      for(int j = 0; j < number_of_ocurrences; j++){
        sorted_array[final_position-j] = numbers[i];
      }
    }
    

    for(int i = 0; i<number_of_elements-1; i++) printf("%d ", sorted_array[i]);
    printf("%d\n", sorted_array[number_of_elements-1]);
    

    free(numbers);
    free(ocurrences_array);
    free(position_array);
    free(sorted_array);
  }
}