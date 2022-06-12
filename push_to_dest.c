#include"push_swap.h"

void	calc_r_dest_max_fw(t_dlst *b, int mid, t_p *dest_new)
{
	t_dnode	*i;
	int		r;

	i = b->head;
	r = 0;
	dest_new->rev = 0;
	while (r <= mid)
	{
		if (i->prev->nb == b->max)
			break ;
		i = i->next;
		r++;
	}
	if (r > mid)
		dest_new->r = -1;
	else
		dest_new->r = r;
}

void	calc_r_dest_max_rev(t_dlst *b, t_p *dest_new)
{
	t_dnode	*i;
	int		r;

	i = b->tail->prev;
	r = 1;
	dest_new->rev = 1;
	while (i)
	{
		if (i->nb == b->max)
			break ;
		i = i->next;
		r++;
	}
	dest_new->r = r;
}

void	calc_r_dest_max(t_dlst *b, int mid, t_p *dest_new)
{
	calc_r_dest_max_fw(b, mid, dest_new);
	if (dest_new->r == -1)
		calc_r_dest_max_rev(b, dest_new);
}

void	calc_r_dest_min_fw(t_dlst *b, int mid, t_p *dest_new)
{
	t_dnode	*i;
	int		r;

	i = b->head;
	r = 0;
	dest_new->rev = 0;
	while (r <= mid)
	{
		if (i->nb == b->max)
			break ;
		i = i->next;
		r++;
	}
	if (r > mid)
		dest_new->r = -1;
	else
		dest_new->r = r;
}

void	calc_r_dest_min_rev(t_dlst *b, t_p *dest_new)
{
	t_dnode	*i;
	int		r;

	i = b->tail;
	r = 1;
	dest_new->rev = 1;
	while (i)
	{
		if (i->nb == b->max)
			break ;
		i = i->prev;
		r++;
	}
	dest_new->r = r;
}

void	calc_r_dest_min(t_dlst *b, int mid, t_p *dest_new)
{
	calc_r_dest_min_fw(b, mid, dest_new);
	if (dest_new->r == -1)
		calc_r_dest_min_rev(b, dest_new);
}

void	calc_r_dest_inbtw_fw(t_dlst *b, int nb, int mid, t_p *dest_new)
{
	t_dnode	*i;
	int		r;

	i = b->head;
	r = 0;
	dest_new->rev = 0;
	// ft_printf("103\n");
	// ft_printf("nb = %i\n", nb);
	// ft_printf("i->nb = %i\n", i->nb);
	// ft_printf("i->rev->nb = %i\n", i->prev->nb);
	// ft_printf("mid = %i\n", mid);
	// ft_printf("b->size = %i\n", b->size);
	// ft_printf("mid = %i\n", mid);
	while (r <= mid)
	{
		if (nb > i->nb && nb < i->prev->nb)
			break ;
		i = i->next;
		r++;
	}
	//ft_printf("r = %i\n", r);
	if (r > mid)
		dest_new->r = -1;
	else
		dest_new->r = r;
}

void	calc_r_dest_inbtw_rev(t_dlst *b, int nb, t_p *dest_new)
{
	t_dnode	*i;
	int		r;

	i = b->tail;
	r = 1;
	dest_new->rev = 1;
	while (1)
	{
		if (nb > i->nb && nb < i->prev->nb)
			break ;
		i = i->prev;
		r++;
	}
	dest_new->r = r;
}

void	calc_r_dest_inbtw(t_dlst *b, int nb, int mid, t_p *dest_new)
{
	calc_r_dest_inbtw_fw(b, nb, mid, dest_new);
	if (dest_new->r == -1)
		calc_r_dest_inbtw_rev(b, nb, dest_new);
}

void	calc_r_dest(t_dlst *b, int nb, int mid, t_p *dest)
{
	if (nb > b->max)
		calc_r_dest_min(b, mid, dest);
	else if (nb < b->min)
		calc_r_dest_min(b, mid, dest);
	else
		calc_r_dest_inbtw(b, nb, mid, dest);
}

void	update_org(t_p *org, t_p *dest_new, int nb, int r)
{
	org->ops = r + dest_new->r - dest_new->r_sim;
	org->nb = nb;
	org->r_sim = dest_new->r_sim;
	org->r = r;
}

void	update_dest(t_p *dest, t_p *dest_new)
{
	dest->rev = dest_new->rev;
	dest->r = dest_new->r;
	dest->r_sim = dest_new->r_sim;
}

void	adj_for_simult(t_p *org, t_p *dest_new, int r)
{
	dest_new->r_sim = 0;
	if (dest_new->rev == -1 || org->rev == dest_new->rev)
	{
		if (r >= dest_new->r)
			dest_new->r_sim = dest_new->r;
		else
			dest_new->r_sim = r;
	}
}

void	calc_origin_rra(t_dlst *a, t_dlst *b, t_p *org, t_p *dest)
{
	int		mid_a;
	int		mid_b;
	int		r;
	t_dnode *i;
	t_p		dest_new;

	mid_a = a->size / 2;
	mid_b = b->size / 2;
	org->ops = MAX_INT;
	org->rev = 1;
	i = a->tail;
	r = 1;
	while (r <= mid_a)
	{
		calc_r_dest(b, i->nb, mid_b, &dest_new);
		adj_for_simult(org, &dest_new, r);
		if ((r + dest_new.r - dest_new.r_sim) < org->ops)
		{
			update_org(org, &dest_new, i->nb, r);
			update_dest(dest, &dest_new);
		}
		r++;
		i = i->prev;
		if (i == a->tail)
			break ;
	}
}

void	calc_origin_ra(t_dlst *a, t_dlst *b, t_p *org, t_p *dest)
{
	int		mid_a;
	int		mid_b;
	int		r;
	t_dnode *i;
	t_p		dest_new;

	mid_a = a->size / 2;
	mid_b = b->size / 2;
	org->ops = MAX_INT;
	org->rev = 0;
	i = a->head;
	r = 0;
	while (r <= mid_a)
	{
		calc_r_dest(b, i->nb, mid_b, &dest_new);
		adj_for_simult(org, &dest_new, r);
		if ((r + dest_new.r - dest_new.r_sim) < org->ops)
		{
			update_org(org, &dest_new, i->nb, r);
			update_dest(dest, &dest_new);
		}
		r++;
		i = i->next;
		if (i == a->head)
			break ;
	}
}

void	init_dest(t_p *dest_top, t_p *dest_bot)
{
	dest_top->ops = 0;
	dest_top->nb = 0;
	dest_bot->ops = 0;
	dest_bot->nb = 0;
}

void	push_to_dest(t_dlst *a, t_dlst *b)
{
	t_p	org_top;
	t_p	org_bot;
	t_p	dest_top;
	t_p	dest_bot;

	init_dest(&dest_top, &dest_bot);
	calc_origin_ra(a, b, &org_top, &dest_top);
	calc_origin_rra(a, b, &org_bot, &dest_bot);
	if (org_top.ops < org_bot.ops)
		ins_dest(a, b, &org_top, &dest_top);
	else
		ins_dest(a, b, &org_bot, &dest_bot);
}

void	push_last_q(t_dlst *a, t_dlst *b)
{
	t_p	dest;
	// t_p	org;

	// org.r = 0;
	// org.r_sim = 0;
	// org.rev = 0;
	//ft_printf("in push_last_q\n");
	dest.r_sim = 0;
	calc_r_dest(b, a->head->nb, b->size / 2, &dest);
	//print_p(&dest, "dest");
	ins_dest(a, b, NULL, &dest);
	//ft_p(a, b);
}