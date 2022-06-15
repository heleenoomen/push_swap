/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoomen <hoomen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/14 13:48:17 by hoomen            #+#    #+#             */
/*   Updated: 2022/06/14 13:48:21 by hoomen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"push_swap.h"

void	init_dst(t_p *dst_top, t_p *dst_bot)
{
	dst_top->ops = 0;
	dst_top->nb = 0;
	dst_bot->ops = 0;
	dst_bot->nb = 0;
}

void	push_sort(t_dlst *o, t_dlst *d)
{
	t_p	org_top;
	t_p	org_bot;
	t_p	dst_top;
	t_p	dst_bot;

	init_dst(&dst_top, &dst_bot);
	calc_o_fw(o, d, &org_top, &dst_top);
	calc_o_rev(o, d, &org_bot, &dst_bot);
	if (o->size == 2)
	{
		if (org_bot.ops <= (org_top.ops + 1) && org_bot.r_sim
			&& o->head->nb < o->tail->nb)
			ins_dst(o, d, &org_bot, &dst_bot);
		else
			ins_dst(o, d, &org_top, &dst_top);
	}	
	else if (org_top.ops <= org_bot.ops)
		ins_dst(o, d, &org_top, &dst_top);
	else
		ins_dst(o, d, &org_bot, &dst_bot);
}
