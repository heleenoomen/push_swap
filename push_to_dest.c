#include"push_swap.h"

int	calc_r_dest_max_fw(t_dlst *b, int mid, t_p *dest)
{
	t_dnode	*i;
	int		r;

	i = b->head;
	r = 0;
	dest->rev = 0;
	while (r <= mid)
	{
		if (i->prev->nb == b->max)
			break ;
		i = i->next;
		r++;
	}
	if (r > mid)
		return (-1);
	return (r);
}

int	calc_r_dest_max_rev(t_dlst *b, t_p *dest)
{
	t_dnode	*i;
	int		r;

	i = b->tail->prev;
	r = 1;
	dest->rev = 1;
	while (i)
	{
		if (i->nb == b->max)
			break ;
		i = i->next;
		r++;
	}
	return (r);
}

int	calc_r_dest_max(t_dlst *b, int mid, t_p *dest)
{
	int	r;

	r = calc_r_dest_max_fw(b, mid, dest);
	if (r == -1)
		return (calc_r_dest_max_rev(b, dest));
	return (r);
}

int	calc_r_dest_min_fw(t_dlst *b, int mid, t_p *dest)
{
	t_dnode	*i;
	int		r;

	i = b->head;
	r = 0;
	dest->rev = 0;
	while (r <= mid)
	{
		if (i->nb == b->min)
			break ;
		i = i->next;
		r++;
	}
	if (r > mid)
		return (-1);
	return (r);
}

int	calc_r_dest_min_rev(t_dlst *b, t_p *dest)
{
	t_dnode	*i;
	int		r;

	i = b->tail;
	r = 1;
	dest->rev = 1;
	while (i)
	{
		if (i->nb == b->min)
			break ;
		i = i->next;
		r++;
	}
	return (r);
}

int	calc_r_dest_min(t_dlst *b, int mid, t_p *dest)
{
	int	r;

	r = calc_r_dest_min_fw(b, mid, dest);
	if (r == -1)
		return (calc_r_dest_min_rev(b, dest));
	return (r);
}

int	calc_r_dest_inbtw_fw(t_dlst *b, int nb, int mid, t_p *dest)
{
	t_dnode	*i;
	int		r;

	i = b->head;
	r = 0;
	dest->rev = 0;
	while (r <= mid)
	{
		if (nb < i->nb && nb > i->prev->nb)
			break ;
		i = i->next;
		r++;
	}
	if (r > mid)
		return (-1);
	return (r);
}

int	calc_r_dest_inbtw_rev(t_dlst *b, int nb, t_p *dest)
{
	t_dnode	*i;
	int		r;

	i = b->tail;
	r = 1;
	dest->rev = 1;
	while (1)
	{
		if (nb < i->nb && nb > i->prev->nb)
			break ;
		i = i->next;
		r++;
	}
	return (r);
}

int	calc_r_dest_inbtw(t_dlst *b, int nb, int mid, t_p *dest)
{
	int	r;

	r = calc_r_dest_inbtw_fw(b, nb, mid, dest);
	if (r == -1)
		return (calc_r_dest_inbtw_rev(b, nb, dest));
	return (r);
}

int	calc_r_dest(t_dlst *b, int nb, int mid, t_p *dest)
{
	if (b->head == NULL)
	{
		dest->rev = -1;
		return (0);
	}
	if (b->head == b->tail && nb < b->head->nb)
	{
		dest->rev = -1;
		return (0);
	}
	if (b->head == b->tail && nb > b->head->nb)
	{
		dest->rev = -1;
		return (1);
	}
	if (nb > b->max)
		return (calc_r_dest_max(b, mid, dest));
	else if (nb < b->min)
		return (calc_r_dest_min(b, mid, dest));
	else
		return (calc_r_dest_inbtw(b, nb, mid, dest));
}

void	adj_for_simult(t_p *org, t_p *dest, int *ops_new)
{
	if (dest->rev == -1 || org->rev == dest->rev)
	{
		if (org->r >= dest->r)
			*ops_new -= dest->r;
		else
			*ops_new -= org->r;
	}
}

void	calc_origin_rra(t_dlst *a, t_dlst *b, t_p *org, t_p *dest)
{
	int		ops_new;
	int		mid;
	int		r;
	t_dnode *i;

	mid = a->size / 2;
	org->ops = MAX_INT;
	org->rev = 1;
	i = a->tail;
	r = 1;
	while (r <= mid)
	{
		ops_new = r + calc_nrot_dest(b, i->nb, mid, dest);
		adj_for_simult(org, dest, &ops_new);
		if (ops_new < org->ops)
		{
			org->ops = ops_new;
			org->nb = i->nb;
			org->r = r;
		}
		r++;
		i = i->prev;
		if (i == a->tail)
			break ;
	}
}

void	calc_origin_ra(t_dlst *a, t_dlst *b, t_p *org, t_p *dest)
{
	int		mid;
	int		ops_new;
	int		r;
	t_dnode *i;

	mid = a->size / 2;
	org->ops = MAX_INT;
	org->rev = 0;
	i = a->head;
	r = 0;
	while (r <= mid)
	{
		ops_new = r + calc_nrot_dest(b, i->nb, mid, dest);
		adj_for_simult(org, dest, &ops_new);
		if (ops_new < org->ops)
		{
			org->ops = ops_new;
			org->nb = i->nb;
			org->r = r;
		}
		r++;
		i = i->next;
		if (i == a->head)
			break ;
	}
}

void	push_to_dest(t_dlst *a, t_dlst *b)
{
	t_p	org_top;
	t_p	org_bot;
	t_p	dest_top;
	t_p	dest_bot;

	calc_origin_ra(a, b, &org_top, &dest_top);
	calc_origin_rra(a, b, &org_bot, &dest_bot);
	if (org_top.ops < org_bot.ops)
		ins_dest(a, b, &org_top, &dest_top);
	else
		ins_dest(a, b, &org_bot, &dest_bot);
}
