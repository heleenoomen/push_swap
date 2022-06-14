/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ins_dst.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoomen <hoomen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/14 13:47:56 by hoomen            #+#    #+#             */
/*   Updated: 2022/06/14 13:51:32 by hoomen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"push_swap.h"

void	r_org_fw(t_dlst *o, t_dlst *d, t_p *org, t_p *dst)
{
	if (dst->rev == -1 || dst->rev == 0)
	{
		while (dst->r_sim)
		{
			ft_r_sim(o, d);
			dst->r_sim--;
			dst->r--;
			org->r--;
		}
	}
	while (org->r)
	{
		ft_r(o);
		org->r--;
	}
}

void	r_org_rev(t_dlst *o, t_dlst *d, t_p *org, t_p *dst)
{
	if (dst->rev == -1 || dst->rev == 1)
	{
		while (dst->r_sim)
		{
			ft_rr_sim(o, d);
			dst->r--;
			org->r--;
			dst->r_sim--;
		}
	}
	while (org->r)
	{
		ft_rr(o);
		org->r--;
	}
}

void	r_org(t_dlst *o, t_dlst *d, t_p *org, t_p *dst)
{
	if (!org->rev)
		r_org_fw(o, d, org, dst);
	else
		r_org_rev(o, d, org, dst);
}

void	r_dst(t_dlst *d, t_p *dst)
{
	if (!dst->rev)
	{
		while (dst->r)
		{
			ft_r(d);
			dst->r--;
		}
		return ;
	}
	while (dst->r)
	{
		ft_rr(d);
		dst->r--;
	}
}

void	ins_dst(t_dlst *a, t_dlst *b, t_p *org, t_p *dst)
{
	if (org != NULL)
		r_org(a, b, org, dst);
	r_dst(b, dst);
	ft_p(a, b);
}
