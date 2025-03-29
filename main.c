#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "stack.h"
#include "browser.h"
#include "circular_list.h"

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

	cir_list_t *list = create_cir_list(sizeof(int));
	int v[] = {1, 2, 3, 4};

	add_cir_node(list, 0, &v[0]);
	printf_int(list);

	add_cir_node(list, 0, &v[3]);
	printf_int(list);

	add_cir_node(list, 200, &v[2]);
	printf_int(list);
	printf_int_rev(list);
	add_cir_node(list, 2, &v[0]);
	add_cir_node(list, 2, &v[1]);
	printf_int(list);
	remove_cir_node(list, 200);
	printf_int(list);

	free_list(&list);
	return 0;
} 
