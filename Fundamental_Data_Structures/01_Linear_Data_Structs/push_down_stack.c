// Implementation of push down stack using linked list

#include <stdio.h>
#include <stdlib.h>

// Create a struct for the node
struct node
{
	int key;
	struct node *next;
};

// Global variables
struct node *head, *tail;

// Function declarations
void stack_init();
void push();
int pop();
int is_stack_empty();

int main(void)
{
	stack_init();
	push(40);
	push(99);
	push(23);
	push(29);
	push(11);

	while(!(is_stack_empty()))
	{
		printf("%d\n", pop());
	}

	return 0;
}

// Initialize the stack
void stack_init()
{
	head = (struct node *) malloc(sizeof(head));
	tail = (struct node *) malloc(sizeof(tail));
	head->next = tail;
	tail->next = head;
}

// Push a new node
void push(int val)
{
	// We push new element with respect to the head
	struct node *temp = (struct node *) malloc(sizeof(temp));
	temp->key = val;
	temp->next = head->next;
	head->next = temp;
}

// Removes the last node, frees it and returns the value
int pop()
{
	// Delete the current node after the head and free it
	int val = head->next->key;
	struct node *temp = (struct node *) malloc(sizeof(temp));
	
	temp = head->next;
	head->next = temp->next;

	free(temp);
	return val;
}

// Returns 1 if stack is empty
int is_stack_empty()
{
	return head->next == tail;
}
