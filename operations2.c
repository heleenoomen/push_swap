/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoomen <hoomen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/14 13:48:09 by hoomen            #+#    #+#             */
/*   Updated: 2022/06/14 18:41:57 by hoomen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"push_swap.h"

void	ft_r(t_dlst *stack)
{
	ft_rotate(stack);
	if (stack->name == 'c')
		return ;
	ft_printf("r%c\n", stack->name);
}

void	ft_rr(t_dlst *stack)
{
	ft_rotate_rev(stack);
	if (stack->name == 'c')
		return ;
	ft_printf("rr%c\n", stack->name);
}

void	ft_p(t_dlst *org, t_dlst *dest)
{
	ft_push(org, dest);
	if (org->name == 'c')
		return ;
	ft_printf("p%c\n", dest->name);
}

void	ft_r_sim(t_dlst *a, t_dlst *b)
{
	ft_rotate(a);
	ft_rotate(b);
	if (a->name == 'c')
		return ;
	ft_printf("rr\n");
}

void	ft_rr_sim(t_dlst *a, t_dlst *b)
{
	ft_rotate_rev(a);
	ft_rotate_rev(b);
	if (a->name == 'c')
		return ;
	ft_printf("rrr\n");
}
