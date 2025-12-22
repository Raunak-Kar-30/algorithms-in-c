// Shell sort is an optimised version of insertion sort.
// We take every data elements in gaps of h (some constant) so array[0], array[h], array[2h], array[4h] .... and arrange these elements 
// using insertion sort. 
// Then we take array[1], array[h+1], array[2h+1], array[3h+1] ... (all in gaps of h) then sort these too using insertion sort.
// Once we go through the entire array like this, we divide h by some constant n and repeat the process from the start to the end once again, 
// but this time with gaps of h/n
// We keep doing this until the entire array is sorted

// Our current implementation of shell sorting uses the increment sequence of h as ..., 1093, 364, 121, 40, 13, 4, 1.
// This increment sequence works better than most sequences according to the author - Sedgewick
// Our implementation of shell sort never does more than N^(2/3) comparisons where N is the number of data elements.

// This is the recommended sorting algorithm by the book for moderately sized data (< 5000 data points)

// Includes
#include <stdio.h>

// Defines

// Function declarations
void shell_sort(int *array, int len);

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

    shell_sort(array, len);

    for(int i = 0; i < len; i++) printf("%d ", array[i]);
    printf("\n");

    return 0;
}

// Shell sort
void shell_sort(int *array, int len)
{
    // We set h to 1, and keep incrementing it by 3*h+1, because we want to keep decreasing h by 3 times every iteration during shell sort (n=3)
    // We get the value of h such that h is not larger than len/9 (i.e. we divide the data atleast nine times)
    int h ;
    for(h = 1; h <= len/9; h = 3*h+1);

    // Now we want to keep dividing the data first into h times, then h/3 times every iteration.
    for(; h > 0; h = h/3)
    {
        // We pick every element at a gap of h (where h = h/3 after every iteration) and (lets say put those elements in an imaginary array) sort them
        // using insertion sort.
        // First we swap array[0] and array[h] elements if they are in the opposite order. 
        // Like this we keep doing for array[1] and array[h+1], array[2] and array[h+2] .... until we finally reach the array[h] and array[2h] pair. 
        // This is where the real insertion sort begins with the elements being sorted are now array[0], array[h] and array[2h]. 
        // Similarly for array[1], array[h+1] and array[2h+1]. 
        // We keep doing this throughout the array till we cover the entire length,
        // with the elements being sorted are array[n], array[h+n], array[2h+n], array[3h+n] .... where x is 0,1,2,3 and x < h.
        // Once done we decrease the size of h to h/3 and continue the entire process again.
        for(int i = h+1; i < len; i++)
        {
            // Hold the current value
            int key = array[i];
            int j = i;

            // Sorts all the array[0+x], array[h+x], array[2h+x]..... elements where x is 0,1,2,3 and x < h (because then it becomes h again).
            while(j > h && array[j-h] > key)
            {
                array[j] = array[j-h];
                j = j-h;
            }

            array[j] = key;
        }
    }
}