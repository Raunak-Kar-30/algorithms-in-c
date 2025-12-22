// Simple program to showcase the various operations of a linked list
// This is not a runnable program, just a template for showcasing how a linked list can be implemented using pointers and structs

#include <stdio.h>
#include <stdlib.h>

// Create the linked list
struct node
{
    int key;
    struct *node next;
}

// Initialize the head, tail
struct *node head, tail;

// Function declarations
void list_init();
void list_insert(struct node *current, int value);
void list_delete(struct node *current);

int main(void)
{

}

// Initiate the list
void list_init()
{
    // Initialize head and tail and make the head point to tail and the tail point to itself
    head = (struct *node) malloc(sizeof(head));
    tail = (struct *node) malloc(sizeof(tail));
    head->next = tail;
    tail->next = tail;
}

// Insert node next to the current node
void list_insert(struct *node current, int value)
{
    struct node *new = (struct *node) malloc(sizeof(new));
    
    new->next = current->next;
    current->next = new;
    new->key = value;
}

// Delete the node next to the current node
int list_delete(struct *node current)
{
    // Store the value of the next node and make the current node point to the node after next node of the current node
    int value = current->next->key;
    current->next = current->next->next;

    return value;
}
