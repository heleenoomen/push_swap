/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_dupl.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoomen <hoomen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/14 13:47:32 by hoomen            #+#    #+#             */
/*   Updated: 2022/06/15 18:11:51 by hoomen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"push_swap.h"

void	swap_int(int *i, int *j)
{
	int	temp;

	temp = *i;
	*i = *j;
	*j = temp;
}

void	repeat(t_dlst *stack, t_dnode *i, t_dnode *head, t_dnode *tail)
{
	if (i != head)
		quickso_dlst(stack, head, i->prev);
	if (i != tail)
		quickso_dlst(stack, i->next, tail);
}

void	quickso_dlst(t_dlst *stack, t_dnode *head, t_dnode *tail)
{
	int		v;
	int		temp;
	t_dnode	*i;
	t_dnode	*j;

	if (tail->id <= head->id)
		return ;
	i = head;
	j = tail;
	v = tail->nb;
	while (1)
	{
		while (i->nb < v && i != tail)
			i = i->next;
		while (j->nb >= v && j != head)
			j = j->prev;
		if (i->id >= j->id)
			break ;
		swap_int(&(i->nb), &(j->nb));
	}
	temp = i->nb;
	i->nb = v;
	tail->nb = temp;
	repeat(stack, i, head, tail);
}

void	make_sor(t_dlst *a, t_dlst *sor)
{
	dlst_dup(a, sor);
	quickso_dlst(sor, sor->head, sor->tail);
}

void	check_dupl(t_dlst *a, t_dlst *sor)
{
	t_dnode	*i;

	make_sor(a, sor);
	i = sor->head;
	while (1)
	{
		if (i->nb == i->next->nb)
		{
			dlst_clear(sor);
			dlst_clear(a);
			ft_putstr_fd("Error\n", STDERR_FILENO);
			exit(0);
		}
		i = i->next;
		if (i == sor->head)
			break ;
	}
	if (a->size < 250)
		dlst_clear(sor);
}
