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


int	make_stack_a(int argc, char **argv, t_dlst *stack_a)
{
	int	i;
	int	is_single;

	if (argc == 1)
		exit(0);
	if (argc == 2)
	{
		argv = ft_split_shift(argv[1], ' ');
		if (argv == NULL)
		{
			ft_printf("Error\n");
			exit(0);
		}
		argc = 1;
		while (argv[argc] != NULL)
			argc++;
		is_single = 1;
	}
	else
		is_single = 0;
	i = 1;
	while (argv[i] != NULL)
	{
		if (!ft_strisnumeric(argv[i]))
		{
			ft_printf("Error\n");
			dlst_clear(stack_a);
			exit(0);
		}
		dlst_addnew(argv[i], stack_a);
		stack_a->tail->id = i - 1;
		i++;
	}
	if (is_single)
		ft_free_argv_ps(argv);
	return (argc);
}

void	check(void)
{
	system("leaks push_swap");
}

int	main(int argc, char **argv)
{
	t_dlst	stack_a;
	t_dlst	stack_b;
	int		ops;

	//atexit(check);
	if (argc == 1)
		return (0);
	ops = 0;
	dlst_init(&stack_a);
	dlst_init(&stack_b);
	argc = make_stack_a(argc, argv, &stack_a);
	//check_usage(argc, argv, &stack_a);
	//print_dlst(&stack_a, "stack_a;");
	//print_dlst_rev(&stack_a, "stack_a reverse:");
	//ft_sort_v2(argc, &stack_a, &stack_b, &ops);
	quickso_dlst(&stack_a, stack_a.head, stack_a.tail);
	print_sorted(&stack_a, &ops);
	//print_dlst_rev(&stack_a, "stack_a reverse");
	dlst_clear(&stack_a);
	dlst_clear(&stack_b);
	return (0);
}
