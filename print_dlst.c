#include"push_swap.h"

void	print_dlst(t_dlst **dlst, char *name)
{
	t_dlst	*i;

	ft_printf("-----------------------------\n");
	ft_printf("%s:\n", name);
	i = *dlst;
	if (i == NULL)
	{
		ft_printf("\tlist is NULL\n");
		return ;
	}
	while (i != NULL)
	{
		ft_printf("\t%i\n", i->number);
		i = i->next;
	}
	ft_printf("-----------------------------\n");
}

void	print_sorted(t_dlst **dlst)
{
	t_dlst	*i; 
	
	i = *dlst;
	if (i == NULL)
	{
		ft_printf("Error print_sorted: head is NULL\n");
		return ;
	}
	ft_printf("we are sorted:");
	while (i->next != NULL)
	{
		ft_printf(" %i,", i->number);
		i = i->next;
	}
	ft_printf(" %i\n", i->number);
}
