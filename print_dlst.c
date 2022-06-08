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
	while (i != stack->tail)
	{
		ft_printf("\t%i\tid = %i\n", i->number, i->id);
		i = i->next;
	}
	ft_printf("\t%i\tid = %i\n", i->number, i->id);
	ft_printf("stack->head->number = %i\n", stack->head->number);
	ft_printf("stack->tail->number = %i\n", stack->tail->number);
	ft_printf("stack->head->previous->number = %i\n", stack->head->previous->number);
	ft_printf("stack->tail->next->number = %i\n", stack->tail->next->number);	
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
	while (i != stack->head)
	{
		ft_printf("\t%i\tid = %i\n", i->number, i->id);
		i = i->previous;
	}
	ft_printf("\t%i\tid = %i\n", i->number, i->id);
	ft_printf("stack->head->number = %i\n", stack->head->number);
	ft_printf("stack->tail->number = %i\n", stack->tail->number);
	ft_printf("stack->head->previous->number = %i\n", stack->head->previous->number);
	ft_printf("stack->tail->next->number = %i\n", stack->tail->next->number);	
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
	while (i != stack_a->tail)
	{
		ft_printf(" %i,", i->number);
		i = i->next;
	}
	ft_printf(" %i\n", i->number);
	ft_printf("operations: %i\n", *ops);
	ft_printf("-------------------------------\n");
}

void	print_liss(t_dlst *stack)
{
	t_dnode *i;
	int		value;
	
	i = stack->liss_ptr;
	value = 0;
	ft_printf("------------LISS:--------------\n");
	ft_printf("ofset is at: %i\n", stack->liss_ptr->number);
	while (1)
	{
		if (i->number >= value)
		{
			ft_printf("%i\n", i->number);
			value = i->number;
		}
		i = i->next;
		if (i == stack->liss_ptr)
			break ;
	}
	ft_printf("-------------------------------\n");
}

void	print_quickso_dlst(t_dnode *head, t_dnode *tail, t_dnode *i, t_dnode *j)
{
	ft_printf("-------------------------------\n");
	ft_printf("head->number = %i\thead->id = %i\n", head->number, head->id);
	ft_printf("tail->number = %i\ttail->id = %i\n", tail->number, tail->id);
	ft_printf("i->number = %i\t\ti->id = %i\n", i->number, i->id);
	ft_printf("j->number = %i\t\tj->id = %i\n", j->number, j->id);
	ft_printf("-------------------------------\n");
}