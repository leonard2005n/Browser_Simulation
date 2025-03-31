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