/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_utils1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoomen <hoomen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/14 13:53:54 by hoomen            #+#    #+#             */
/*   Updated: 2022/06/15 15:10:05 by hoomen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"push_swap.h"

bool	check_set_i_sign(const char *arg, int *i, int *sign)
{
	size_t	len;

	len = ft_strlen(arg);
	if (arg[0] == '-')
	{
		*i = 1;
		*sign = -1;
		if (len > 11 || (len == 11 && arg[1] > '2'))
			return (0);
	}
	else
	{
		*i = 0;
		*sign = 1;
		if (len > 10 || (len == 10 && arg[0] > '2'))
			return (0);
	}
	return (1);
}

bool	isint(const char *arg)
{
	int			i;
	size_t		nb;
	int			sign;

	if (!check_set_i_sign(arg, &i, &sign))
		return (0);
	nb = 0;
	while (arg[i])
	{
		nb = nb * 10 + ((arg[i]) - '0');
		i++;
	}
	if (nb > MAX_INT && sign == 1)
		return (0);
	if (nb > (MAX_INT + 1))
		return (0);
	return (1);
}

void	parse_argv(int *argc, char ***argv)
{
	*argv = ft_split_shift((*argv)[1], ' ');
	if (*argv == NULL)
	{
		ft_putstr_fd("Error\n", STDERR_FILENO);
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
		if (!ft_strisnumeric(argv[i]) || !isint(argv[i]))
		{
			ft_putstr_fd("Error\n", STDERR_FILENO);
			dlst_clear(a);
			exit(0);
		}
		dlst_addnew(a, ft_atoi(argv[i]));
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
	if (argc == 2)
	{
		dlst_clear(a);
		exit(0);
	}
}
