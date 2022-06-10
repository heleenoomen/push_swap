#include"push_swap.h"

void	quickso_dlst(t_dlst *stack, t_dnode *head, t_dnode *tail)
{
	int		v;
	int		temp;
	t_dnode	*i;
	t_dnode	*j;

	if (tail->id <= head->id)
		return ;
	i = head;
	j = tail;
	v = tail->nb;
	while (1)
	{
		while (i->nb < v && i != tail)
			i = i->next;
		while (j->nb >= v && j != head)
			j = j->prev;
		if (i->id >= j->id)
			break ;
		temp = i->nb;
		i->nb = j->nb;
		j->nb = temp;
	}
	temp = i->nb;
	i->nb = v;
	tail->nb = temp;
	if (i != head)
		quickso_dlst(stack, head, i->prev);
	if (i != tail)
		quickso_dlst(stack, i->next, tail);
}
