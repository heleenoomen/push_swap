#include"push_swap.h"

void	pb_sort(t_dlst *a, t_dlst *b, int nb, int *ops)
{
	if (nb > b->max)
		insb_max(a, b, ops);
	else if (nb < b->max)
		insb_min(a, b, ops);
	else
		insb_inbetw(a, b, nb, ops);
}

void	sort_portion(t_dlst *a, t_dlst *b, int lim, int *ops)
{
	int	count;
	t_p	parms;

	count = 0;
	while (count < 10)
	{
		pb_calc_ops(a, b, lim, &parms);
		ft_printf("---------------------------\n");
		ft_printf("lim = %i\n", lim);
		ft_printf("parms.num = %i\n", parms.nb);
		ft_printf("parms.ops = %i\n", parms.ops);
		rot_nb_up(a, parms.nb);
		pb_sort(a, b, parms.nb, ops);
		count++;
	}
	(*ops)++;
}

void	sort_big(t_dlst *a, t_dlst *b, t_dlst *sor, int *ops)
{
	int		p;
	t_dnode	*i;

	i = sor->head;
	p = 0;
	while (1)
	{
		if (p == 10)
		{
			sort_portion(a, b, i->nb, ops);
			p = 0;
		}
		i = i->next;
		p++;
		if (i == sor->head)
		{
			if (p > 1)
				sort_portion(a, b, i->prev->nb, ops);
			break ;
		}
	}
}
