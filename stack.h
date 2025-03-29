#pragma once

// A struct that defines a node
typedef struct node_t node_t;
struct node_t{
	void *data;
	node_t *next;
};

// A struct that defines a stack
typedef struct stack_t stack_t;
struct stack_t{
	unsigned int data_size;
	node_t *head;
	unsigned int size;
};

// Function that creates a stack
stack_t *create_stack(unsigned int data_size);

// Function that deletes a node form the stack
void pop(stack_t *s);

// Function that frees a node
void free_node(node_t **node);

// Function that returns the value of the top stack element
void *peek(stack_t *s);

// Function that determits if the stack is empty
int is_empty(stack_t *s);

// Function that frees the stack structure
void free_stack(stack_t **stack);

// Function that adds a element to the stack
void push(stack_t *s, void *data);
