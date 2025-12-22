// Simple program to implement every kind of traversal in a tree - postfix, prefix, infix traversal using stack WITHOUT recursion

#include <stdio.h>
#include <stdlib.h>

// Create a tree node
typedef struct treenode
{
	int value;
	struct treenode *left;
	struct treenode *right;
} treenode;

// Create a node for the stack holding trees
typedef struct stacknode
{
	treenode *key;
	struct stacknode *next;
} stacknode;

// Global variables
stacknode *head, *tail;

// Function declarations
// Tree functions
treenode *create_node(int value);
void pre_order_traverse_tree(treenode *root);
void post_order_traverse_tree(treenode *root);
void level_order_traverse_tree(treenode *root)
void visit(treenode *node);

// Stack functions
void stack_init();
void stack_push(treenode *node);
treenode *stack_pop();
int is_stack_empty();

// Main function
int main(void)
{
	// Initialize the stack
	stack_init();

	// Create a new treenode
	treenode *n1 = create_node(1);
	treenode *n2 = create_node(2);
	treenode *n3 = create_node(3);
	treenode *n4 = create_node(4);
	treenode *n5 = create_node(5);
	treenode *n6 = create_node(6);
	treenode *n7 = create_node(7);
	treenode *n8 = create_node(8);
	treenode *n9 = create_node(9);
	treenode *n10 = create_node(10);

	// Connect the nodes
	n1->left = n2;
	n1->right = n3;
	n2->left = n4;
	n2->right = n5;
	n5->left = n8;
	n3->left = n6;
	n3->right = n7;
	n7->left = n9;
	n7->right = n10;

	// Traverse the trees in various ways
	printf("Pre-ordered : \n");
	pre_order_traverse_tree(n1);

	printf("Post ordered : \n");
	post_order_traverse_tree(n1);

	return 0;
}

// Initialize the stack
void stack_init()
{
	head = (stacknode *) malloc(sizeof(stacknode));
	tail = (stacknode *) malloc(sizeof(stacknode));
	head->next = tail;
	tail->next = tail;
}

// Push a treenode into the stack
void stack_push(treenode *node)
{
	stacknode *new = (stacknode *) malloc(sizeof(stacknode));
	new->key = node;
	new->next = head->next;
	head->next = new;
}

// Pop a treenode from the stack
treenode *stack_pop()
{
	stacknode *temp = (stacknode *) malloc(sizeof(stacknode));
	temp = head->next;
	head->next = temp->next;
	treenode *node = temp->key;
	free(temp);
	return node;
}

// Check if the stack is empty
int is_stack_empty()
{
	return head->next == tail;
}

// Create a tree node
treenode* create_node(int value)
{
	treenode *node = (treenode *)malloc(sizeof(treenode));
	if(node == NULL)
	{
		fprintf(stderr, "Allocation for treenode failed\n");
		exit(1);
	}

	node->value = value;
	node->left = node;
	node->right = node;

	return node;
}

// Pre-order traversal using while loop and stack (without recursion)
void pre_order_traverse_tree(treenode *root)
{
	// Push the root to the stack
	stack_push(root);

	/* 
	Until the stack is empty, we keep visiting the root, pushing the right node to the stack first, then the left node.
	In this manner in every iteration if there was a left node in the previous iteration, it will always be popped first since it was pushed last (after the right root)
	As a result everytime we are finding a left node it is being visited first (in the next iteration).
	Once all the left nodes are visited, we then start visiting the right roots starting from the last root's right node and moving up.
	*/
	while(!(is_stack_empty()))
	{
		root = stack_pop();
		visit(root);
		if(root->right != root) stack_push(root->right);
		if(root->left != root) stack_push(root->left);		
	}
}

// Post order traversal using while loop and stack (without recursion) -- currently wrong
void post_order_traverse_tree(treenode *root)
{
	// Push the root to stack
	stack_push(root);
	treenode *visited = (treenode *)malloc(sizeof(treenode));

	// Wait until the stack is empty
	while(!(is_stack_empty()))
	{
		treenode *node = stack_pop();

		while(node != visited && (node->left != node || node->right != node))
		{
			stack_push(node);
			if(node->right != node && node->right != visited) stack_push(node->right);
			if(node->left != node && node->left != visited) stack_push(node->left);
		}

		visit(node);
		visited = node;
	}
}

// Level order tree traversal using while loop and queue
void level_order_traverse_tree(treenode *root)
{

}

// Visit the treenode 
void visit(treenode *node)
{
	printf("%d\n", node->value);
}
