#include "push_swap.h"

void print_list(t_stack stack)
{
	t_node *temp = NULL;
	if (!(is_empty_list(stack)))
		temp = stack->begin;
	while(temp != NULL)
	{
		printf("[%d] ", temp->value);
		temp = temp->next;
	}

	printf("END\n");
}
