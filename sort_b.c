#include"push_swap.h"

int	det_nrb_max_top(t_dlst *b, int mid, bool *rb)
{
	t_dnode	*i;
	int		nrb;

	i = b->head;
	nrb = 0;
	*rb = 1;
	while (i <= mid)
	{
		if (i->prev->nb == b->max)
			break ;
		i = i->next;
		nrb++;
	}
	if (nrb > mid)
		return (-1);
	return (nrb);
}

int	det_nrb_max_bot(t_dlst *b, int mid, bool *rb)
{
	t_dnode	*i;
	int		nrb;

	i = b->tail->prev;
	nrb = 1;
	*rb = 0;
	while (i)
	{
		if (i->nb == b->max)
			break ;
		i = i->next;
		nrb++;
	}
	return (nrb);
}

int	det_nrb_min_top(t_dlst *b, int mid, bool *rb)
{
	t_dnode	*i;
	int		nrb;

	i = b->head;
	nrb = 0;
	*rb = 1;
	while (i <= mid)
	{
		if (i->nb == b->min)
			break ;
		i = i->next;
		nrb++;
	}
	if (nrb > mid)
		return (-1);
	return (nrb);
}

int	det_nrb_min_bot(t_dlst *b, int mid, bool *rb)
{
	t_dnode	*i;
	int		nrb;

	i = b->tail;
	nrb = 1;
	*rb = 0;
	while (i)
	{
		if (i->nb == b->min)
			break ;
		i = i->next;
		nrb++;
	}
	return (nrb);
}

int	det_nrb_inbtw_top(t_dlst *b, int nb, int mid, bool *rb)
{
	t_dnode	*i;
	int		nrb;

	i = b->head;
	nrb = 0;
	*rb = 1;
	while (i <= mid)
	{
		if (nb < i->nb && nb > i->prev->nb)
			break ;
		i = i->next;
		nrb++;
	}
	if (nrb > mid)
		return (-1);
	return (nrb);
}

int	det_nrb_inbtw_bot(t_dlst *b, int nb, int mid, bool *rb)
{
	t_dnode	*i;
	int		nrb;

	i = b->tail;
	nrb = 1;
	*rb = 0;
	while (i <= mid)
	{
		if (nb < i->nb && nb > i->prev->nb)
			break ;
		i = i->next;
		nrb++;
	}
	return (nrb);
}

int	det_nrb_max(t_dlst *b, int mid, bool *rb)
{
	int	nrb;

	nrb = det_nrb_max_top(b, mid, rb);
	if (nrb == -1)
		return (det_nrb_max_bot(b, mid, rb));
	return (nrb);
}

int	det_nrb_min(t_dlst *b, int mid, bool *rb)
{
	int	rot;

	rot = det_nrb_min_top(b, mid, rb);
	if (rot == -1)
		return (det_nrb_min_bot(b, mid, rb));
	return (rot);
}

int	det_nrb_inbtw(t_dlst *b, int nb, int mid, bool *rb)
{
	int	nrb;

	nrb = det_nrb_inbtw_top(b, mid, rb);
	if (nrb == -1)
		return (det_nrb_inbtw_bot(b, mid, rb));
	return (nrb);
}

int	det_nrb(t_dlst *b, int nb, int mid, bool *rb)
{
	int	nrb;

	if (nb > b->max)
		nrb = det_nrb_max(b, mid, rb);
	else if (nb < b->min)
		nrb = det_nrb_min(b, mid, rb);
	else
		nrb = det_nrb_inbtw(b, nb, mid, rb);
	return (nrb);
}

void	search_a_top(t_dlst *a, t_dlst *b, int mid, t_p *r)
{
	int		nra;
	int		ops_new;
	bool	rb;
	t_dnode *i;

	r->ops = MAX_INT;
	i = a->head;
	nra = 0;
	while (nra <= mid)
	{
		ops_new = nra + det_nrb(b, i->nb, mid, &rb);
		if (ops_new < r->ops)
		{
			r->ops = ops_new;
			r->nb = i->nb;
		}
		nra++;
		i = i->next;
		if (i == a->head)
			break ;
	}
}

void	search_a_bot(t_dlst *a, t_dlst *b, int mid, t_p *r)
{
	int		nra;
	int		ops_new;
	bool	rb;
	t_dnode *i;

	r->ops = MAX_INT;
	i = a->tail;
	nra = 1;
	while (nra <= mid)
	{
		ops_new = nra + det_nrb(b, i->nb, mid, &rb);
		if (ops_new < r->ops)
		{
			r->ops = ops_new;
			r->nb = i->nb;
			r->rb = rb;
		}
		nra++;
		i = i->prev;
		if (i == a->tail)
			break ;
	}
}

void	pick_nb(t_dlst *a, t_dlst *b)
{
	t_p	top;
	t_p	bot;
	int	mid;
	int	ops_top;
	int	nb_top;

	mid = a->size / 2;
	search_a_top(a, b, mid, &top);
	search_a_bot(a, b, mid, &bot);
	if (top.ops < bot.ops)
		ins_b(a, b, mid, &top);
	ins_b(a, b, mid, &bot);
}
