#pragma once
#include <stdio.h>
#include "browser.h"

// Function that read pages from the file
page_t **read_pages(FILE **input, int *nr_pages);

// Function that frees the pages
void free_pages(page_t ***p_pages);

// Functiont that allocs memory for a new tab
tab_t *create_tab(page_t **pages);

// Function that searches a specif id in a list of tabs
cir_node_t *search_tab(browser_t *browser, int id);

// Function that searches a page with a specific id
page_t *search_page(page_t **pages, int id, int nr_pages);

// Prints the stack
void print_stack(stack_t *s);

// Prints the stack reversed
void print_stack_rev(stack_t *s);
