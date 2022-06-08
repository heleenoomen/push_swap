#include"push_swap.h"

void	ft_sort_two(t_dlst *stack_a, int *ops)
{
	if (stack_a->head->number <= stack_a->tail->number)
		print_sorted(stack_a, ops);
	else 
		ft_sa(stack_a, ops);
}

void	ft_sort_three(t_dlst *stack_a, int *ops)
{
	int	nbrs[3];
	
	nbrs[0] = stack_a->head->number;
	nbrs[1] = stack_a->head->next->number;
	nbrs[2] = stack_a->tail->number;
	if (nbrs[0] <= nbrs[1] && nbrs[1] <= nbrs[2])  // (1 2 3) WORKS
		return ;
	else if (nbrs[1] <= nbrs[0] && nbrs[0] <= nbrs[2]) // (2 1 3) WORKS
		ft_sa(stack_a, ops);
	else if (nbrs[2] <= nbrs[0] && nbrs[0] <= nbrs[1])  // (2 3 1) WORKS
		ft_rra(stack_a, ops);
	else if (nbrs[1] <= nbrs[2] && nbrs[2] <= nbrs[0])  // (3 1 2) WORKS
		ft_ra(stack_a, ops);
	else if (nbrs[0] <= nbrs[2] && nbrs[2] <= nbrs[1])  // (1 3 2) WORKS
	{
		ft_sa(stack_a, ops);
		ft_ra(stack_a, ops);
	}
	else if (nbrs[2] <= nbrs[1] && nbrs[1] <= nbrs[0]) // (3 2 1) WORKS
	{
		ft_sa(stack_a, ops);
		ft_rra(stack_a, ops);
	}
}

void	ft_sort_four(t_dlst *stack_a, t_dlst *stack_b, int *ops)
{
	ft_pb(stack_a, stack_b, ops);
	ft_sort_three(stack_a, ops);
	if (stack_b->head->number > stack_a->tail->number)
	{
		ft_pa(stack_a, stack_b, ops);
		ft_ra(stack_a, ops);
		return ;
	}
	if (stack_b->head->number > stack_a->tail->previous->number)
	{
		ft_rra(stack_a, ops);
		ft_pa(stack_a, stack_b, ops);
		ft_ra(stack_a, ops);
		ft_ra(stack_a, ops);
		return ;
	}
	if (stack_b->head->number < stack_a->head->number)
	{
		ft_pa(stack_a, stack_b, ops);
		return ; 
	}
	ft_pa(stack_a, stack_b, ops);
	ft_sa(stack_a, ops);
	return ;
}

void	ft_sort_five(t_dlst *stack_a, t_dlst *stack_b, int *ops)
{
	stack_a = NULL;
	stack_b = NULL;
	(*ops)++;
	return ;
}

void	ft_sort(int argc, t_dlst *stack_a, t_dlst *stack_b, int *ops)
{
	if (argc == 2)
		ft_printf("we are sorted: %i\n", (stack_a->head)->number);
	else if (argc == 3)
		ft_sort_two(stack_a, ops);
	else if (argc == 4)
		ft_sort_three(stack_a, ops);
	else if (argc == 5)
		ft_sort_four(stack_a, stack_b, ops);
	else if (argc == 6)
		ft_sort_five(stack_a, stack_b, ops);
	//print_sorted(stack_a, ops);
	//print_dlst(stack_a, "stack a");
	//print_dlst_rev(stack_a, "stack a reverse:");
}

bool	closer_to_top(t_dlst *stack_a, t_dlst *stack_b)
{
	t_dnode *i;
	int		mid;
	int		count;
	int		v;
	
	v = stack_b->head->number;
	i = stack_a->head;
	mid = stack_a->size / 2;
	count = 0;
	while (count <= mid)
	{
		if (v >= stack_a->max && i->number == stack_a->max)
			break ;
		else if (v <= stack_a->min && i->number == stack_a->min)
			break ;
		else if (v >= i->number && v <= i->next->number)
			break ;
		count++;
		i = i->next;
	}
	if (count <= mid)
		return (1);
	return (0);
}

void	ins_top(t_dlst *stack_a, t_dlst *stack_b, int *ops)
{
	int		v;

	v = stack_b->head->number;
	if (v == stack_b->min)
	{
		while (stack_a->head != stack_a->min)
			ft_ra(stack_a, ops);
	}
	else if (v == stack_b->max)
	{
		while (stack_a->tail != stack_a->max)
			ft_ra(stack_a, ops);
	}
	else
	{
		while (!(v >= stack_a->head && v <= stack_a->tail))
			ft_ra(stack_a, ops);
	}
	ft_pa(stack_a, stack_b, ops);
}

void	ins_bottom(t_dlst *stack_a, t_dlst *stack_b, int *ops)
{
	int		v;

	v = stack_b->head->number;
	if (v == stack_b->min)
	{
		while (stack_a->head != stack_a->min)
			ft_rra(stack_a, ops);
	}
	else if (v == stack_b->max)
	{
		while (stack_a->tail != stack_a->max)
			ft_rra(stack_a, ops);
	}
	else
	{
		while (!(v >= stack_a->head && v <= stack_a->tail))
			ft_rra(stack_a, ops);
	}
	ft_pa(stack_a, stack_b, ops);
}

void	ft_sort_small(int argc, t_dlst *stack_a, t_dlst *stack_b, int *ops)
{
	int	max;
	int	min;

	while (stack_a->size > 3)
		ft_pb(stack_a, stack_b, ops);
	ft_sort_three(stack_a, ops);
	while (stack_b->size > 0)
	{
		if (closer_to_top(stack_a, stack_b))
			ins_top(stack_a, stack_b, ops);
		else
			ins_bottom(stack_a, stack_b, ops);
	}
}

void	ft_sort_two(int argc, t_dlst *stack_a, t_dlst *stack_b, int *ops)
{
	if (argc = 2)
		return ;
	else if (argc < 7)
		ft_sort_small(argc, stack_a, stack_b, ops);
	else if (argc < 12)
		ft_sort_middle(argc, stack_a, stack_b, ops);
	else
		ft_sort_large(argc, stack_a, stack_b, ops);
}