#include"push_swap.h"

void	update_org(t_p *org, t_p *dst_new, int nb, int r)
{
	org->ops = r + dst_new->r - dst_new->r_sim;
	org->nb = nb;
	org->r_sim = dst_new->r_sim;
	org->r = r;
}

void	update_dst(t_p *dst, t_p *dst_new)
{
	dst->rev = dst_new->rev;
	dst->r = dst_new->r;
	dst->r_sim = dst_new->r_sim;
}

void	adj_for_simult(t_p *org, t_p *dst_new, int r)
{
	dst_new->r_sim = 0;
	if (dst_new->rev == -1 || org->rev == dst_new->rev)
	{
		if (r >= dst_new->r)
			dst_new->r_sim = dst_new->r;
		else
			dst_new->r_sim = r;
	}
}

void	calc_o_rev(t_dlst *o, t_dlst *d, t_p *org, t_p *dst)
{
	int		mid_o;
	int		mid_d;
	int		r;
	t_dnode *i;
	t_p		dst_new;

	mid_o = o->size / 2;
	mid_d = d->size / 2;
	org->ops = MAX_INT;
	org->rev = 1;
	i = o->tail;
	r = 1;
	while (r <= mid_o)
	{
		calc_r_dst(d, i->nb, mid_d, &dst_new);
		adj_for_simult(org, &dst_new, r);
		if ((r + dst_new.r - dst_new.r_sim) < org->ops)
		{
			update_org(org, &dst_new, i->nb, r);
			update_dst(dst, &dst_new);
		}
		r++;
		i = i->prev;
	}
}

void	calc_o_fw(t_dlst *o, t_dlst *d, t_p *org, t_p *dst)
{
	int		mid_o;
	int		mid_d;
	int		r;
	t_dnode *i;
	t_p		dst_new;

	mid_o = o->size / 2;
	mid_d = d->size / 2;
	org->ops = MAX_INT;
	org->rev = 0;
	i = o->head;
	r = 0;
	while (r <= mid_o)
	{
		calc_r_dst(d, i->nb, mid_d, &dst_new);
		adj_for_simult(org, &dst_new, r);
		if ((r + dst_new.r - dst_new.r_sim) < org->ops)
		{
			update_org(org, &dst_new, i->nb, r);
			update_dst(dst, &dst_new);
		}
		r++;
		i = i->next;
	}
}
