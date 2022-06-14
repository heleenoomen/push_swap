//read, write, malloc, free, exit
//ft_printf,libft

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
		argv[i+1] = temp[i];
		i++;
	}
	free(temp);
	return (argv);
}

void	parse_argv(int *argc, char ***argv)  //3
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

void	make_dllst(char **argv, t_dlst *a)  //4
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

void	make_stack_a(int argc, char **argv, t_dlst *a) //2
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


int	main(int argc, char **argv)  //1
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
