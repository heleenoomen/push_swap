/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_portion.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoomen <hoomen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/15 12:56:02 by hoomen            #+#    #+#             */
/*   Updated: 2022/06/15 13:37:50 by hoomen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"push_swap.h"

void	get_key(t_dlst *a, t_dlst *sor, int *key)
{
	t_dnode	*i;
	int		mid;
	int		c;

	mid = a->size / 2;
	i = sor->head;
	c = 0;
	while (c < mid)
	{
		i = i->next;
		c++;
	}
	*key = i->nb;
}

bool	bigger_first(t_dlst *a, int key)
{
	int		count;
	int		mid;
	t_dnode	*i;
	int		j;

	mid = a->size / 2;
	count = 0;
	j = 0;
	i = a->head;
	while (j <= mid)
	{
		if (i->nb >= key)
			count++;
		i = i->next;
		j++;
	}
	return (count > (mid / 2));
}

bool	fw_faster_bg(t_dlst *a, int key)
{
	t_dnode *i;
	int		top;
	int		bot;

	i = a->head;
	top = 0;
	bot = 1;
	while (i->nb < key)
	{
		i = i->next;
		top++;
		if (i == a->head)
			break ;
	}
	i = a->tail;
	while (i->nb < key)
	{
		i = i->prev;
		bot++;
		if (i == a->tail)
			break ;
	}
	return (top <= bot);
}

bool	fw_faster_sm(t_dlst *a, int key)
{
	t_dnode *i;
	int		top;
	int		bot;

	i = a->head;
	top = 0;
	bot = 1;
	while (i->nb > key)
	{
		i = i->next;
		top++;
		if (i == a->head)
			break ;
	}
	i = a->tail;
	while (i->nb > key)
	{
		i = i->prev;
		bot++;
		if (i == a->tail)
			break ;
	}
	return (top <= bot);
}

void	push_bigger(t_dlst *a, t_dlst *b, int key)
{
	int	mid;

	mid = a->size / 2;
	while (a->size > mid)
	{
		if (a->head->nb >= key)
			ft_p(a, b);
		else if (fw_faster_bg(a, key))
			ft_r(a);
		else
			ft_rr(a);
	}
}

void	push_smaller(t_dlst *a, t_dlst *b, int key)
{
	int	mid;

	mid = a->size / 2;
	while (a->size > mid)
	{
		if (a->head->nb <= key)
			ft_p(a, b);
		else if (fw_faster_sm(a, key))
			ft_r(a);
		else
			ft_rr(a);
	}
}

void	push_half(t_dlst *a, t_dlst *b, t_dlst *sor)
{
	int	key;

	if (a->size < 250)
		return ;
	get_key(a, sor, &key);
	if (bigger_first(a, key))
		push_bigger(a, b, key);
	else
		push_smaller(a, b, key);
	dlst_clear(sor);
}