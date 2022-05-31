#include"push_swap.h"

void	ft_sort_two(t_dlst **head_a, t_dlst **head_b)
{
	if ((*head_a)->number < (*head_a)->next->number)
		print_sorted(head_a);
	else 
	{
		(ft_sa(head_a));
		print_sorted(head_a);
	}

	return ;
}

void	ft_sort_three(t_dlst **head_a, t_dlst **head_b)
{
	return ;
}

void	ft_sort_four(t_dlst **head_a, t_dlst **head_b)
{
	return ;
}

void	ft_sort_five(t_dlst **head_a, t_dlst **head_b)
{
	return ;
}

void	ft_sort(int argc, t_dlst **head_a, t_dlst **head_b, int *ops)
{
	if (argc == 2)
		ft_printf("we are sorted: %i\n", (*head_a)->number);
	else if (argc == 3)
		ft_sort_two(head_a, head_b);
	else if (argc == 4)
		ft_sort_three(head_a, head_b);
	else if (argc == 5)
		ft_sort_four(head_a, head_b);
	else if (argc == 6)
		ft_sort_five(head_a, head_b);
}