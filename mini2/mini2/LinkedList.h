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
	node *tail = NULL;
public:
	node *head = NULL;
	void AddNode(void* addItem);
	void PrintNodes(void(*printItem)(void *data));
	void FreeNodes(void(*freeItem)(void *item));
	int NumNodes();
};