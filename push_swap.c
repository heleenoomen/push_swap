/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoomen <hoomen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/14 13:48:25 by hoomen            #+#    #+#             */
/*   Updated: 2022/06/14 13:55:03 by hoomen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"push_swap.h"

void	parse_argv(int *argc, char ***argv)
{
	*argv = ft_split_shift((*argv)[1], ' ');
	if (*argv == NULL)
	{
		ft_printf("Error\n");
		exit(0);
	}
	*argc = 1;
	while ((*argv)[*argc] != NULL)
		(*argc)++;
}

void	make_dllst(char **argv, t_dlst *a)
{
	int	i;

	i = 1;
	dlst_init(a, 'a');
	while (argv[i] != NULL)
	{
		if (!ft_strisnumeric(argv[i]))
		{
			ft_printf("Error\n");
			dlst_clear(a);
			exit(0);
		}
		dlst_addnew(argv[i], a);
		a->tail->id = i - 1;
		i++;
	}
}

void	make_stack_a(int argc, char **argv, t_dlst *a)
{
	int	is_single;

	if (argc == 2)
	{
		parse_argv(&argc, &argv);
		is_single = 1;
	}
	else
		is_single = 0;
	make_dllst(argv, a);
	if (is_single)
		ft_free_argv_ps(argv);
}

void	check(void)
{
	system("leaks push_swap");
}

int	main(int argc, char **argv)
{
	t_dlst	a;

	//atexit(check);
	if (argc == 1)
		return (0);
	make_stack_a(argc, argv, &a);
	check_dupl(&a);
	sort(&a);
	dlst_clear(&a);
	return (0);
}
