#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "stack.h"
#include "browser.h"
#include "circular_list.h"
#include "function.h"

int main(void)
{
	int nr_pages, n, id_tab = 0;
	char command[50];
	FILE *in = fopen("tema1.in", "r");

	if (!in) {
		printf("Error opening file.\n");
		return 1;
	}

	page_t **pages = read_pages(&in, &nr_pages);
	fscanf(in, "%d", &n);
	browser_t *browser = init_browser(pages);
	for (int i = 0; i < n; i++) {
		fscanf(in, "%s", command);
		if (strstr(command, "NEW_TAB")) {
			new_tab(browser, pages, &id_tab);
		} else if (strstr(command, "CLOSE")) {
			close_tab(browser);
		} else if (strstr(command, "OPEN")) {
			open_tab(browser, in);
		} else if (strstr(command, "NEXT")) {
			next(browser);
		} else if (strstr(command, "PREV")) {
			prev(browser);
		} else if (strstr(command, "PAGE")) {
			page(browser, pages, in, nr_pages);
		} else if (strstr(command, "PRINT_HISTORY")) {
			print_history(browser, in);
		} else if (strstr(command, "PRINT")) {
			print_browser(browser);
		} else if (strstr(command, "BACKWARD")) {
			backward(browser);
		} else if (strstr(command, "FORWARD")) {
			forward(browser);
		}
	}

	free_browser(browser);
	free_pages(&pages);
	fclose(in);

	return 0;
}
