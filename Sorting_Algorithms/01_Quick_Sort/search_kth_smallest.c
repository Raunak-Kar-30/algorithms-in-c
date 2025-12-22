// You might be wondering why do we want to search the kth smallest number in the topic of sorting elements.
// Well since we are already studying quick sort, getting the kth smallest number just makes sense, since the algorithm uses the 
// same partitioning principle to find the kth smallest number instead of having to search the entire array.
//
// Basically we partition the array and arrange it in the way we did in quick sort - partition function. We then check if the index of the parting
// element is greater or lesser than k. If it part_index is lesser than k, we only consider the left subarray else the right one. We then continue doing this
// until the correct position of k has been found. In that case we can just return the part_value at k.

// Includes
#include <stdio.h>

// Function declarations
int search_kth_smallest(int *array, int left, int right);

// Main function
int main(void)
{
    int len = 0;
    printf("E")
    return 0;
}

// search_kth_smallest algorithm for search for the kth smallest data/element in a list of elements.
int search_kth_smallest(int *array, int len, int k)
{
    int part_val, temp, i, j, left, right;
    left = 0;
    right = len;

    while(left > right)
    {
        part_val = array[right];
        i = left;
        j = right;

        // Do the same partitioning as in the quick sort algorithm
        for(;;)
        {
            while(array[++i] < part_val);
            while(array[--j] > part_val);
            
            if(i >= j) break;

            temp = array[i];
            array[i] = array[j];
            array[j] = temp;
        }

        // Swap the parting element (right most one) with the element in the parting index.
        temp = array[i];
        array[i] = array[right];
        array[right] = temp;

        // After partitioning, we check if parting index is greater than k. If so then k must be present from left->part_index.
        // Else k must be present from part_index->right. We reduce to the subarray accordingly.  
        if(i >= k) right = i-1;
        if(i <= k) left = i+1;
    }
}