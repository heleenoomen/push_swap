/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoomen <hoomen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/14 13:48:25 by hoomen            #+#    #+#             */
/*   Updated: 2022/06/15 16:38:36 by hoomen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"push_swap.h"

int	main(int argc, char **argv)
{
	t_dlst	a;
	t_dlst	sor;

	if (argc == 1)
		return (0);
	make_stack_a(argc, argv, &a);
	check_dupl(&a, &sor);
	sort(&a, &sor);
	dlst_clear(&a);
	return (0);
}
