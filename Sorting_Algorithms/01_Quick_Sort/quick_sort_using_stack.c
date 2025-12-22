// This is the process of optimizing the quick-sort algorithm using the process of recursion removal and using the stack based implementation.
// In this process we first partition the data array such that all the elements to the left of the parting element is smaller than all the elements to
// the right of the parting element.
// Then after partioning into two subarrays, the larger subarray (the end points - left and right points) are pushed to the stack
// and the smaller array is being partitioned and arranged the same way, and we keep repeating the entire process
// until both the ends are same (i.e. no element left in a subarray).
// We then pop the left and right indexes of the larger array, and do the whole thing again, until the stack is empty (implying the array is sorted).
// Since we only push the larger array into the stack the maximum size occupied by the data is log N, and in worst case (when the file is already sorted) N

// Includes
#include <stdio.h>
#include <stdlib.h>

// Defines

// Create the struct for the node of the stack
typedef struct node
{
    int key;
    struct node *next;
} node;

// Global variables
node *head, *tail;

// Function declarations
// Stack functions
void stack_init();
void stack_push(int value);
int stack_pop();
int is_stack_empty();
void quick_sort_using_stack(int *array, int len);
int partition(int *array, int left, int right);

// Main function
int main(void)
{
    int len;
    printf("Length : ");
    scanf("%d", &len);

    int array[len];
    for(int i = 0; i < len; i++)
    {
        printf("Enter array[%d] : ", i);
        scanf("%d", &array[i]);
    }

    quick_sort_using_stack(array, len);

    for(int i = 0; i < len; i++) printf("%d ", array[i]);
    printf("\n");

    return 0;
}

// Quick sort implementation using stack - recursion removal
void quick_sort_using_stack(int *array, int len)
{
    int part, left, right;
    left = 0; right = len;

    stack_init();

    for(;;)
    {
        // We keep dividing the array into subarrays and sort the smaller array of the two subarrays first, simultaneously pushing the
        // larger array end (left and right indexes of the larger subarray) indexes into the stack.
        // We check if right is smaller than left, indicating that two ends have either become same or right has become smaller than left,
        // of left has become larger than right, all indicating that the subarray cannot be divided further (as there are no further elements present)
        // and we break out of the while loop.
        while(right > left)
        {
            part = partition(array, left, right);
            if((part-left) > (right-part))
            {
                stack_push(left);
                stack_push(part-1);
                left = part+1;
            }

            else
            {
                stack_push(part+1);
                stack_push(right);
                right = part-1;
            }
        }

        // Once we break out of the while loop we keep repeating this for all the sub-arrays that were pushed into the stack.
        // All the larger subarrays that we pushed into the stack will now under go the same process (dividing into smaller subarrays and
        // partitioning the smaller of the either, while the larger one gets pushed onto the stack).
        // Keep doing this until no subarray is left in the stack, at which point the entire array must be sorted.
        if(is_stack_empty()) break;
        right = stack_pop();
        left = stack_pop();
    }
}

// Partition the stack appropriately such that all the elememts to the left of the stack is smaller than the elements to the 
// right of the stack
int partition(int *array, int left, int right)
{
    int part = right, temp;

    for(;;)
    {
        while(array[++left] < array[part]);
        while(array[--right] > array[part]);
        
        if(left >= right) break;
        
        temp = array[left];
        array[left] = array[right];
        array[right] = temp;
    }

    temp = array[part];
    array[part] = array[left];
    array[left] = temp;

    part = left;
    return part;
}

// Initialize the stack
void stack_init()
{
    head = (node *) calloc(1, sizeof(head));
    tail = (node *) calloc(1, sizeof(tail));
    head->next = tail;
    tail->next = tail;
}

// Push a value onto the stack
void stack_push(int value)
{
    node *new = (node *) calloc(1, sizeof(new));
    
    new->key = value;
    new->next = head->next;
    head->next = new;
}

// Pop the last value from the stack
int stack_pop()
{
    node *temp = (node *) calloc(1, sizeof(temp));
    
    temp = head->next;
    head->next = temp->next;

    int value = temp->key;
    free(temp);

    return value;
}

// Check if stack is empty
int is_stack_empty()
{
    return head->next == tail;
}