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
		ft_printf("\t%i\tid = %i\n", i->nb, i->id);
		i = i->next;
	}
	ft_printf("\t%i\tid = %i\n", i->nb, i->id);
	ft_printf("stack->head->nb = %i\n", stack->head->nb);
	ft_printf("stack->tail->nb = %i\n", stack->tail->nb);
	ft_printf("stack->head->prev->nb = %i\n", stack->head->prev->nb);
	ft_printf("stack->tail->next->nb = %i\n", stack->tail->next->nb);
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
		ft_printf("\t%i\tid = %i\n", i->nb, i->id);
		i = i->prev;
	}
	ft_printf("\t%i\tid = %i\n", i->nb, i->id);
	ft_printf("stack->head->nb = %i\n", stack->head->nb);
	ft_printf("stack->tail->nb = %i\n", stack->tail->nb);
	ft_printf("stack->head->prev->nb = %i\n", stack->head->prev->nb);
	ft_printf("stack->tail->next->nb = %i\n", stack->tail->next->nb);	
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
		ft_printf(" %i,", i->nb);
		i = i->next;
	}
	ft_printf(" %i\n", i->nb);
	ft_printf("operations: %i\n", *ops);
	ft_printf("-------------------------------\n");
}

// void	print_liss(t_dlst *stack)
// {
// 	t_dnode *i;
// 	int		value;
	
// 	i = stack->liss_ptr;
// 	value = 0;
// 	ft_printf("------------LISS:--------------\n");
// 	ft_printf("ofset is at: %i\n", stack->liss_ptr->nb);
// 	while (1)
// 	{
// 		if (i->nb >= value)
// 		{
// 			ft_printf("%i\n", i->nb);
// 			value = i->nb;
// 		}
// 		i = i->next;
// 		if (i == stack->liss_ptr)
// 			break ;
// 	}
// 	ft_printf("-------------------------------\n");
// }

void	print_quickso_dlst(t_dnode *head, t_dnode *tail, t_dnode *i, t_dnode *j)
{
	ft_printf("-------------------------------\n");
	ft_printf("head->nb = %i\thead->id = %i\n", head->nb, head->id);
	ft_printf("tail->nb = %i\ttail->id = %i\n", tail->nb, tail->id);
	ft_printf("i->nb = %i\t\ti->id = %i\n", i->nb, i->id);
	ft_printf("j->nb = %i\t\tj->id = %i\n", j->nb, j->id);
	ft_printf("-------------------------------\n");
}

void	print_stacks(t_dlst *a, t_dlst *b)
{
	t_dnode *i;
	t_dnode *j;
	int		pad_a;
	int		pad_b;

	pad_a = 0;
	pad_b = 0;
	if (a->size > b->size)
		pad_b = a->size - b->size;
	if (a->size < b->size)
		pad_a = b->size - a->size;
	i = a->head;
	j = b->head;
	ft_printf("-------------------------------\n");
	ft_printf("stack a:\tstack b:\n");
	if (!pad_a && !pad_b)
	{
		while (i != a->tail && j != b->tail)
		{
			ft_printf("\t%i\t%i\n", i->nb, j->nb);
			i = i->next;
			j = j->next;
		}
		ft_printf("\t%i\t%i\n", i->nb, j->nb);
	}
	if (pad_a)
	{
		while (j != b->tail)
		{
			if (pad_a)
			{
				ft_printf("\t\t%i\n", j->nb);
				pad_a--;
				j = j->next;
			}
			else
			{
				ft_printf("\t%i\t%i\n", i->nb, j->nb);
				i = i->next;
				j = j->next;
			}
		}
		if (!pad_a)
		{
			ft_printf("\t%i", i->nb);
			ft_printf("\t%i\n", j->nb);
		}
		else
			ft_printf("\t\t%i\n", j->nb);
	}
	if (pad_b)
		{
		while (i != a->tail)
		{
			if (pad_b)
			{
				ft_printf("\t%i\n", i->nb);
				pad_b--;
				i = i->next;
			}
			else
			{
				ft_printf("\t%i\t%i\n", i->nb, j->nb);
				i = i->next;
				j = j->next;
			}
		}
		ft_printf("\t%i", i->nb);
		if (!pad_b)
			ft_printf("\t%i", j->nb);
		ft_printf("\n");
	}
	ft_printf("-------------------------------\n");
}
