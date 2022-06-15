/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoomen <hoomen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/14 13:48:45 by hoomen            #+#    #+#             */
/*   Updated: 2022/06/15 16:39:12 by hoomen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

bool	r_or_rr(t_dlst *a, int key)
{
	t_dnode	*i;
	int		top;
	int		bot;

	i = a->head;
	top = 0;
	while (i->nb > key)
	{
		i = i->next;
		top++;
		if (i == a->head)
			break ;
	}
	i = a->tail;
	bot = 1;
	while (i->nb > key)
	{
		i = i->prev;
		top++;
		if (i == a->tail)
			break ;
	}
	return (top <= bot);
}

void	sort(t_dlst *a, t_dlst *sor)
{
	t_dlst	b;

	if (is_sorted(a))
		exit (0);
	if (a->size == 2)
		sort_two(a);
	if (a->size == 3)
		sort_three(a);
	dlst_init(&b, 'b');
	push_half(a, &b, sor);
	while (a->size > 3)
		ft_p(a, &b);
	sort_three_b(a, &b);
	while (b.size > 2)
		push_sort(&b, a);
	push_second_last(a, &b);
	push_last(a, &b);
	final_r(a);
}
