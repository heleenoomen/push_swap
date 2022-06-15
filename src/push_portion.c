/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_portion.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoomen <hoomen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/15 12:56:02 by hoomen            #+#    #+#             */
/*   Updated: 2022/06/15 14:01:28 by hoomen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"push_swap.h"

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
