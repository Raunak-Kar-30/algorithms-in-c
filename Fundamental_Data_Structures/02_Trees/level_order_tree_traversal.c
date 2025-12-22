// Simple program to demonstrate level order traversal using queue and while loops (without recursion)

#include <stdio.h>
#include <stdlib.h>

// Struct for treenode
typedef struct treenode
{
    int value;
    struct treenode *left;
    struct treenode *right;
} treenode;

// Struct for queuenode
typedef struct queuenode
{
    treenode *node;
    struct queuenode *next;
} queuenode;

// Globals
queuenode *head, *tail, *last;

// Function declarations
// Queue functions
void queue_init();
void enqueue(treenode *node);
treenode *dequeue();
int is_queue_empty();

// Tree functions
treenode *create_node(int value);
void level_order_traverse_tree(treenode *root);
void visit(treenode *node);

int main(void)
{
    // Initialize the queue
    queue_init();

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

    // Traverse the tree using level order traversal
    printf("Level order traversal : \n");
    level_order_traverse_tree(n1);
    printf("\n");

    return 0;
}

// Initialize queues
void queue_init()
{
    head = (queuenode *) malloc(sizeof(queuenode));
    if(head == NULL)
    {
        fprintf(stderr, "Allocation failed for queuenode\n");
        exit(1);
    }
    
    tail = (queuenode *) malloc(sizeof(queuenode));
    if(tail == NULL)
    {
        fprintf(stderr, "Allocation failed for queuenode\n");
        exit(1);
    }

    last = (queuenode *) malloc(sizeof(queuenode));
    if(last == NULL)
    {
        fprintf(stderr, "Allocation failed for queuenode\n");
        exit(1);
    }

    head->next = tail;
    tail->next = tail;
}

// Enequeue
void enqueue(treenode *node)
{
    if(head->next == tail)
    {
        last->node = node;
        head->next = last;
        last->next = tail;
    }

    else
    {
        queuenode *new = (queuenode *) malloc(sizeof(queuenode));
        if(new == NULL)
        {
            fprintf(stderr, "Allocation failed for queuenode\n");
            exit(1);
        }

        new->node = node;
        new->next = tail;
        last->next = new;
        last = new;
    }
}

// Dequeue
treenode *dequeue()
{
    queuenode *temp = (queuenode *) malloc(sizeof(queuenode));
    if(temp == NULL)
    {
        fprintf(stderr, "Allocation failed for queuenode\n");
        exit(1);
    }

    temp = head->next;
    head->next = temp->next;

    treenode *node = temp->node;
    free(temp);

    return node;
}

// Check if queue is empty
int is_queue_empty()
{
    return head->next == tail;
}

// Create a treenode
treenode *create_node(int value)
{
    treenode *node = (treenode *) malloc(sizeof(treenode));
    if(node == NULL)
    {
        fprintf(stderr, "Allocation failed for treenode\n");
        exit(1);
    }

    node->value = value;
    node->left = node;
    node->right = node;

    return node;
}

// Level order tree traversal using while loop and queue
void level_order_traverse_tree(treenode *root)
{
    // Push the root onto the queue
    enqueue(root);

    while(!(is_queue_empty()))
    {
        root = dequeue();
        visit(root);
        if(root->left != root) enqueue(root->left);
        if(root->right != root) enqueue(root->right);
    }
}

void visit(treenode *node)
{
    printf("%d \n", node->value);
}