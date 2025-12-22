// Simple program to demonstrate in order tree traversal using stack

#include <stdio.h>
#include <stdlib.h>

// Define a struct for the tree node
typedef struct treenode
{
    int value;
    struct treenode *right;
    struct treenode *left;
} treenode;

// Function declarations
treenode *create_node(int value);
void in_order_traverse_tree(treenode *root);
void visit(treenode *node);

int main(void)
{
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

    // In order tree traversal
    printf("In order tree traversal : \n");
    in_order_traverse_tree(n1);
    printf("\n");

    return 0;
}

// Create a tree node
treenode *create_node(int value)
{
    treenode *node = (treenode *) malloc(sizeof(treenode));
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

// Traverse the tree using in order traversal and recursion
void in_order_traverse_tree(treenode *root)
{
    if(root->left != root) in_order_traverse_tree(root->left);
    visit(root);
    if(root->right != root) in_order_traverse_tree(root->right);
}

void visit(treenode *node)
{
    printf("%d ", node->value);
}