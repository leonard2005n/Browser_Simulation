#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "circular_list.h"

// Function that creates a circular list with sentinel
cir_list_t *create_cir_list(unsigned int data_size)
{
	cir_list_t *list = calloc(1, sizeof(cir_list_t));
	list->sentinel = calloc(1, sizeof(cir_node_t));
	list->data_size = data_size;
	return list;
}

// Function that add a node
void add_cir_node(cir_list_t *list, unsigned int n, void *data)
{
	cir_node_t *new = calloc(1, sizeof(cir_node_t));
	new->data = calloc(1, list->data_size);
	memcpy(new->data, data, list->data_size);
	
	if (list->size == 0) {
		list->sentinel->next = new;
		list->sentinel->prev = new;
		new->next = list->sentinel;
		new->prev = list->sentinel;
		list->size++;
		return;
	}

	if (n == 0) {
		new->next = list->sentinel->next;
		new->prev = list->sentinel;
		list->sentinel->next->prev = new;
		list->sentinel->next = new;
		list->size++;
		return;
	}

	if (n >= list->size) {
		list->sentinel->prev->next = new;
		new->prev = list->sentinel->prev;
		new->next = list->sentinel;
		list->sentinel->prev = new;
		list->size++;
		return;
	}

	cir_node_t *p = list->sentinel->next;

	for (unsigned int i = 0; i < n && i < list->size; i++) {
		p = p->next;
	}

	new->next = p;
	new->prev = p->prev;
	p->prev->next = new;
	p->prev = new;
	list->size++;
}

// Function that removes the node form the list
void remove_cir_node(cir_list_t *list, unsigned int n)
{
	if (list->size == 0)
		return;

	n++;
	cir_node_t *p = list->sentinel;

	for (unsigned int i = 0; i < n && i < list->size; i++) {
		p = p->next;
	}

	p->prev->next = p->next;
	p->next->prev = p->prev;
	free_cir_node(&p);
	list->size--;
}

// Function that frees the node 
void free_cir_node(cir_node_t **c_node)
{
	cir_node_t *node = *c_node;
	free(node->data);
	free(node);
	*c_node = NULL;
}

// Function that prints the int
void printf_int(cir_list_t *list)
{
	cir_node_t *p = list->sentinel->next;

	for (unsigned int i = 0; i < list->size; i++) {
		int *x = (int *)p->data;
		printf("%d ", *x);
		p = p->next;
	}
	printf("\n");
}

// Function that prints the int
void printf_int_rev(cir_list_t *list)
{
	cir_node_t *p = list->sentinel->prev;

	for (unsigned int i = 0; i < list->size; i++) {
		int *x = (int *)p->data;
		printf("%d ", *x);
		p = p->prev;
	}
	printf("\n");
}

// Function that free the list
void free_list(cir_list_t **cir_list)
{
	cir_list_t *list = *cir_list;
	cir_node_t *p = list->sentinel, *aux;

	for (unsigned int i = 0; i < list->size + 1; i++) {
		aux = p;
		p = p->next;
		free_cir_node(&aux);
	}
	free(list);
	
}
