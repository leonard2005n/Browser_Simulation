#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "stack.h"

// Function that creates a stack
stack_t *create_stack(unsigned int data_size) 
{
	stack_t *s = calloc(1, sizeof(stack_t));
	s->data_size = data_size;
	return s;
}

// Function that deletes a node form the stack
void pop(stack_t *s)
{
	if (is_empty(s))
		return;

	node_t *aux = s->head;
	s->head = s->head->next;
	free_node(&aux);
	s->size--;
}

// Function that adds a element to the stack
void push(stack_t *s, void *data)
{
	s->size++;

	// Createing a new node
	node_t *new = calloc(1, sizeof(node_t));
	new->next = s->head;
	// new->data = calloc(1, s->data_size);
	// memcpy(new->data, data, s->data_size);
	new->data = data;

	s->head = new;
}

// Function that frees a node
void free_node(node_t **node)
{
	node_t *aux = *node;
	// free(aux->data);
	free(aux);
	*node = NULL;
}

// Function that determits if the stack is empty
int is_empty(stack_t *s)
{
	if (s->size == 0)
		return 1;
	
	return 0;
}


// Function that returns the value of the top stack element
void *peek(stack_t *s)
{
	if (is_empty(s))
		return NULL;

	return s->head->data;
}

// Function that frees the stack structure
void free_stack(stack_t **stack)
{
	stack_t *s = *stack;

	while (!is_empty(s))
		pop(s);

	free(s);
	*stack = NULL;
}
