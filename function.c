#include <stdio.h>
#include <stdlib.h>	
#include <string.h>
#include "function.h"
#include "browser.h"

// Function that read pages from the file
page_t **read_pages(FILE **input, int *nr_pages)
{	
	FILE *in = *input;
	int n;
	char desc[200], def[] = "Computer Science";
	page_t **pages = malloc(50 *sizeof(page_t *));

	for (int i = 0; i < 50; i++) {
		pages[i] = calloc(1, sizeof(page_t));
	}

	strcpy(pages[0]->url, "https://acs.pub.ro/");
	pages[0]->description = strdup(def);

	fscanf(in, "%d", &n);
	for (int i = 1; i <= n; i++) {
		fscanf(in, "%d %s", &pages[i]->id, pages[i]->url);
		fgets(desc, 200, in);
		fgets(desc, 200, in);
		desc[strlen(desc) - 1] = 0;
		pages[i]->description = strdup(desc);
	}

	*nr_pages = n + 1;
	return pages;
}


// Function that frees the pages
void free_pages(page_t ***p_pages)
{
	page_t **pages = *p_pages;
	for (int i = 0; i < 50; i++) {
		if (pages[i]->description != 0) {
			free(pages[i]->description);
		}
		free(pages[i]);
	}

	free(pages);
	*p_pages = NULL;
}

// Functiont that allocs memory for a new tab
tab_t *create_tab(page_t **pages)
{
	tab_t *tab = malloc(sizeof(tab_t));
	tab->forward = create_stack(sizeof(int));
	tab->back = create_stack(sizeof(int));
	tab->id = 0;
	tab->curr_page = pages[0];

	return tab;
}

// Function that searches a specif id in a list of tabs
cir_node_t *search_tab(browser_t *browser, int id)
{
	cir_node_t *p = browser->list->sentinel->next;
	
	while (p != browser->list->sentinel) {
		tab_t *tab = p->data;
		if (tab->id == id)
			return p;
		p = p->next;
	}
	return NULL;
}

// Function that searches a page with a specific id
page_t *search_page(page_t **pages, int id, int nr_pages)
{

	for (int i = 0; i <= nr_pages; i++) {
		if (pages[i]->id == id)
			return pages[i];
	}
	return NULL;
}