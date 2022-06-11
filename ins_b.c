#include "push_swap.h"

void	ins_b_max(t_dlst *b, t_p *r)
{
	// ft_printf("--------------------\n");
	// ft_printf("nb = %i\n", r->nb);
	// ft_printf("ops = %i\n", r->ops);
	// ft_printf("ra = %i\n", r->ra);
	// ft_printf("rb = %i\n", r->rb);
	// return ;
	if (r->rb)
	{
		while (b->tail->nb != b->max)
			ft_rb(b);
			return ;
	}
	while (b->tail->nb != b->max)
			ft_rrb(b);
}

void	ins_b_min(t_dlst *b, t_p *r)
{
	ft_printf("--------------------\n");
	ft_printf("in ins_b_min:\n");
	ft_printf("nb = %i\n", r->nb);
	ft_printf("ops = %i\n", r->ops);
	ft_printf("ra = %i\n", r->ra);
	ft_printf("rb = %i\n", r->rb);
	return ;
	if (r->rb)
	{
		while (b->head->nb != b->min)
			ft_rb(b);
		return ;
	}
	while (b->head->nb != b->min)
			ft_rrb(b);
}

void	ins_b_inbtw(t_dlst *b, t_p *r)
{
	ft_printf("--------------------\n");
	ft_printf("nb = %i\n", r->nb);
	ft_printf("ops = %i\n", r->ops);
	ft_printf("ra = %i\n", r->ra);
	ft_printf("rb = %i\n", r->rb);
	return ;
	if (r->rb)
	{
		while (!(r->nb < b->head->nb && r->nb > b->tail->nb))
			ft_rb(b);
		return ;
	}
	while (!(r->nb < b->head->nb && r->nb > b->tail->nb))
		ft_rrb(b);
}

void	ins_first_second(t_dlst *a, t_dlst *b, t_p *r)
{
	if (b->head == NULL)
		ft_pb(a, b);
	else if (b->head == b->tail && r->nb < b->head->nb)
		ft_pb(a, b);
	else if (b->head == b->tail)
	{
		ft_pb(a, b);
		ft_rb(b);
	}
}

void	rotate_a(t_dlst *a, t_p *r)
{
	if (a->head == a->tail)
		return ;
	if (r->ra)
	{
		while (a->head->nb != r->nb)
			ft_ra(a);
		return ;
	}
	while (a->head->nb != r->nb)
		ft_rra(a);
}

void	ins_b(t_dlst *a, t_dlst *b, t_p *r)
{
	rotate_a(a, r);
	if (b->head == NULL || b->head == b->tail)
	{
		ins_first_second(a, b, r);
		return ;
	}
	ft_printf("r->nb = %i, b->min = %i\n", r->nb, b->min);
	if (r->nb > b->max)
		ins_b_max(a, b, r);
	else if (r->nb < b->min)
		ins_b_min(a, b, r);
	else
		ins_b_inbtw(a, b, r);
	ft_pb(a, b);
}
