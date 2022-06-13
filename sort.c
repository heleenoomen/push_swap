#include"push_swap.h"

void	push_to_org(t_dlst *a, t_dlst *b)
{
	t_dnode *i;
	int		mid;
	int		r;

	while (b->size)
		ft_p(b, a);
	i = a->head;
	mid = a->size / 2;
	r = 0;
	while (1)
	{
		if (i->nb == a->min)
			break ;
		r++;
		i = i->next;
	}
	if (r <= mid)
	{
		while (a->head->nb != a->min)
			ft_r(a);
		return ;
	}
	while (a->head->nb != a->min)
		ft_rr(a);
}

void	sort_big(t_dlst *a, t_dlst *b)
{
	ft_p(a, b);
	ft_p(a, b);
	if (b->head->nb < b->tail->nb)
		ft_s(b);
	while (a->size)
		push_to_dest(a, b);
	push_to_org(a, b);
}

bool	is_sorted(t_dlst *a)
{
	t_dnode	*i;

	i = a->head;
	while (1)
	{
		if (i->nb > i->next->nb)
			return (0);
		if (i->nb < i->next->nb)
			i = i->next;
		if (i == a->tail)
			return (1);
	}
}

void	sort(t_dlst *a)
{
	t_dlst	b;

	if (is_sorted(a))
		exit (0);
	dlst_init(&b, 'b');
	if (a->size < 501)
		sort_small(a, &b);
	else
		sort_big(a, &b);
	dlst_clear(&b);
}
