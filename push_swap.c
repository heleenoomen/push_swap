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


void	make_a(int argc, char **argv, t_dlst *a)
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
	if (is_single)
		ft_free_argv_ps(argv);
}

void	check(void)
{
	system("leaks push_swap");
}

void	check_dupl(t_dlst *a, t_dlst *sor)
{
	t_dnode	*i;
	
	i = sor->head;
	while (1)
	{
		if (i->nb == i->next->nb)
		{
			dlst_clear(sor);
			dlst_clear(a);
			ft_printf("Error\n");
			exit(0);
		}
		i = i->next;
		if (i == sor->head)
			break;
	}
}

void	make_sor(t_dlst *a, t_dlst *sor)
{
	dlst_dup(a, sor);
	quickso_dlst(sor, sor->head, sor->tail);
}

int	main(int argc, char **argv)
{
	t_dlst	a;
	t_dlst	sor;

	//atexit(check);
	if (argc == 1)
		return (0);
	make_a(argc, argv, &a);
	make_sor(&a, &sor);
	//print_dlst(&sor, "sor");
	check_dupl(&a, &sor);
	//simplify_sequence(&a, &sor);
	//print_dlst(&a, "stack a");
	ft_sort(&a);
	//print_sorted(&a);
	dlst_clear(&a);
	//dlst_clear(&b);
	dlst_clear(&sor);
	return (0);
}
