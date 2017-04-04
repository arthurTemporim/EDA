#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>


#define ARRAYS_SIZE 9

int binary_search(int*, int, int, int);

int main (int argc, char *argv[]) {
  int arrays_size[ARRAYS_SIZE] = {10, 25, 50, 100, 500, 1000, 10000, 100000, 1000000};
  int *array, array_iterator, size_iterator, entry_value;
  clock_t inicio,fim;
  double tempo_lista;


  srand(time(NULL));

  for (size_iterator = 0; size_iterator < ARRAYS_SIZE; size_iterator++) {
    array = (int*)malloc(sizeof(int) * arrays_size[size_iterator]);
    for (array_iterator = 0; array_iterator < arrays_size[size_iterator]; array_iterator++) {
      array[array_iterator] = array_iterator;
    }

    entry_value = rand() % arrays_size[size_iterator];
    inicio = clock();
    binary_search(array, 0, arrays_size[size_iterator]-1, entry_value);
    fim = clock();
  	tempo_lista = (double) (fim-inicio)/CLOCKS_PER_SEC;
    printf("array size: %d, random generated value: %d, total time: %lf\n", arrays_size[size_iterator], entry_value, tempo_lista);
  }


  return 0;
}

int binary_search(int *array, int min, int max, int value) {
  int mid_pos = min + (max - min) * ((value - array[min]) / (array[max] - array[min]));
  if (value == array[mid_pos]) {
    return mid_pos;
  }
  if (min >= max) {
    return -1;
  }else {
    if (array[mid_pos] > value) {
      return binary_search(array, min, mid_pos-1, value);
    } else {
      return binary_search(array, mid_pos+1, max, value);
    }
  }
}
