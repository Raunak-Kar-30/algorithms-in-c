/*
Simple program to sort an integer array using insertion sort.
In insertion sort we take a key value and compare it with the values in the left of that value in the array. We continually compare if the 
key value is lesser than a particular value to the left of it. If not we shift the values by one position to the right. Once found we place the value
in the appropriate position. 
Since this process is being done from the very beginning of the array, so the left hand side to the key of array is always sorted.
 */

// Includes
#include <stdio.h>

// Defines

// Function declarations
void insert_sort(int *array, int len);

// Main functions
int main(void)
{
    int len;
    printf("Len : ");
    scanf("%d", &len);

    int array[len];
    for(int i = 0; i < len; i++)
    {
        printf("array[%d] : ", i);
        scanf("%d", &array[i]);
    }

    insert_sort(array, len);

    for(int i = 0; i < len; i++) printf("%d ", array[i]);
    printf("\n");

    return 0;
}

// Insertion sort
void insert_sort(int *array, int len)
{
    for(int i = 1; i < len; i++)
    {
        // Set the current value as key
        int key = array[i];
        int j = i;

        // Until we have either reached the first element whilst checking or the key value is smaller than the next left value,
        // keep pushing array[i] each time to the right until the correct position is found
        while((j > 0) && (array[j-1] > key))
        {
            // Keep pushing the next left element to the right till the key becomes larger than the next left value
            array[j] = array[j-1];
            j = j-1;
        }

        array[j] = key;
    }
}