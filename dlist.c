#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>
#include "dlist.h"

dnode* dnode_create(int data, dnode* prev, dnode* next) {
	dnode* p = (dnode*)malloc(sizeof(dnode));
	if (p)
	{
		p->data = data;
		p->next = next;
		p->prev = prev;
	}

	return p;
}

dlist* dlist_create(void) {
	dlist* p = (dlist*)malloc(sizeof(dlist));
	if (p)
	{
		p->head = NULL;
		p->tail = NULL;
		p->size = 0;
	}

	return p;
}

bool dlist_empty(dlist* list) {
	if (list->head == NULL) { return true; }
	else { return false; }
}

size_t dlist_size(dlist* list) {
	return list->size;
}

void dlist_popfront(dlist* list) {
	if (list->head)
	{
		if (list->head->next)
		{
			list->head = list->head->next;
			list->head->prev = NULL;
		}
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

void dlist_popback(dlist* list) {
	if (list->tail)
	{
		if (list->tail->prev)
		{
			list->tail = list->tail->prev;
			list->head->next = NULL;
		}
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

void dlist_pushfront(dlist* list, int data) {
	dnode* node = dnode_create(data, NULL, list->head);
	if (list->tail == NULL) 
	{
		list->head = node;
		list->tail = node;
	}
	else 
	{
		list->head->prev = node;
		list->head = node;
	}
	list->size++;
}

void dlist_pushback(dlist* list, int data) {
	dnode* node = dnode_create(data, list->tail, NULL);
	if (list->head == NULL)
	{
		list->head = node;
		list->tail = node;
	}
	else
	{
		list->tail->prev = node;
		list->tail = node;
	}
	list->size++;
}

void dlist_clear(dlist* list) {
	if (list)
	{
		slist_clear(list);
		free(list);
	}
}

void dlist_print(dlist* list, const char* msg) {

}

int dlist_front(dlist* list) {
	return list->head->data;
}

int dlist_back(dlist* list) {
	return list->tail->data;
}
