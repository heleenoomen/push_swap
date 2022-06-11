#include"push_swap.h"

bool	r_is_faster(t_dlst *stack, int lim)
{
	t_dnode	*i;
	int		mid;
	int		top;
	int		bottom;
	
	top = 0;
	bottom = 1;
	mid = stack->size / 2;
	i = stack->head;
	while (top <= mid)
	{
		if (i->nb < lim)
			break ;
		i = i->next;
		top++;
	}
	i = stack->tail;
	while (bottom <= (mid + 1))
	{
		if (i->nb < lim)
			break ;
		i = i->prev;
		bottom++;
	}
	return (top <= bottom);
}

void	r_nb_to_top(t_dlst *a, int lim, int *ops)
{
	while (a->head->nb >= lim)
		ft_ra(a, ops);
}

void	rr_nb_to_top(t_dlst *a, int lim, int *ops)
{
	while (a->head->nb >= lim)
		ft_rra(a, ops);
}

void	pb_portion(t_dlst *a, t_dlst *b, int lim, int *ops)
{
	int		count;

	count = 0;
	while (count < PORTION)
	{
		if (r_is_faster(a, lim))
			r_nb_to_top(a, lim, ops);
		else
			rr_nb_to_top(a, lim, ops);
		ft_pb(a, b, ops);
		count++;
	}
}

void	ft_pa_sort(t_dlst *a, t_dlst *b, int *ops)
{
	int		rotations;

	rotations = 0;
	while (1)
	{
		if (b->head->nb == b->max)
		{
			ft_pa(a, b, ops);
			if (b->size == 0)
				break ;
			while (rotations)
			{
				ft_rrb(b, ops);
				rotations--;
			}
		}
		else
		{
			ft_rb(b, ops);
			rotations++;
		}
	}
}

void	sort_big(t_dlst *a, t_dlst *b, t_dlst *sor, int *ops)
{
	int		p;
	t_dnode	*i;

	i = sor->head;
	p = 0;
	while (1)
	{
		if (p == PORTION)
		{
			pb_portion(a, b, i->nb, ops);
			p = 0;
		}
		i = i->next;
		p++;
		if (i == sor->head)
		{
			while (a->size)
				ft_pb(a, b, ops);
			break; ;
		}
	}
	ft_pa_sort(a, b, ops);
}
