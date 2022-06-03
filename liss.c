#include"push_swap.h"

void	liss(t_dlst *stack)
{
	t_dnode	*i;
	t_dnode *j;
	t_dnode *stop;
	int		value;
	int		count;

	stack->liss_ptr = stack->head;
	stack->liss_size = 0;
	i = stack->head;
	while(1)
	{
		ft_printf("--------------------------------------------\n");
		stop = i;
		j = i;
		value = 0;
		count = 0;
		while (1)
		{
			if (j->number >= value)
			{
				count++;
				value = j->number;
			}
			else
			{
				count--;
			}
			j = j->next;
			if (j == stop)
			{
				ft_printf("at break: i is at %i, count is %i\n", i->number, count);
				ft_printf("at break: liss_ptr is at: %i\n", stack->liss_ptr->number);
				ft_printf("liss_size = %i\n", stack->liss_size);
				ft_printf("--------------------------------------------\n");
				break ;
			}

		}
		if (count > stack->liss_size)
		{
			stack->liss_size = count;
			stack->liss_ptr = i;
		}
		i = i->next;
		if (i = stack->head)
			break ;
	}
}
