#include"push_swap.h"

void	print_dlst(t_dlst *stack, char *name)
{
	t_dnode	*i;

	ft_printf("-----------------------------\n");
	ft_printf("%s:\n", name);
	i = stack->head;
	if (i == NULL)
	{
		ft_printf("\tlist is NULL\n");
		return ;
	}
	while (i != NULL)
	{
		ft_printf("\t%i\n", i->number);
		i = i->next;
	}
	ft_printf("stack->head->number = %i\n", stack->head->number);
	ft_printf("stack->tail->number = %i\n", stack->tail->number);
	ft_printf("-----------------------------\n");
}

void	print_dlst_rev(t_dlst *stack, char *name)
{
	t_dnode	*i;

	ft_printf("-----------------------------\n");
	ft_printf("%s:\n", name);
	i = stack->tail;
	if (i == NULL)
	{
		ft_printf("\tlist is NULL\n");
		return ;
	}
	while (i != NULL)
	{
		ft_printf("\t%i\n", i->number);
		i = i->previous;
	}
	ft_printf("stack->head->number = %i\n", stack->head->number);
	ft_printf("stack->tail->number = %i\n", stack->tail->number);
	ft_printf("-----------------------------\n");
}

void	print_sorted(t_dlst *stack_a, int *ops)
{
	t_dnode	*i; 
	
	ft_printf("------------SORTED-------------\n");
	i = stack_a->head;
	if (i == NULL)
	{
		ft_printf("Error print_sorted: head is NULL\n");
		return ;
	}
	ft_printf("We are sorted:");
	while (i->next != NULL)
	{
		ft_printf(" %i,", i->number);
		i = i->next;
	}
	ft_printf(" %i\n", i->number);
	ft_printf("operations: %i\n", *ops);
	ft_printf("-------------------------------\n");
}
