#include"push_swap.h"

int	det_nrb_max_top(t_dlst *b, int mid, bool *rb)
{
	t_dnode	*i;
	int		nrb;

	i = b->head;
	nrb = 0;
	*rb = 1;
	while (nrb <= mid)
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

int	det_nrb_max_bot(t_dlst *b, bool *rb)
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
	while (nrb <= mid)
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

int	det_nrb_min_bot(t_dlst *b, bool *rb)
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
	while (nrb <= mid)
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

int	det_nrb_inbtw_bot(t_dlst *b, int nb, bool *rb)
{
	t_dnode	*i;
	int		nrb;

	i = b->tail;
	nrb = 1;
	*rb = 0;
	while (1)
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
		return (det_nrb_max_bot(b, rb));
	return (nrb);
}

int	det_nrb_min(t_dlst *b, int mid, bool *rb)
{
	int	rot;

	rot = det_nrb_min_top(b, mid, rb);
	if (rot == -1)
		return (det_nrb_min_bot(b, rb));
	return (rot);
}

int	det_nrb_inbtw(t_dlst *b, int nb, int mid, bool *rb)
{
	int	nrb;

	nrb = det_nrb_inbtw_top(b, nb, mid, rb);
	if (nrb == -1)
		return (det_nrb_inbtw_bot(b, nb, rb));
	return (nrb);
}

int	det_nrb(t_dlst *b, int nb, int mid, bool *rb) // = calc ops_b
{
	int	nrb;

	if (b->head == NULL)
		return (0);
	if (b->head == b->tail && nb < b->head->nb)
		return (1);
	if (b->head == b->tail && nb > b->head->nb)
		return (2);
	if (nb > b->max)
		nrb = det_nrb_max(b, mid, rb);
	else if (nb < b->min)
		nrb = det_nrb_min(b, mid, rb);
	else
		nrb = det_nrb_inbtw(b, nb, mid, rb);
	return (nrb);
}

void	pick_nb_a_top(t_dlst *a, t_dlst *b, int mid, t_p *r) // = calc_a_ra
{
	int		nra;
	int		ops_new;
	bool	rb;
	t_dnode *i;

	r->ops = MAX_INT;
	r->ra = 1;
	i = a->head;
	nra = 0;
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
		i = i->next;
		if (i == a->head)
			break ;
	}
}

void	pick_nb_a_bot(t_dlst *a, t_dlst *b, int mid, t_p *r) // = calc_a_rra
{
	int		nra;
	int		ops_new;
	bool	rb;
	t_dnode *i;

	r->ops = MAX_INT;
	r->ra = 0;
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
