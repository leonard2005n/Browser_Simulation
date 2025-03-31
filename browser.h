#pragma once
#include "stack.h"
#include "circular_list.h"

// A struct that defines the page
typedef struct {
	int id;
	char url[50];
	char *description;
} page_t;


// A struct that defines a tab
typedef struct {
	int id;
	page_t *curr_page;
	stack_t *back, *forward;
} tab_t;

typedef struct {
	cir_node_t *cur_tab;
	cir_list_t *list;
} browser_t;

// Function that initialize the browser
browser_t *init_browser(page_t **pages);

// Function that adds a net tab
void new_tab(browser_t *browser, page_t **pages, int *id);

// Function that frees the browser
void free_browser(browser_t *browser);

// Prints the contents of the browser
void print_browser(browser_t *browser);

// Function that closes the current tab
void close_tab(browser_t *browser);

// Function that opens a specific tab
void open_tab(browser_t *browser, FILE *in);

// Function that moves the cur_tab to the next tab
void next(browser_t *browser);

// Function that moves the cur_tab to the prev tab
void prev(browser_t *browser);

// Function that opens in a cur_tab a new page
void page(browser_t *browser, page_t **pages, FILE *in, int nr_pages);
