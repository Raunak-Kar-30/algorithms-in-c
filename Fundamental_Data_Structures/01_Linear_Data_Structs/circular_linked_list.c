// A simple program to implement a circular linked list to solve the josephus problem

#include <stdio.h>
#include <stdlib.h>

// Creating the node
struct node
{
    int key;
    struct node *next;
};

// Global variables
struct node *head;

// Function declarations
struct node *list_init(int len);
void list_delete(struct node *current);

int main(void)
{
    int n,m;
    scanf("%d %d", &n, &m);

    if(n < m) 
    {
        printf("Number of people must be greater than the position");
        exit(1);
    }

    struct node *list = list_init(n);

    // Loop until list points to itself, that is until only one node remains in the loop
    while(list != list->next)
    {
        // Move forward int the list by m-1 steps
        for(int i = 1; i < m; i++) list = list->next;
    
        // Store the next node and delete it
        struct node *hold = list->next;
        list_delete(list);

        // Free the hold node
        free(hold);
    }

    // Print the last node's key
    printf("%d\n", list->key);

    return 0;
}

// Initialize the list
struct node *list_init(int len)
{
    // Initialize a list node and a temporary node for holding the first node of the list
    struct node *list = (struct node *) malloc(sizeof(list));
    list->key = 1;
    struct node *temp = list;

    // Create a new node everytime and make the current node the new node
    for(int i = 2; i <= len; i++)
    {
        list->key = i;

        list->next = (struct node *) malloc(sizeof(list->next));
        list = list->next;  
    }

    // Make the list point to the beginning 
    list->next = temp;

    return list;
}

// Delete an element from the list
void list_delete(struct node *current)
{
    current->next = current->next->next;
}