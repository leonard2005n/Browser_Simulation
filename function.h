#pragma once
#include <stdio.h>
#include "browser.h"

// Function that read pages from the file
page_t **read_pages(FILE **input, int *nr_pages);

// Function that frees the pages
void free_pages(page_t ***p_pages);

// Functiont that allocs memory for a new tab
tab_t *create_tab(page_t **pages);