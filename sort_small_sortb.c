#include"push_swap.h"

void	insert_max(t_dlst *stack_a, t_dlst *stack_b, int *ops)
{
	int	count;
	int	mid;
	t_dnode *i;

	count = 0;
	mid = stack_a->size / 2;
	i = stack_a->tail;
	while (count <= mid && i->number != stack_a->max)
	{
		i = i->previous;
		count++;
	}
	if (count <= mid)
	{
		while (stack_a->tail->number != stack_a->max)
			ft_rra(stack_a, ops);
	}
	else
	{
		while (stack_a->tail->number != stack_a->max)
			ft_ra(stack_a, ops);
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
	while (count <= mid && i->number != stack_a->min)
	{
		i = i->next;
		count++;
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
	
	if (stack_b->size == 1 && v >= i->number && v <= i->next->number)
	{
		ft_pa(stack_a, stack_b, ops);
		ft_sa(stack_a, ops);
		return ; 
	}
	while (count <= mid && !(v <= i->number && v >= i->previous->number))
	{
		count++;
		i = i->next;
	}
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
	while (count <= mid && i->number != stack_a->min)
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

bool	closer_to_top(t_dlst *stack, int nbr) // count the amount of pushes before inserting
{
	int		mid;
	int		count;
	t_dnode	*i;

	mid = stack->size / 2;
	count = 2;
	i = stack->head->next->next;
	while (count <= mid)
	{
		if (nbr < i->number)
			break ;
		i = i->next;
	}
	return (count <= mid);
}

void	insert_rb(t_dlst *stack_a, t_dlst *stack_b, int *ops)
{
	t_dnode	*i;

	i = stack_b->head->next->next;
	while (1)
	{
		if (stack_a->head->number < i->number)
			break ;
		ft_rb(stack_b, ops);
	}
	ft_pb(stack_a, stack_b, ops);
	while (stack_b->head->number != stack_b->min)
		ft_rrb(stack_b, ops);
}

void	insert_rrb(t_dlst *stack_a, t_dlst *stack_b, int *ops)
{
	int		nbr;
	
	nbr = stack_a->head->number;
	ft_rrb(stack_b, ops);
	while (nbr < stack_b->head)
		ft_rrb;
	ft_pb(stack_a, stack_b, ops);
	while (stack_b->head != stack_b->min)
		ft_rb;
}

void	ft_pb_sort(t_dlst *stack_a, t_dlst *stack_b, int *ops)
{
	if (stack_b->head == NULL)
		ft_pb(stack_a, stack_b, ops);
	else if(stack_a->head->number < stack_b->head->number)
		ft_pb(stack_a, stack_b, ops);
	else if(stack_a->head->number < stack_b->head->next->number ||
		stack_b->head == stack_b->tail)
	{
		ft_pb(stack_a, stack_b, ops);
		ft_sb(stack_b, ops);
	}
	else if (stack_a->head->number > stack_b->tail->number)
	{
		ft_pb(stack_a, stack_b, ops);
		ft_rb(stack_b, ops);
	}
	else if (closer_to_top(stack_b, stack_a->head->number))
		insert_rb(stack_a, stack_b, ops);
	else
		insert_rrb(stack_a, stack_b, ops);
}

void	insert_back_ra(stack_a, stack_b, ops)
{
	
}


void	sort_small_sortb(t_dlst *stack_a, t_dlst *stack_b, int *ops)
{
	while (stack_a->size > 3)
		ft_pb_sort(stack_a, stack_b, ops);
	ft_sort_three(stack_a, ops);
	if (closer_to_top(stack_a, stack_b->head->number))
		insert_back_ra(stack_a, stack_b, ops);
	else
		insert_back_rra(stack_a, stack_b, ops);
}