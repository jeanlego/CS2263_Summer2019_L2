/********************************
 *
 * ArraySort.c
 *
 * Created by Jean-Philippe Legault
 *
 * Your task is to implement in place sorting using the two available functions
 * swapAdjacent, and compareAdjacent.
 *
 * Some bug might have been introduced... you will have to find out if there are any!
 * if so, you will have to correct it
 *
 ********************************/
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void printArray(int *array, int size)
{
  int i = 0;
    for(i; i<size; i++)
    {
        if(i != 0)
        {
            printf(", ");
        }
        printf("%d", array[i]);
    }
    printf("\n");
}

void swapAdjacent(int *a, int index)
{
    int temp = *(a + index);
    *(a + index) = *(a + index + 1);
    *(a + index + 1) = temp;
}

int compareAdjacent(int *a, int index)
{
    return *(a + index) - *(a + index + 1);
}


void inPlaceSort(int *a, int size)
{
  int j = size - 1;
  int i;
  for(j; j>0 ; j--){
    i = 0;
    for(i; i<j; i++){
      if(compareAdjacent(a, i) > 0){
        swapAdjacent(a, i);
      }
    }
  }

}

int main(void)
{

    int array_size = 0;
    printf("Enter the array size (>0) and the numbers to fill the array with: ");
    if(!scanf("%d", &array_size))
    {
        printf("ERROR. Must enter an integer.\n");
        return EXIT_FAILURE;
    }
    else if(array_size < 1)
    {
        printf("ERROR. array size must be at least 1.\n");
        return EXIT_FAILURE;
    }

    int a[array_size];
    int input_val;
    int i = 0;
    for(i; i<array_size; i++){
      if(!scanf("%d", &input_val))
      {
          printf("ERROR. Must enter an integer.\n");
          return EXIT_FAILURE;
      }
      a[i] = input_val;
    }

    printArray(a, array_size);

    inPlaceSort(a, array_size);

    printArray(a, array_size);

}
