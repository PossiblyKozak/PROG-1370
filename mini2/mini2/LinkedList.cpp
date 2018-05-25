#include "LinkedList.h"

void LinkedList::AddNode(void* addItem)
{
	node* block = (node*)malloc(sizeof(node));
	block->info = addItem;
	block->next = NULL;

	if (head == NULL)
	{
		head = block;
		tail = block;
		block = NULL;
	}
	else
	{
		tail->next = block;
		tail = block;
	}
}

void LinkedList::PrintNodes(void (*printFunction)(void *data))
{
	node* block = head;
	while (block != NULL)
	{
		printFunction(block->info);
		block = block->next;
	}
}

void LinkedList::FreeNodes(void (*freeFunction)(void *item))
{
	PrintNodes(freeFunction);
}

int LinkedList::NumNodes()
{
	int numNodes = 0;
	node *block = head;
	while (block != NULL)
	{
		block = block->next;
		numNodes++;
	}
	return numNodes;
}