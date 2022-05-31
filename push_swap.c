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

void	check_usage(int argc, char **argv, t_dlst **head)
{
	int	i;

	if (argc == 1)
		exit(0);
	i = 1;
	while (argv[i] != NULL)
	{
		if (!ft_strisnumeric(argv[i]))
		{
			ft_printf("Error\n");
			dlst_clear(head);
			exit(0);
		}
		dlst_addnew(argv[i], head);
		i++;
	}
}

void	check(void)
{
	system("leaks push_swap");
}

int	main(int argc, char **argv)
{
	t_dlst	*head_a;
	t_dlst	*head_b;
	int		ops;

	atexit(check);
	dlst_init(&head_a);
	dlst_init(&head_b);
	ft_sort(argc, &head_a, &head_b, &s);
	check_usage(argc, argv, &head_a);
	dlst_clear(&head_a);
	dlst_clear(&head_b);
}
