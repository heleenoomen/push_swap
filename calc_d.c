/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc_d.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoomen <hoomen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/14 13:47:17 by hoomen            #+#    #+#             */
/*   Updated: 2022/06/14 13:47:20 by hoomen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"push_swap.h"

void	calc_r_dst_inbtw_fw_a(t_dlst *d, int nb, int mid, t_p *dst_new)
{
	t_dnode	*i;
	int		r;

	i = d->head;
	r = 0;
	dst_new->rev = 0;
	while (r <= mid)
	{
		if (nb < i->nb && nb > i->prev->nb)
			break ;
		i = i->next;
		r++;
	}
	if (r > mid)
		dst_new->r = -1;
	else
		dst_new->r = r;
}

void	calc_r_dst_inbtw_rev_a(t_dlst *d, int nb, t_p *dst_new)
{
	t_dnode	*i;
	int		r;

	i = d->tail;
	r = 1;
	dst_new->rev = 1;
	while (1)
	{
		if (nb < i->nb && nb > i->prev->nb)
			break ;
		i = i->prev;
		r++;
	}
	dst_new->r = r;
}

void	calc_r_dst_inbtw_a(t_dlst *d, int nb, int mid, t_p *dst_new)
{
	calc_r_dst_inbtw_fw_a(d, nb, mid, dst_new);
	if (dst_new->r == -1)
		calc_r_dst_inbtw_rev_a(d, nb, dst_new);
}

void	calc_r_dst(t_dlst *d, int nb, int mid, t_p *dst_new)
{
	if (nb > d->max)
		calc_r_dst_max_a(d, mid, dst_new);
	else if (nb < d->min)
		calc_r_dst_min_a(d, mid, dst_new);
	else
		calc_r_dst_inbtw_a(d, nb, mid, dst_new);
}
