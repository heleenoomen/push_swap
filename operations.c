#include"push_swap.h"

void	ft_sa(t_dlst *stack_a, int *ops)
{
	t_dnode	*t;

	t = stack_a->head;
	stack_a->head = stack_a->head->next;
	if (stack_a->head->next == NULL)
		t->next = NULL;
	else
		t->next = stack_a->head->next;
	stack_a->head->next = t;
	ft_printf("sa\n");
	(*ops)++;
}
