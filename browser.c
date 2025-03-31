#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "function.h"
#include "browser.h"
#include "circular_list.h"

// Function that initialize the browser
browser_t *init_browser(page_t **pages)
{
	browser_t *browser = malloc(sizeof(browser_t));
	browser->list = create_cir_list(sizeof(tab_t *));

	tab_t *tab = create_tab(pages);

	add_cir_node(browser->list, 1, tab);
	browser->cur_tab = browser->list->sentinel->next;

	return browser;
}

// Function that adds a net tab
void new_tab(browser_t *browser, page_t **pages, int *id)
{
	(*id)++;
	tab_t *tab = create_tab(pages);
	tab->id = *id;
	add_cir_node(browser->list, browser->list->size, tab);
	browser->cur_tab = browser->list->sentinel->prev;
}

// Function that frees the browser
void free_browser(browser_t *browser)
{
	free_list(&browser->list);
	free(browser);
}

// Prints the contents of the browser
void print_browser(browser_t *browser)
{
	cir_node_t *cur_tab = browser->cur_tab;
	cir_node_t *p = cur_tab;

	do {
		if (p->data) {
			tab_t *x = p->data;
			printf("%d ", x->id);
		}
		p = p->next;
	} while(cur_tab != p);
	tab_t *x = cur_tab->data;
	printf("\n%s\n", x->curr_page->description);
}

// Function that closes the current tab
void close_tab(browser_t *browser)
{
	if (browser->cur_tab == browser->list->sentinel->next) {
		printf("403 Forbidden\n");
		return;
	}

	int n = 0;
	cir_node_t *p = browser->list->sentinel->next;

	while (p != browser->cur_tab) {

		n++;
		p = p->next;
	}
	browser->cur_tab = browser->cur_tab->prev;
	remove_cir_node(browser->list, n);
}

// Function that opens in a cur_tab a new page
void page(browser_t *browser, page_t **pages, FILE *in, int nr_pages)
{
	int id;
	fscanf(in, "%d", &id);
	tab_t *tab = browser->cur_tab->data;

	page_t *page = search_page(pages, id, nr_pages);

	if (page == NULL) {
		printf("403 Forbidden\n");
		return;
	}

	push(tab->back, tab->curr_page);
	tab->curr_page = page;
}

// Function that opens a specific tab
void open_tab(browser_t *browser, FILE *in)
{
	int id;
	fscanf(in, "%d", &id);

	cir_node_t *tab = search_tab(browser, id);
	if (tab == NULL) {
		printf("403 Forbidden\n");
		return;
	}

	browser->cur_tab = tab;

}

// Function that moves the cur_tab to the next tab
void next(browser_t *browser) 
{
	browser->cur_tab = browser->cur_tab->next;
	if (browser->cur_tab == browser->list->sentinel)
		browser->cur_tab = browser->cur_tab->next;
}


// Function that moves the cur_tab to the prev tab
void prev(browser_t *browser)
{
	browser->cur_tab = browser->cur_tab->prev;
	if (browser->cur_tab == browser->list->sentinel)
		browser->cur_tab = browser->cur_tab->prev;
}

// Print the history of a specific tab
void print_history(browser_t *browser, FILE *in) 
{
	int id;
	fscanf(in, "%d", &id);
	cir_node_t *tab = search_tab(browser, id);

	if (tab == NULL) {
		printf("403 Forbidden\n");
		return;
	}

	
}
