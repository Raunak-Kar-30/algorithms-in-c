// Quick sort method for sorting an array of data.
// This is a divide and conquer sorting method using recursion.
// We divide the array every iteration at the element array[part], where all the elements to the left of the array[part] is lesser than array[part]
// and all the elements right of the array[part] are greater than array part. The elements to the left and right of the array part do not need to
// be sorted in any order

// A correctly tuned quick sort will over perform almost all elementary sort, however tuning quick sort is difficult and prone to errors. 
// If we cannot prove that the tuning is correct it is better to use something like shell sort as it stll gives the number of comparisons to N^(2/3).
// A correctly tuned quick sort gives the total number of operations not more than NlogN.

// Includes
#include <stdio.h>

// Defines

// Function declarations
void quick_sort(int *array, int left, int right);

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

    quick_sort(array, 0, len);

    for(int i = 0; i < len; i++) printf("%d ", array[i]);
    printf("\n");

    return 0;
}

// Quick sort the array of data.
// We consider the parting element to be the right most element of the array (since we can consider any element to be the parting element)
// as the parting element will always come to the correct parting postion - where all the elements to the left of the parting element is smaller
// than it and all the elements to the right of the array is greater than it.
void quick_sort(int *array, int left, int right)
{
    int part_val, i, j, temp;

    if(right > left)
    {
        // Hold the right most element as the parting element and i and j respectfully start at the leftmost and right most element
        part_val = array[right];
        i = left;
        j = right;

        for(;;)
        {
            // Move i towards the right (increment i) and j towards the left (decrement j). 
            // The moment array[i] > part_val and array[j] > part_val, both loops are broken and array[i] and array[j] are swapped.
            while(array[++i] < part_val);   // Starting from the left end, get the value array[i] that is greater than part_val
            while(array[--j] > part_val);   // Starting from the right end, get the value array[j] that is lesser than part_val
            if(i >= j) break;               // If i and j have crossed over, break
            temp = array[i];
            array[i] = array[j];
            array[j] = temp;
        }

        // Since we have broken out of the loop after i and j crosses each other that means, all the value to the left of i is now lesser than part_val
        // and all the elements to the right of array[i] is now greater than part_val
        // So we swap part_val (array[right]) with array[i]. This way the part val is now in the correct position, with i being the parting index.
        temp = array[i];
        array[i] = array[right];
        array[right] = temp;
        int part_index = i;

        quick_sort(array, left, (part_index-1));
        quick_sort(array, (part_index+1), right);
    }
}