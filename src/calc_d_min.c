/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc_d_min.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoomen <hoomen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/14 13:47:11 by hoomen            #+#    #+#             */
/*   Updated: 2022/06/14 13:49:15 by hoomen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"push_swap.h"

void	calc_r_dst_min_fw_a(t_dlst *b, int mid, t_p *dst_new)
{
	t_dnode	*i;
	int		r;

	i = b->head;
	r = 0;
	dst_new->rev = 0;
	while (r <= mid)
	{
		if (i->nb == b->min)
			break ;
		i = i->next;
		r++;
	}
	if (r > mid)
		dst_new->r = -1;
	else
		dst_new->r = r;
}

void	calc_r_dst_min_rev_a(t_dlst *b, t_p *dst_new)
{
	t_dnode	*i;
	int		r;

	i = b->tail;
	r = 0;
	dst_new->rev = 1;
	while (i)
	{
		if (i->nb == b->max)
			break ;
		i = i->prev;
		r++;
	}
	dst_new->r = r;
}

void	calc_r_dst_min_a(t_dlst *d, int mid, t_p *dst_new)
{
	calc_r_dst_min_fw_a(d, mid, dst_new);
	if (dst_new->r == -1)
		calc_r_dst_min_rev_a(d, dst_new);
}
