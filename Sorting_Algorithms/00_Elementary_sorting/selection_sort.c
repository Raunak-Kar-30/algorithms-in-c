// Simple program to implement selection sort on a given array of numbers.
// Selection sort selects the smallest value in the array and swaps the first element in the array with it, then the second, then third
// until the entire array is sorted

// Just like insertion sort, the elements to the left of the current index i always remains sorted

// Includes
#include "stdio.h"

// Defines

// Function declarations
void select_sort(int *array, int len);

int main(void)
{
    int len = 0;
    printf("Len : ");
    scanf("%d", &len);

    int array[len];

    for(int i = 0; i < len; i++)
    {
        printf("array[%d] : ", i+1);
        scanf("%d", &array[i]);
    }

    select_sort(array, len);

    for(int i = 0; i < len; i++) printf("%d ", array[i]);
    printf("\n");

    return(0);
}

// Selection sort function
void select_sort(int *array, int len)
{
    int min_index = 0;

    for(int i = 0; i < len; i++)
    {
        min_index = i;
        
        for(int j = i; j < len; j++)
        {
            if(array[j] < array[min_index]) min_index = j;
        }

        // Swap value at min_index with the ith value
        int temp = array[i];
        array[i] = array[min_index];
        array[min_index] = temp;
    }
}