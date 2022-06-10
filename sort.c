#include"push_swap.h"

void	ft_sort_two(t_dlst *a, int *ops)
{
	if (a->head->number <= a->tail->number)
		print_sorted(a, ops);
	else 
		ft_sa(a, ops);
}

void	ft_sort_three(t_dlst *a, int *ops)
{
	int	nbrs[3];
	
	nbrs[0] = a->head->number;
	nbrs[1] = a->head->next->number;
	nbrs[2] = a->tail->number;
	if (nbrs[0] <= nbrs[1] && nbrs[1] <= nbrs[2])  // (1 2 3) WORKS
		return ;
	else if (nbrs[1] <= nbrs[0] && nbrs[0] <= nbrs[2]) // (2 1 3) WORKS
		ft_sa(a, ops);
	else if (nbrs[2] <= nbrs[0] && nbrs[0] <= nbrs[1])  // (2 3 1) WORKS
		ft_rra(a, ops);
	else if (nbrs[1] <= nbrs[2] && nbrs[2] <= nbrs[0])  // (3 1 2) WORKS
		ft_ra(a, ops);
	else if (nbrs[0] <= nbrs[2] && nbrs[2] <= nbrs[1])  // (1 3 2) WORKS
	{
		ft_sa(a, ops);
		ft_ra(a, ops);
	}
	else if (nbrs[2] <= nbrs[1] && nbrs[1] <= nbrs[0]) // (3 2 1) WORKS
	{
		ft_sa(a, ops);
		ft_rra(a, ops);
	}
}

void	ft_sort(t_dlst *a, t_dlst *sor, int *ops)
{
	t_dlst	b;
	
	dlst_init(&b);
	if (a->size == 1)
		return ;
	if (a->size == 2)
		ft_sort_two(a, ops);
	else if (a->size < 21)
		sort_small(a, &b, ops);
	else
		sort_big(a, &b, sor, ops);
	sor->size = 15;
	dlst_clear(&b);
}

//comparison:
// numbers:		ops sort_small		ops. sortb
// 20			74					134
// 100			1580				2869