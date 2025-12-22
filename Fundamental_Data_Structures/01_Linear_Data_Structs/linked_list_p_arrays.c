// Simple implementation of linked lists using parallel arrays instead of pointers
// This is not a runnable program, just a template for showcasing how a linked list can be implemented using arrays

#include <stdio.h>

#define MAX 100

// Create 2 global arrays for holding the keys of the current index and for holding the next index for the current index
int key[MAX+2];
int next[MAX+2];
int head, tail, temp;

void list_init();

int main(void)
{

}

void list_init()
{
	head = 0;
	tail = 1;
	temp = 2;
	next[head] = tail;
	next[tail] = tail;
}

void list_insert(int val, int current)
{
	key[temp] = val;
	next[temp] = next[current];
	next[current] = temp;
	return temp++;
}

void list_delete(int current)
{
	next[current] = next[next[current]];
}
