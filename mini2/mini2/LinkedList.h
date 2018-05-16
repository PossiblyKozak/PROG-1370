#pragma once
#include <iostream>
struct node
{
	node* next;
	void* info;
};

class LinkedList
{
private:
	node *tail;
public:
	node *head;
	LinkedList()
	{
		head = NULL;
		tail = NULL;
	}

	void addNode(void* addItem)
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
};