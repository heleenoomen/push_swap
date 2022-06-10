#include"push_swap.h"

void	insa_max(t_dlst *a, t_dlst *b, int *ops)
{
	int	count;
	int	mid;
	t_dnode *i;

	count = 0;
	mid = a->size / 2;
	i = a->tail;
	while (count <= mid && i->nb != a->max)
	{
		i = i->prev;
		count++;
	}
	if (count <= mid)
	{
		while (a->tail->nb != a->max)
			ft_rra(a, ops);
	}
	else
	{
		while (a->tail->nb != a->max)
			ft_ra(a, ops);
	}
	ft_pa(a, b, ops);
}

void	insa_min(t_dlst *a, t_dlst *b, int *ops)
{
	int	count;
	int	mid;
	t_dnode *i;

	count = 0;
	mid = a->size / 2;
	i = a->head;
	while (count <= mid && i->nb != a->min)
	{
		i = i->next;
		count++;
	}
	if (count <= mid)
	{
		while (a->head->nb != a->min)
			ft_ra(a, ops);
	}
	else
	{
		while (a->head->nb != a->min)
			ft_rra(a, ops);
	}
	ft_pa(a, b, ops);
}

void	insa_inbetw(t_dlst *a, t_dlst *b, int *ops)
{
	int	v;
	int	count;
	int	mid;
	t_dnode *i;

	v = b->head->nb;
	count = 0;
	mid = a->size / 2;
	i = a->head;
	
	if (b->size == 1 && a->head->nb > b->head->nb && a->head->nb < a->head->next->nb)
	{
		ft_pa(a, b, ops);
		ft_sa(a, ops);
		return ; 
	}
	while (count <= mid && !(v < i->nb && v > i->prev->nb))
	{
		count++;
		i = i->next;
	}
	if (count <= mid)
	{
		while (!(a->head->nb > v && a->tail->nb < v))
			ft_ra(a, ops);
	}
	else
	{
		while (!(a->head->nb > v && a->tail->nb < v))
			ft_rra(a, ops);
	}
	ft_pa(a, b, ops);
}

void	final_rotation(t_dlst *a, int *ops)
{
	t_dnode	*i;
	int		count;
	int		mid;

	mid = a->size / 2;
	count = 0;
	i = a->head;
	while (count <= mid && i->nb != a->min)
	{
		count++;
		i = i->next;
	}
	if (count <= mid)
	{
		while (a->head->nb != a->min)
			ft_ra(a, ops);
	}
	else
	{
		while (a->head->nb != a->min)
			ft_rra(a, ops);
	}
	while (a->tail->nb == a->min)
		ft_rra(a, ops);
}

void	sort_small(t_dlst *a, t_dlst *b, int *ops)
{
	while (a->size > 3)
		ft_pb(a, b, ops);
	ft_sort_three(a, ops);
	while (b->size > 0)
	{
		if (b->head->nb > a->max)
			insa_max(a, b, ops);
		else if (b->head->nb < a->min)
			insa_min(a, b, ops);
		else
			insa_inbetw(a, b, ops);
	}
	final_rotation(a, ops);
}