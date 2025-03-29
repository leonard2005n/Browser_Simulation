#pragma once
#include "stack.h"

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
	tab_t *cur_tab;
	
} browser;
