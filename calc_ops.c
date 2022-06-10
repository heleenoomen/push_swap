#include"push_swap.h"

int	pb_calc_sortb_max_top(t_dlst *b, int mid)
{
	int		top;
	t_dnode	*i;

	top = 0;
	i = b->head;
	while (top <= mid)
	{
		if (i->prev->nb == b->max)
			break ;
		i = i->next;
		top++;
	}
	return (top);
}

int	pb_calc_sortb_max_bot(t_dlst *b, int mid)
{
	int		bottom;
	t_dnode	*i;
	
	bottom = 1;
	i = b->tail;
	while (bottom <= (mid + 1))
	{
		if (i->nb == b->max)
			break ;
		i = i->prev;
		bottom++;
	}
	return (bottom);
}

int	pb_calc_sortb_max(t_dlst *b)
{
	int		top;
	int		bottom;
	int		mid;

	mid = b->size / 2;
	top = pb_calc_sortb_max_top(b, mid);
	bottom = pb_calc_sortb_max_bot(b, mid);
	if (top < bottom)
		return (top);
	return (bottom);
}

int	pb_calc_sortb_min_top(t_dlst *b, int mid)
{
	int		top;
	t_dnode	*i;

	top = 0;
	i = b->head;
	while (top <= mid)
	{
		if (i->nb == b->min)
			break ;
		i = i->next;
		top++;
	}
	return (top);
}

int	pb_calc_sortb_min_bot(t_dlst *b, int mid)
{
	int		bottom;
	t_dnode	*i;

	bottom = 1;
	i = b->tail;
	while (bottom <= (mid + 1))
	{
		if (i->nb == b->min)
			break;
		i = i->prev;
		bottom++;
	}
	return (bottom);
}

int	pb_calc_sortb_min(t_dlst *b)
{
	int		top;
	int		bottom;
	int		mid;

	mid = b->size / 2;
	top = pb_calc_sortb_min_top(b, mid);
	bottom = pb_calc_sortb_min_bot(b, mid);
	if (top < bottom)
		return (top);
	return (bottom);
}

int	pb_calc_sortb_inb_top(t_dlst *b, int nb, int mid)
{
	int		top;
	t_dnode *i;

	top = 0;
	i = b->head;
	while (top <= mid)
	{
		if (nb < i->nb && nb > i->prev->nb)
			break ;
		i = i->next;
		top++;
	}
	return (top);
}

int	pb_calc_sortb_inb_bot(t_dlst *b, int nb, int mid)
{
	int		bottom;
	t_dnode *i;

	bottom = 1;
	i = b->head;
	while (bottom <= (mid + 1))
	{
		if (nb < i->nb && nb > i->prev->nb)
			break ;
		i = i->prev;
		bottom--;
	}
	return (bottom);
}

int	pb_calc_sortb_inbetw(t_dlst *b, int nb)
{
	int	top;
	int	bottom;
	int	mid;

	mid = b->size / 2;
	top = pb_calc_sortb_inb_top(b, nb, mid);
	bottom = pb_calc_sortb_inb_bot(b, nb, mid);
	if (top < bottom)
		return (top);
	return (bottom);
}

int	pb_calc_sortb(t_dlst *b, int nb)
{
	if (b->head == NULL)
		return (0);
	if (nb > b->max)
		return (pb_calc_sortb_max(b));
	else if (nb < b->min)
		return (pb_calc_sortb_min(b));
	else
		return (pb_calc_sortb_inbetw(b, nb));
}

void	pb_calc_from_top(t_dlst *a, t_dlst *b, int lim, t_p *parms)
{
	int		mid;
	t_dnode	*i;
	int		steps;
	int		ops;

	mid = a->size / 2;
	parms->ops = MAX_INT;
	i = a->head;
	steps = 0;
	while (steps <= mid)
	{
		if (i->nb < lim)
		{
			ops = steps + pb_calc_sortb(b, i->nb);
			return ;
			if (ops < parms->ops)
			{
				parms->ops = ops;
				parms->nb = i->nb;
			}
		}
		steps++;
		i = i->next;
	}
}

void	pb_calc_from_bottom(t_dlst *a, t_dlst *b, int lim, t_p *parms)
{
	int		mid;
	t_dnode	*i;
	int		steps;
	int		ops;

	mid = a->size / 2;
	i = a->tail;
	steps = 1;
	ops = 1;
	while (steps <= (mid + 1))
	{
		if (i->nb < lim)
		{
			ops = steps + pb_calc_sortb(b, i->nb);
			if (ops < parms->ops)
			{
				parms->ops = ops;
				parms->nb = i->nb;
			}
		}
		steps++;
		i = i->prev;
	}
}

void	pb_calc_ops(t_dlst *a, t_dlst *b, int lim, t_p *parms)
{
	pb_calc_from_top(a, b, lim, parms);
	pb_calc_from_bottom(a, b, lim, parms);
}