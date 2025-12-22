// Simple program to demonstrate the implementation of trees in C

#include <stdio.h>
#include <stdlib.h>

// Create a struct for a treenode
typedef struct treenode
{
	int value;
	struct treenode *left;
	struct treenode *right;
} treenode;

// Function declarations
treenode *createnode(int val);
void print_tree(treenode *root);

int main(void)
{
	// Creating the nodes
	treenode *n1 = createnode(121);
	treenode *n2 = createnode(10);
	treenode *n3 = createnode(132);
	treenode *n4 = createnode(15);
	treenode *n5 = createnode(76);

	// Connecting the nodes
	n1->left = n2;
	n1->right = n3;
	n2->left = n4;
	n2->right = n5;

	// Printing the entire tree
	print_tree(n1);

	// Freeing the nodes
	free(n1);
	free(n2);
	free(n3);
	free(n4);
	free(n5);
}

treenode *createnode(int val)
{
	treenode *result = malloc(sizeof(treenode));
	if(result == NULL)
	{
		fprintf(stderr, "Node allocation failed\n");
		exit(1);
	}

	result->left = NULL;
	result->right = NULL;
	result->value = val;

	return result;
}

// Prints the tree starting from the root node
void print_tree(treenode *root)
{
	// If root node does not exist, then the rem
	if(root == NULL)
	{
		printf("---\n");
		return;
	}

	printf("Value = %d\n", root->value);

	// Recursively print the left subtree and the right subtree
	printf("Left : ");
	print_tree(root->left);
	printf("Right : ");
	print_tree(root->right);
	
	printf("Done\n");
}
