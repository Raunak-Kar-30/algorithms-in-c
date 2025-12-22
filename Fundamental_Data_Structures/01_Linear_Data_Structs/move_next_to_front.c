// This is a program using linked list (Q 2 chapter 3) that move the node next to the current node to the first 
// To make this functionality testable we implement a reverse list function using this method

#include <stdio.h>
#include <stdlib.h>

// Create the struct for the node
struct node
{
	int key;
	struct node *next;
};

// Global variables
struct node *head, *tail;

// Function declarations
void list_init();
void insert_after(struct node *current, int val);
void move_next_to_first(struct node *current);

int main(void)
{
	// Create the list and store the head
	list_init();

	int len = 0;
	printf("Enter the length of the list : ");
	scanf("%d", &len);

	struct node *current = head;

	for(int i = 0; i < len; i++)
	{
		// Read the value
		int val = 0;
		printf("Enter val %d : ", i+1);
		scanf("%d", &val);

		// Insert the value after the current node
		insert_after(current, val);
		current = current->next;
	}

	current = head->next;
	// Reverse the elements in the list
	for(int i = 0; i < len; i++)
	{
		move_next_to_first(current);
	}

	// Print the elements of the list
	for(int i = 0; i < len; i++)
	{
		printf("%d ", current->key);
		current = current->next;
	}

	return 0;
}

void list_init()
{
	head = (struct node *) malloc(sizeof(head));
	tail = (struct node *) malloc(sizeof(tail));
	head->next = tail;
	tail->next = tail;
}

void insert_after(struct node *current, int val)
{
	struct node *temp = (struct node *) malloc(sizeof(temp));
	temp->key = val;
	temp->next = current->next;
	current->next = temp;
}

void move_next_to_first(struct node *current)
{
	struct node *temp = (struct node *) malloc(sizeof(temp));
	*temp = *current->next;
	
	// Insert the node after the head node (to move it to the front)
	temp->next = head->next;
	head->next = temp;
	
	// Delete the node next to temp
	current->next = current->next->next;
}

