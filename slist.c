
#include "slist.h"

snode* snode_create(int data, snode* next) {
	snode* p = (snode*)malloc(sizeof(snode));
	if (p)
	{
		p->data = data;
		p->next = next;
	}

	return p;
}
slist* slist_create(void) {
	slist* p = (slist*)malloc(sizeof(slist));
	if (p)
	{
		p->head = NULL;
		p->tail = NULL;
		p->size = 0;
	}

	return p;
}

bool slist_empty(slist* list) {
	if (list->head == NULL) { return true; }
	else { return false; }
}

size_t slist_size(slist* list) {
	return list->size;
}

void slist_popfront(slist* list) {
	if (list->head)
	{
		if (list->head->next)
			list->head = list->head->next;
		else
		{
			list->head = NULL;
			list->tail = NULL;
		}
	}
	list->size--;
	if (list->size == 1)
		list->tail = list->head;
}

void slist_popback(slist* list) {
	if (list->tail)
	{
		snode* current = list->head;
		snode* newTail = NULL;
		while (current->next) 
		{
			newTail = current;
			current = current->next;
		}
		free(current);
		if (newTail) 
		{
			list->tail = newTail;
			newTail->next = NULL;
		}
		else 
		{
			list->head = NULL;
			list->tail = NULL;
		}
	}
	list->size--;
	if (list->size == 1)
		list->head = list->tail;
}

void slist_pushfront(slist* list, int data) {
	snode* node = snode_create(data, list->head);
	if (list->tail == NULL)
	{
		list->head = node;
		list->tail = node;
	}
	else
	{
		list->head = node;
	}
	list->size++;
}

void slist_pushback(slist* list, int data) {
	snode* node = snode_create(data, NULL);
	if (list->head == NULL)
	{
		list->head = node;
		list->tail = node;
	}
	else
	{
		list->tail->next = node;
		list->tail = node;
	}
	list->size++;
}

void slist_clear(slist* list) {
	if (list)
	{
		slist_clear(list);
		free(list);
	}
}

void slist_print(slist* list, const char* msg) {

}

int slist_front(slist* list) {
	return list->head->data;
}

int slist_back(slist* list) {
	return list->tail->data;
}