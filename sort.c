#include"push_swap.h"

// void	ft_sort_two(t_dlst *a, int *ops)
// {
// 	if (a->head->nb <= a->tail->nb)
// 		print_sorted(a, ops);
// 	else 
// 		ft_sa(a, ops);
// }

// void	ft_sort_three(t_dlst *a, int *ops)
// {
// 	int	nbrs[3];
	
// 	nbrs[0] = a->head->nb;
// 	nbrs[1] = a->head->next->nb;
// 	nbrs[2] = a->tail->nb;
// 	if (nbrs[0] <= nbrs[1] && nbrs[1] <= nbrs[2])  // (1 2 3) WORKS
// 		return ;
// 	else if (nbrs[1] <= nbrs[0] && nbrs[0] <= nbrs[2]) // (2 1 3) WORKS
// 		ft_sa(a, ops);
// 	else if (nbrs[2] <= nbrs[0] && nbrs[0] <= nbrs[1])  // (2 3 1) WORKS
// 		ft_rra(a, ops);
// 	else if (nbrs[1] <= nbrs[2] && nbrs[2] <= nbrs[0])  // (3 1 2) WORKS
// 		ft_ra(a, ops);
// 	else if (nbrs[0] <= nbrs[2] && nbrs[2] <= nbrs[1])  // (1 3 2) WORKS
// 	{
// 		ft_sa(a, ops);
// 		ft_ra(a, ops);
// 	}
// 	else if (nbrs[2] <= nbrs[1] && nbrs[1] <= nbrs[0]) // (3 2 1) WORKS
// 	{
// 		ft_sa(a, ops);
// 		ft_rra(a, ops);
// 	}
// }

// void	ft_sort(t_dlst *a, t_dlst *sor, int *ops)
// {
// 	t_dlst	b;
	
// 	dlst_init(&b);
// 	if (a->size == 1)
// 		return ;
// 	if (a->size == 2)
// 		ft_sort_two(a, ops);
// 	else if (a->size < 21)
// 		sort_small(a, &b, ops);
// 	else
// 		sort_big(a, &b, sor, ops);
// 	dlst_clear(&b);
// }

void	push_to_org(t_dlst *a, t_dlst *b)
{
	t_dnode *i;
	int		mid;
	int		r;

	while (b->size)
		ft_p(b, a);
	i = a->head;
	mid = a->size / 2;
	r = 0;
	while (1)
	{
		if (i->nb == a->min)
			break ;
		r++;
		i = i->next;
	}
	if (r <= mid)
	{
		while (a->head->nb != a->min)
			ft_r(a);
		return ;
	}
	while (a->head->nb != a->min)
		ft_rr(a);
}

void	ft_sort(t_dlst *a)
{
	t_dlst	b;
	//int		i;
	
	dlst_init(&b, 'b');
	ft_p(a, &b);
	ft_p(a, &b);
	if (b.head->nb < b.tail->nb)
		ft_s(&b);
	//ps2;
	//int i = 0;
	while (a->size)// && i < 87)
	{
		push_to_dest(a, &b);
		//i++;
		//ps2;
	}
	//ps2;
	//push_last_q(a, &b);
	push_to_org(a, &b);
	dlst_clear(&b);
}
