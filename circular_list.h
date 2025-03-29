#pragma once

typedef struct cir_node_t cir_node_t;
struct cir_node_t {
	cir_node_t *next, *prev;
	void *data;
};

typedef struct cir_list_t cir_list_t;
struct cir_list_t {
	cir_node_t *sentinel;
	unsigned int size;
	unsigned int data_size;
};

// Function that creates a circular list with sentinel
cir_list_t *create_cir_list(unsigned int data_size);

// Function that add a node
void add_cir_node(cir_list_t *list, unsigned int n, void *data);

// Function that frees the node 
void free_cir_node(cir_node_t **c_node);

// Function that removes the node form the list
void remove_cir_node(cir_list_t *list, unsigned int n);

// Function that prints the int
void printf_int(cir_list_t *list);

// Function that free the list
void free_list(cir_list_t **cir_list);

// Function that prints the int
void printf_int_rev(cir_list_t *list);