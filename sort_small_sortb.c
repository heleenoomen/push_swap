#include"push_swap.h"

bool	closer_to_top(t_dlst *stack, int nbr) // count the amount of pushes before inserting
{
	int		mid;
	int		count;
	t_dnode	*i;

	mid = stack->size / 2;
	count = 0;
	i = stack->head;
	while (count <= mid)
	{
		if (nbr < i->nb)
			break ;
		if (nbr > i->nb)
			count++;
		i = i->next;
	}
	return (count <= mid);
}

void	insert_rb(t_dlst *stack_a, t_dlst *stack_b, int *ops)
{
	while (1)
	{
		if (stack_a->head->nb < stack_b->head->nb)
			break ;
		ft_rb(stack_b, ops);
	}
	ft_pb(stack_a, stack_b, ops);
	while (stack_b->head->nb != stack_b->min)
		ft_rrb(stack_b, ops);
}

void	insert_rrb(t_dlst *stack_a, t_dlst *stack_b, int *ops)
{
	int		nbr;
	
	nbr = stack_a->head->nb;
	ft_rrb(stack_b, ops);
	while (nbr < stack_b->tail->nb)
		ft_rrb(stack_b, ops);
	ft_pb(stack_a, stack_b, ops);
	while (stack_b->head->nb != stack_b->min)
		ft_rb(stack_b, ops);
}

void	ft_pb_sort(t_dlst *stack_a, t_dlst *stack_b, int *ops)
{
	if (stack_b->head == NULL)
		ft_pb(stack_a, stack_b, ops);
	else if (stack_a->head->nb < stack_b->head->nb)
		ft_pb(stack_a, stack_b, ops);
	else if (stack_a->head->nb < stack_b->head->next->nb ||
		stack_b->head == stack_b->tail)
	{
		ft_pb(stack_a, stack_b, ops);
		ft_sb(stack_b, ops);
	}
	else if (stack_a->head->nb > stack_b->tail->nb)
	{
		ft_pb(stack_a, stack_b, ops);
		ft_rb(stack_b, ops);
	}
	else if (closer_to_top(stack_b, stack_a->head->nb))
		insert_rb(stack_a, stack_b, ops);
	else
		insert_rrb(stack_a, stack_b, ops);
}

bool	min_closer_to_top(t_dlst *stack)
{
	t_dnode	*i;
	int		mid;
	int		count;

	i = stack->head;
	mid = stack->size / 2;
	count = 0;
	while (i->nb != stack->min && count <= mid)
	{
		count++;
		i = i->next;
	}
	return (count <= mid);
}

void	sort_small_sortb(t_dlst *stack_a, t_dlst *stack_b, int *ops)
{
	int	count;
	count = 0;
	while (stack_a->size > 3)
		ft_pb_sort(stack_a, stack_b, ops);
	ft_sort_three(stack_a, ops);
	while (stack_b->size)
		ft_pb_sort(stack_b, stack_a, ops);
	//ins_back(stack_a, stack_b, ops);
	if (min_closer_to_top(stack_a))
	{
		while (stack_a->head->nb != stack_a->min)
			ft_ra(stack_a, ops);
	}
	else
	{
		while (stack_a->head->nb != stack_a->min)
			ft_rra(stack_a, ops);
	}
}