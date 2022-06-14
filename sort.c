#include"push_swap.h"

void	sort_two(t_dlst *a)
{
		ft_s(a);
		exit(0);
}

void	sort_three(t_dlst *a)
{
	if (a->head->next->nb < a->head->nb && a->head->nb < a->tail->nb)
		ft_s(a);
	else if (a->tail->nb < a->head->nb && a->head->nb < a->head->next->nb)
		ft_rr(a);
	else if (a->head->next->nb < a->tail->nb && a->tail->nb < a->head->nb)
		ft_r(a);
	else if (a->head->nb < a->tail->nb && a->tail->nb < a->head->next->nb)
	{
		ft_s(a);
		ft_r(a);
	}
	else if (a->tail->nb < a->head->next->nb && a->head->next->nb < a->head->nb)
	{
		ft_s(a);
		ft_rr(a);
	}
	dlst_clear(a);
	exit (0);
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
	if (a->size == 2)
		sort_two(a);
	if (a->size == 3)
		sort_three(a);
	dlst_init(&b, 'b');
	while (a->size > 3)
		ft_p(a, &b);
	sort_three_b(a);
	while (b.size > 2)
		push_sort(&b, a);
	push_second_last(a, &b);
	push_last(a, &b);
	final_r(a);
}
