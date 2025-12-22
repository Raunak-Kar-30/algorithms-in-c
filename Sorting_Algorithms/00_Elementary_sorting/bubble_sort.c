// Simple bubble sorting algorithms
// Swap the adjacent elements if the ordering is wrong and repeat this process for the entire length of the loop
// In every iteration what this ensures is that the largest element is always pushed to the end (if arranged in ascending order)

// Includes
#include <stdio.h>

// Defines

// Function declarations
void bubble_sort(int *array, int len);

// Main function
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

    bubble_sort(array, len);

    for(int i = 0; i < len; i++) printf("%d ", array[i]);
    printf("\n");

    return 0;
}

// Bubble sort
void bubble_sort(int *array, int len)
{
    for(int i = len-1; i >= 0; i--)
    {
        // Since the largest element is always being pushed to the very end after each iteration,
        // no need to iterate to the last element every time.
        for(int j = 0; j < i; j++)
        {
            if(array[j+1] < array[j])
            {
                int temp = array[j];
                array[j] = array[j+1];
                array[j+1] = temp;
            }
        }
    }
}