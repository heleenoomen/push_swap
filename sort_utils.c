/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoomen <hoomen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/14 13:48:38 by hoomen            #+#    #+#             */
/*   Updated: 2022/06/14 15:24:35 by hoomen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"push_swap.h"

void	sort_three_b(t_dlst *a)
{
	if (a->head->next->nb < a->head->nb && a->head->nb < a->tail->nb)
		ft_s(a);
	else if (a->head->nb < a->tail->nb && a->tail->nb < a->head->next->nb)
		ft_s(a);
	else if (a->tail->nb < a->head->next->nb && a->head->next->nb < a->head->nb)
		ft_s(a);
}

void	push_second_lastb(t_dlst *a, t_dlst *b)
{
	if (b->head->nb < a->min && a->head->nb == a->min
		&& b->tail->nb < a->head->next->nb && b->head->nb == b->min)
	{
		ft_s(b);
		ft_p(b, a);
		if (!is_sorted(a))
			ft_s(a);
		ft_p(b, a);
	}
	if (a->head->nb < b->tail->nb && a->head->next->nb > b->tail->nb
		&& b->head->nb < b->tail->nb && b->head->nb < a->head->nb &&
			b->tail->nb > a->tail->nb)
	{
		ft_r(b);
		ft_p(b, a);
		ft_s(a);
	}
	else
		push_sort(b, a);
}

void	push_second_last(t_dlst *a, t_dlst *b)
{
	if (a->tail->nb == a->min && b->max < a->head->nb
		&& b->tail->nb > b->head->nb)
	{
		ft_s(b);
		ft_p(b, a);
	}
	else if (a->head->nb == a->max && b->tail->nb == b->max
		&& b->max < a->max && b->max > a->tail->nb)
	{
		ft_s(b);
		ft_p(b, a);
	}
	else if (a->head->nb == a->max && b->tail->nb == b->max
		&& b->max < b->head->nb && b->max > b->tail->nb)
	{
		ft_s(b);
		ft_p(b, a);
	}
	else
		push_second_lastb(a, b);
}

void	push_last(t_dlst *a, t_dlst *b)
{
	if (!b->size)
		return ;
	if (b->head->nb > a->head->nb && b->head->nb < a->head->next->nb)
	{
		ft_p(b, a);
		ft_s(a);
	}
	else if (b->head->nb > a->head->next->nb
		&& b->head->nb < a->head->next->next->nb)
	{
		ft_r(a);
		ft_p(b, a);
		ft_s(a);
	}
	else
		push_sort(b, a);
}

void	final_r(t_dlst *a)
{
	t_dnode	*i;
	int		mid;
	int		r;

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
