// Simple program to show divide and conquer techniques using recursion

#include <stdio.h>
#include <stdlib.h>

// Global variables
int *ruler_marks;

// Function declarations
void create_ruler(int left, int right, int height);
void mark(int point, int height);
void show_ruler(int left, int right);

int main(void)
{
    int left, right, height;
    printf("Enter the left marking, right marking and height seperated by spaces : ");
    scanf("%d %d %d", &left, &right, &height);

    ruler_marks = (int *) calloc((left+right), sizeof(int));
    if(ruler_marks == NULL)
    {
        fprintf(stderr, "Allocation failed for ruler_marks\n");
        exit(1);
    }

    create_ruler(left, right, height);
    show_ruler(left, right);

    return 0;
}

// Create the marking for the ruler
void create_ruler(int left, int right, int height)
{
    int mid_point = (left + right)/2;
    
    if(height > 0)
    {
        // Mark the current mid_point and then mark all the left ones then the right ones.

        // This algorithm sort of corresponds to the pre order traversal of trees.
        // We mark the current mid-point (as in visiting the root), then visit the left mid point if present (as in moving to the left node)
        // If present, mark the left mid-point (as in vising the left node as root) then, continuing down left.
        // After no more left marks are to be maid (i.e. no more left nodes), then star marking the right marks 
        // corresponding to the current mid-point.

        // However it seems like maybe during the return journey (left most -> mid, marking all the right points), it follows
        // in-order traversal, since it actually returns to the parent function first (the root node of the left node), 
        // then marks the right mid-point (visits the right node. ???

        // Edit : It is not in-order traveral, but seems like since we are not marking (visiting)the midpoint of the parent function
        // rather just moving to the parent, to then mark the right mid-point. So it is still pre-order, but might look like in-order.

        // Interesting  point to note : This is actually also using the stack, just like pre order traversal, but here it is using the stack
        // of the RAM and not our own implementation. 
        // How we know ? Because returning from the child function to the parent function is nothing but a stack operation
        mark(mid_point, height);
        create_ruler(left, mid_point, height-1);
        create_ruler(mid_point, right, height-1);
    }
}

// Mark the points
void mark(int point, int height)
{
    ruler_marks[point] = height;
}

// Show the ruler
void show_ruler(int left, int right)
{
    for(int i = left; i <= (left+right); i++)
    {
        for(int j = 0; j < ruler_marks[i]; j++) printf("---");
        printf("\n");
    }
}   