/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoomen <hoomen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/14 18:07:41 by hoomen            #+#    #+#             */
/*   Updated: 2022/06/14 18:43:05 by hoomen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"push_swap.h"

void	exit_checker(t_dlst *a, t_dlst *b, char *line)
{
	free(line);
	dlst_clear(a);
	dlst_clear(b);
	ft_printf("Error\n");
	exit(0);
}

void	checker(t_dlst *a, t_dlst *b, char *line)
{
	if (!ft_strncmp(line, "sa\n", 4))
		ft_s(a);
	else if (!ft_strncmp(line, "sb\n", 4))
		ft_s(b);
	else if (!ft_strncmp(line, "ra\n", 4))
		ft_r(a);
	else if (!ft_strncmp(line, "rb\n", 4))
		ft_r(b);
	else if (!ft_strncmp(line, "rra\n", 5))
		ft_rr(a);
	else if (!ft_strncmp(line, "rrb\n", 5))
		ft_rr(b);
	else if (!ft_strncmp(line, "rr\n", 4))
		ft_r_sim(a, b);
	else if (!ft_strncmp(line, "rrr\n", 5))
		ft_rr_sim(a, b);
	else
		exit_checker(a, b, line);
}

int	main(int argc, char **argv)
{
	t_dlst	a;
	t_dlst	b;
	char	*line;

	if (argc == 1)
		return (0);
	make_stack_a(argc, argv, &a);
	dlst_init(&b, 'b');
	a.name = 'c';
	b.name = 'c';
	line = get_next_line(0);
	while (line != NULL)
	{
		checker(&a, &b, line);
		free(line);
		line = get_next_line(0);
	}
	if (is_sorted(&a) && b.head == NULL)
		ft_printf("OK\n");
	else
		ft_printf("KO\n");
	dlst_clear(&a);
	dlst_clear(&b);
}