#include"push_swap.h"

void	sort_two(t_dlst *a)
{
		ft_s(a);
		exit(0);
}

void	sort_three(t_dlst *a)
{
	if (a->head->next->nb < a->head->nb && a->head->nb < a->tail->nb)
		ft_s(a);
	else if (a->tail->nb < a->head->nb && a->head->nb < a->head->next->nb)
		ft_rr(a);
	else if (a->head->next->nb < a->tail->nb && a->tail->nb < a->head->nb)
		ft_r(a);
	else if (a->head->nb < a->tail->nb && a->tail->nb < a->head->next->nb)
	{
		ft_s(a);
		ft_r(a);
	}
	else if (a->tail->nb < a->head->next->nb && a->head->next->nb < a->head->nb)
	{
		ft_s(a);
		ft_rr(a);
	}
	exit (0);
}

void	sort_three_b(t_dlst *a)
{
	if (a->head->next->nb < a->head->nb && a->head->nb < a->tail->nb)
		ft_s(a);
	else if (a->head->nb < a->tail->nb && a->tail->nb < a->head->next->nb)
		ft_s(a);
	else if (a->tail->nb < a->head->next->nb && a->head->next->nb < a->head->nb)
		ft_s(a);
}

void	ft_push_sort(t_dlst *a, t_dlst *b)
{
	int i = 0;
	//ps;
	while (b->size && i < 100)
	{
		push_to_dest(b, a);
		//ps;
		i++;
	}
	//push_to_org(a, b);
}

void	sort_small(t_dlst *a, t_dlst *b)
{
	if (a->size == 2)
		sort_two(a);
	if (a->size == 3)
		sort_three(a);
	while (a->size > 3)
		ft_p(a, b);
	//ps;
	sort_three_b(a);
	//ps;
	ft_push_sort(a, b);
	//ps;
}