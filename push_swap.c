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

void	check_usage(int argc, char **argv, t_dlst *stack_a)
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
			dlst_clear(stack_a);
			exit(0);
		}
		dlst_addnew(argv[i], stack_a);
		stack_a->tail->id = i - 1;
		i++;
	}
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

	atexit(check);
	ops = 0;
	dlst_init(&stack_a);
	dlst_init(&stack_b);
	check_usage(argc, argv, &stack_a);
	//print_dlst(&stack_a, "stack_a;");
	//print_dlst_rev(&stack_a, "stack_a reverse:");
	//liss(&stack_a);
	//print_liss(&stack_a);

	ft_sort(argc, &stack_a, &stack_b, &ops);
	//quickso_dlst(&stack_a, stack_a.head, stack_a.tail);
	//printf("------------AFTER QUICKSO_DLST--------------\n");
	//print_dlst(&stack_a, "stack_a;");
	//print_dlst_rev(&stack_a, "stack_a reverse:");
	dlst_clear(&stack_a);
	dlst_clear(&stack_b);
	return (0);
}
