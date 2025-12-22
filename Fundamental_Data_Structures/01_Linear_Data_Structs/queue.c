// Simple program to implement a queue using linked list

#include <stdio.h>
#include <stdlib.h>

// Create a struct for the node
struct node
{
	int key;
	struct node *next;
};

// Global variables
struct node *head, *tail, *last;

// Function declarations
void queue_init();
void queue_insert(int val);
int queue_remove();
int is_queue_empty();

int main(void)
{
	queue_init();

	queue_insert(11);
	queue_insert(773);
	queue_insert(23);
	queue_insert(32);

	while(!(is_queue_empty())) printf("%d\n", queue_remove());

	return 0;
}

// Initialize the queue
void queue_init()
{
	head = (struct node *) malloc(sizeof(head));
	tail = (struct node *) malloc(sizeof(tail));
	last = (struct node *) malloc(sizeof(last));
	head->next = tail;
	tail->next = tail;
}

// Insert a new element in the queue
void queue_insert(int val)
{
	if(head->next == tail)
	{
		last->key = val;
		last->next = tail;
		head->next = last;
	}

	else
	{
		struct node *temp = (struct node *) malloc(sizeof(temp));
		temp->key = val;
		temp->next = tail;
		last->next = temp;
		last = temp;
	}
}

// Remove the first element from the queue
int queue_remove()
{
	struct node *temp = (struct node *) malloc(sizeof(temp));
	temp = head->next;
	head->next = temp->next;

	int val = temp->key;
	free(temp);
	
	return val;
}

// Check if queue is empty
int is_queue_empty()
{
	return head->next == tail;
}
