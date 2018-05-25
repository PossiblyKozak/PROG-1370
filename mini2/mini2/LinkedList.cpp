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

void LinkedList::PrintNodes(void (*printItem)(void *data))
{
	node* block = head;
	while (block != NULL)
	{
		printItem(block->info);
		block = block->next;
	}
}

void LinkedList::FreeNodes(void (*freeItem)(void *item))
{
	node* block = head;
	while (block != NULL)
	{
		freeItem(block->info);
		block = block->next;
	}
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