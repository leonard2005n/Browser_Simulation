#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "stack.h"
#include "browser.h"
#include "circular_list.h"
#include "function.h"

int main(void)
{
	// stack_t *s = create_stack(sizeof(int));
	// int v[] = {1, 2, 3, 4};

	// for (int i = 0; i < 4; i++) {
	// 	push(s, &v[i]);
	// }

	// for (int i = 0; i < 4; i++) {
	// 	int x = *(int*)peek(s);
	// 	printf("%d\n", x);
	// 	pop(s);
		
	// }

	// free_stack(&s);

	// cir_list_t *list = create_cir_list(sizeof(int));
	// int v[] = {1, 2, 3, 4};

	// add_cir_node(list, 0, &v[0]);
	// printf_int(list);

	// add_cir_node(list, 0, &v[3]);
	// printf_int(list);

	// add_cir_node(list, 200, &v[2]);
	// printf_int(list);
	// printf_int_rev(list);
	// add_cir_node(list, 2, &v[0]);
	// add_cir_node(list, 2, &v[1]);
	// printf_int(list);
	// remove_cir_node(list, 200);
	// printf_int(list);

	// free_list(&list);

	int nr_pages, n, id_tab = 0;
	char command[50];
	FILE *in = fopen("tema1.in", "r");

	if (in == NULL) {
        printf("Error opening file.\n");
        return 1;
    }

	page_t **pages = read_pages(&in, &nr_pages);
	// for (int i = 0; i < nr_pages; i++) {
	// 	printf("%d\n", pages[i]->id);
	// 	printf("%s\n", pages[i]->url);
	// 	printf("%s\n", pages[i]->description);
	// }
	fscanf(in, "%d", &n);
	browser_t *browser = init_browser(pages);
	// tab_t *tab = (tab_t *)browser->cur_tab->data;
	for (int i = 0; i < n; i++) {
		fscanf(in, "%s", command);
		if (strstr(command, "NEW_TAB")) {
			new_tab(browser, pages, &id_tab);
		} else if (strstr(command, "PRINT")) {
			print_browser(browser);
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
			
		}
	}

	free_browser(browser);
	free_pages(&pages);
	fclose(in);


	return 0;
} 
