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
	while (b->size > 2)
	{
		push_to_dest(b, a);
		//ps;
		i++;
	}
	// if (b->head->nb < b->tail->nb)
	// {
	// 	ft_s(b);
	// }
	//push_to_dest(b, a);
	if (b->head->nb < a->min && a->head->nb == a->min && b->tail->nb < a->head->next->nb
		&& b->head->nb == b->min)
	{
		ft_s(b);
		ft_p(b, a);
		if (!is_sorted(a))
			ft_s(a);
		ft_p(b, a);
	}
	else
		push_to_dest(b, a);
	if (b->head->nb > a->head->nb && b->head->nb < a->head->next->nb)
	{
		ft_p(b, a);
		ft_s(a);
	}
	else if (b->head->nb > a->head->next->nb && b->head->nb < a->head->next->next->nb)
	{
		ft_r(a);
		ft_p(b, a);
		ft_s(a);
	}
	else
		push_to_dest(b, a);
	push_to_org(a, b);
}

void	sort_small(t_dlst *a, t_dlst *b)
{
	if (a->size == 2)
		sort_two(a);
	if (a->size == 3)
		sort_three(a);
	//if (a->head->nb == a->max && a->tail->nb > a->tail->prev->nb)
		//ft_r(a);
	while (a->size > 3)
	{
		// if (a->head->nb != a->max)
		// 	ft_p(a, b);
		ft_p(a, b);
	}//ps;
	//ps;
	sort_three_b(a);
	//ps;
	ft_push_sort(a, b);
	//ps;
}