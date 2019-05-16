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
    while(i<size)
    {
        if(i != 0)
        {
            printf(", ");
        }
        printf("%d", array[i]);
        i++;
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

/**
 * TODO: implement in place sorting on an array
 * by using the two functions swapAdjacent and compareAdjacent
 */
void inPlaceSort(int *a, int size)
{
    int size_copy = size;
    int i=0;
    while(i<size_copy-1) {
        int j=0;
        while(j<size-1) {
            if(compareAdjacent(a, j) > 0) {
                swapAdjacent(a, j);
            }
            j++;
        }
        i++;
        size--;
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

    /**********************
     * TODO finish parsing the user input to fill the array
     *
     * it should parse user input with scanf to fill the array with values
     **********************/
    int i = 0;
    while(i<array_size) {
        scanf("%d", &a[i]);
        i++;
    }

    //printf("=== Array before Sorting = ");
    printArray(a, array_size);

    inPlaceSort(a, array_size);

    //printf("=== Array after Sorting = ");
    printArray(a, array_size);

}
