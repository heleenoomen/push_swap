#include"push_swap.h"

void	ft_sort_two(t_dlst *stack_a, int *ops)
{
	if (stack_a->head->number < stack_a->tail->number)
		print_sorted(stack_a, ops);
	else 
	{
		ft_sa(stack_a, ops);
		print_sorted(stack_a, ops);
	}
}

void	ft_sort_three(t_dlst *stack_a, t_dlst *stack_b, int *ops)
{
	stack_a = NULL;
	stack_b = NULL;
	(*ops)++;
	return ;
}

void	ft_sort_four(t_dlst *stack_a, t_dlst *stack_b, int *ops)
{
	
	stack_a = NULL;
	stack_b = NULL;
	(*ops)++;
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
		ft_sort_three(stack_a, stack_b, ops);
	else if (argc == 5)
		ft_sort_four(stack_a, stack_b, ops);
	else if (argc == 6)
		ft_sort_five(stack_a, stack_b, ops);
}
