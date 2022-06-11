#include"push_swap.h"

static void	pushb_sort_top(t_dlst *a, t_p *parms, int lim)//, int count)
{
	t_dnode	*i;
	int		mid;
	int		steps;
	int		new_ops;

	i = a->head;
	mid = a->size / 2;
	parms->ops = MAX_INT;
	steps = 0;
	while (steps <= mid)
	{
		if (i->nb < lim)
		{
			new_ops = steps + ((i->nb - a->min));// * (PORTION - count));
			if (new_ops < parms->ops)
			{
				parms->ops = new_ops;
				parms->nb = i->nb;
			}
		}
		i = i->next;
		steps++;
	}
}

static void	pushb_sort_bottom(t_dlst *a, t_p *parms, int lim)//, int count)
{
	t_dnode	*i;
	int		mid;
	int		steps;
	int		new_ops;

	i = a->tail;
	mid = a->size / 2;
	parms->ops = MAX_INT;
	steps = 1;
	while (steps <= mid)
	{
		if (i->nb < lim)
		{
			new_ops = steps + ((i->nb - a->min));// * (PORTION - count));
			if (new_ops < parms->ops)
			{
				parms->ops = new_ops;
				parms->nb = i->nb;
			}
		}
		i = i->prev;
		steps++;
	}
}

static bool	r_faster(t_dlst *a, int lim, int *nb)//, int count)
{
	t_p	top;
	t_p bottom;

	pushb_sort_top(a, &top, lim);//, count);
	pushb_sort_bottom(a, &bottom, lim);//, count);
	if (top.ops <= bottom.ops)
		*nb = top.nb;
	else
		*nb = bottom.nb;
	return (top.ops <= bottom.ops);
}

static void	r_nb_to_top(t_dlst *a, int nb, int *ops)
{
	while (a->head->nb != nb)
		ft_ra(a, ops);
}

static void	rr_nb_to_top(t_dlst *a, int nb, int *ops)
{
	while (a->head->nb != nb)
		ft_rra(a, ops);
}

void	pb_portion_sort(t_dlst *a, t_dlst *b, int lim, int *ops)
{
	int		count;
	int		nb;

	count = 0;
	while (count < PORTION)
	{
		if (r_faster(a, lim, &nb))//, count))
			r_nb_to_top(a, nb, ops);
		else
			rr_nb_to_top(a, nb, ops);
		ft_pb(a, b, ops);
		count++;
	}
}