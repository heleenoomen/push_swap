#include"push_swap.h"

void	insert_max(t_dlst *stack_a, t_dlst *stack_b, int *ops)
{
	int	count;
	int	mid;
	t_dnode *i;

	count = 0;
	mid = stack_a->size / 2;
	i = stack_a->head;
	while (count < mid && i->number != stack_a->max)
		i = i->next;
	if (count <= mid)
	{
		while (stack_a->tail->number != stack_a->max)
			ft_ra(stack_a, ops);
	}
	else
	{
		while (stack_a->tail->number != stack_a->max)
			ft_rra(stack_a, ops);
	}
	ft_pa(stack_a, stack_b, ops);
}

void	insert_min(t_dlst *stack_a, t_dlst *stack_b, int *ops)
{
	int	count;
	int	mid;
	t_dnode *i;

	count = 0;
	mid = stack_a->size / 2;
	i = stack_a->head;
	while (count < mid && i->number != stack_a->min)
		i = i->next;
	if (count <= mid)
	{
		while (stack_a->head->number != stack_a->min)
			ft_ra(stack_a, ops);
	}
	else
	{
		while (stack_a->head->number != stack_a->min)
			ft_rra(stack_a, ops);
	}
	ft_pa(stack_a, stack_b, ops);
}

void	insert_inbetw(t_dlst *stack_a, t_dlst *stack_b, int *ops)
{
	int	v;
	int	count;
	int	mid;
	t_dnode *i;

	v = stack_b->head->number;
	count = 0;
	mid = stack_a->size / 2;
	i = stack_a->head;
	while (count < mid && !(stack_a->head->number >= v && stack_a->tail->number <= v))
		count++;
	if (count <= mid)
	{
		while (!(stack_a->head->number >= v && stack_a->tail->number <= v))
			ft_ra(stack_a, ops);
	}
	else
	{
		while (!(stack_a->head->number >= v && stack_a->tail->number <= v))
			ft_rra(stack_a, ops);
	}
	ft_pa(stack_a, stack_b, ops);
}

void	final_rotation(t_dlst *stack_a, int *ops)
{
	t_dnode	*i;
	int		count;
	int		mid;

	mid = stack_a->size / 2;
	count = 0;
	i = stack_a->head;
	while (count < mid && i->number != stack_a->min)
	{
		count++;
		i = i->next;
	}
	if (count <= mid)
	{
		while (stack_a->head->number != stack_a->min)
			ft_ra(stack_a, ops);
	}
	else
	{
		while (stack_a->head->number != stack_a->min)
			ft_rra(stack_a, ops);
	}
	while (stack_a->tail->number == stack_a->min)
		ft_rra(stack_a, ops);
}

void	sort_small(t_dlst *stack_a, t_dlst *stack_b, int *ops)
{
	while (stack_a->size > 3)
		ft_pb(stack_a, stack_b, ops);
	ft_sort_three(stack_a, ops);
	while (stack_b->size > 0)
	{
		if (stack_b->head->number >= stack_a->max)
			insert_max(stack_a, stack_b, ops);
		else if (stack_b->head->number <= stack_a->min)
			insert_min(stack_a, stack_b, ops);
		else
			insert_inbetw(stack_a, stack_b, ops);
	}
	final_rotation(stack_a, ops);
}