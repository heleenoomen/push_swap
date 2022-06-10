#include"push_swap.h"

void	insb_max(t_dlst *a, t_dlst *b, int *ops)
{
	if (r_is_faster_max(b))
	{
		while (b->tail->nb != b->max)
			ft_rb(b, ops);
	}
	else
	{
		while (b->tail->nb != b->max)
			ft_rrb(a, ops);
	}
	ft_pb(a, b, ops);
}

void	insb_min(t_dlst *a, t_dlst *b, int *ops)
{
	if (r_is_faster_min(b))
	{
		while (b->head->nb != b->min)
			ft_rb(b, ops);
	}
	else
	{
		while (b->head->nb != b->min)
			ft_rrb(b, ops);
	}
	ft_pb(a, b, ops);
}

void	insb_inbetw(t_dlst *a, t_dlst *b, int nb, int *ops)
{
	if ((nb > b->head->nb && nb < b->head->next->nb &&
		nb < a->head->next->nb))
	{
		ft_pb(a, b, ops);
		ft_sb(b, ops);
	}
	else if (r_is_faster_inbetw(a, nb))
	{
		while (!(b->head->nb > nb && b->tail->nb < nb))
			ft_rb(a, ops);
	}
	else
	{
		while (!(b->head->nb > nb && b->tail->nb < nb))
			ft_rrb(a, ops);
	}
	ft_pb(a, b, ops);
}

void	final_rotation_b(t_dlst *b, int *ops)
{
	t_dnode	*i;
	int		count;
	int		mid;

	mid = b->size / 2;
	count = 0;
	i = b->head;
	while (count <= mid && i->nb != b->min)
	{
		count++;
		i = i->next;
	}
	if (count <= mid)
	{
		while (b->head->nb != b->min)
			ft_rb(b, ops);
	}
	else
	{
		while (b->head->nb != b->min)
			ft_rrb(b, ops);
	}
	while (b->tail->nb == b->min)
		ft_rrb(b, ops);
}