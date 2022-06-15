/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_utils2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoomen <hoomen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/14 16:37:47 by hoomen            #+#    #+#             */
/*   Updated: 2022/06/15 16:38:23 by hoomen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"push_swap.h"

bool	ft_strisnumeric(const char *s)
{
	int	i;

	i = 0;
	if (s[0] == '-')
		i++;
	while (s[i])
	{
		if (ft_isdigit((int) s[i]))
			i++;
		else
			return (false);
	}
	return (true);
}

void	ft_free_argv_ps(char **arr)
{
	int		i;

	i = 1;
	while (arr[i] != NULL)
	{
		free(arr[i]);
		i++;
	}
	free(arr);
}

char	**ft_split_shift(char *s, char c)
{
	char	**temp;
	char	**argv;
	int		count;
	int		i;

	temp = ft_split(s, c);
	count = 0;
	while (temp[count] != NULL)
		count++;
	argv = malloc((count + 2) * sizeof(char *));
	if (argv == NULL)
		return (NULL);
	argv[0] = NULL;
	i = 0;
	while (i < (count + 1))
	{
		argv[i + 1] = temp[i];
		i++;
	}
	free(temp);
	return (argv);
}
