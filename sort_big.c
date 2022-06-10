#include"push_swap.h"

//search where is the nearest item that we are going to push
bool	closer_to_top(t_dlst *a, int nb)
{
	int		t;
	int		b;
	t_dnode	*i;

	t = 0;
	b = 0;
	i = a->head;
	while (1)
	{
		if (i->nb > nb)
			break ;
		t++;
		i = i->next;
	}
	i = a->tail;
	while (1)
	{
		if (i->nb > nb)
			break ;
		b++;
		i = i->prev;
	}
	return (t < b);
}

//calculate how many further operations it takes to insert a number from the top of stack a to the top of stack b
int	calc_ops_insb(t_dlst *b, int nb, int count)
{
	t_dnode	*i;

	if (nb < b->min)
		calc_insb_min(b, nb, count);
	if (b->head == NULL)
		return (count++);
	
	i = b->head;
	while (1)
	{
		if (nb < i->nb && nb > i->prev->nb)
			break ;
		i = i->next;
		count++;
	}
	i = b->head;
	if (closer_to_top(b, nb))
	{
		while (1)
	}
}

// calculate the amount of operations it takes to bring each of the numbers < lim in the upper half of the stack
// to the top of the stack
int	calc_ops_top(t_dlst *a, t_dlst *b, int lim, t_p *p)
{
	int		count;
	int		count_new;
	int		mid;
	int		i;
	t_dnode	*j;

	mid = a->size / 2;
	i = 0;
	count = MAX_INT;
	count_new = 0;
	j = a->head;
	while (i <= mid)
	{
		if (j->nb < lim)
		{
			count_new = calc_ops_insb(b, j->nb, count);
			if (count_new < count)
				count = count_new;
		}
		j = j->next;
		count++;
		i++;
	}
	return (count);
}


void	calc_ops(t_dlst *a, t_dlst *b, int lim)
{
	int	ops_top;
	int	ops_bottom;

	ops_top = calc_ops_top(a, b, lim);
	ops_bottom = calc_ops_bottom(a, b, lim);
}



void	ins_ra(t_dlst *a, t_dlst *b, int *ops)
{
	while (a->head->nb > b->head->nb)
		ft_sb(b, ops);
}

void	pb_sort(t_dlst *a, t_dlst *b, int *ops)
{
	if (b->head == NULL)
		ft_pb(a, b, ops);
	else if (b->head == b->tail && a->head->nb < b->head->nb)
		ft_pb(a, b, ops);
	else if (b->head == b->tail)
	{
		ft_pb(a, b, ops);
		ft_rb(a, b, ops);
	}
	else if (a->head->nb > b->head->nb && a->head->nb < a->head->next->nb)
	{
		ft_pb(a, b, ops);
		ft_sb(a, b, ops);
	}
	else if (closer_to_top(b, nb))
		ins_ra(a, b, ops);
	else
		ins_rra(a, b, ops);
}

void	pbsort_ra(t_dlst *a, t_dlst *b, int nb, int *ops)
{
	while (a->head < nb)
		ft_ra(a, ops);
	pb_sort(a, b, ops);
}

void	pbsort_rra(t_dlst *a, t_dlst *b, int nb, int *ops)
{
	ft_rra(a, ops);
	while (a->head < nb)
		ft_rra(a, ops);
	ft_pbsort(a, b, ops);
}

//sort everything that is bigger than nb
void	sort_portion(t_dlst *a, t_dlst *b, int nb, int *ops)
{
	int	count;

	count = 0;
	while (count < 10)
	{
		if (closer_to_top(a, nb))
			pb_ra(a, b, nb, ops);
		else
			pb_rra(a, b, nb, ops);
		count++;
	}
}

//divide a in portions of 10 items that we push to b and then sort. 
void	sort_big(t_dlst *a, t_dlst *b, t_dlst *sor, int *ops)
{
	int		s;
	int		p;
	t_dnode	*i;

	i = sor->head;
	p = 0;
	s = 0;
	while (1)
	{
		if (p == 9)
		{
			sort_portion(a, b, i->nb, ops);
			p = 0;
		}
		i = i->next;
		p++;
		if (i = sor->tail)
		{
			if (p)
				sort_portion(a, b, i->nb, ops);
			break ;
		}
	}
}
