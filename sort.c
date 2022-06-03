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
	ft_pa(stack_a, stack_b, ops);
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
	print_sorted(stack_a, ops);
	print_dlst(stack_a, "stack a");
	print_dlst_rev(stack_a, "stack a reverse:");
}
