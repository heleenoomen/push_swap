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
	v = tail->number;
	while (1)
	{
		while (i->number < v && i != tail)
			i = i->next;
		while (j->number >= v && j != head)
			j = j->next;
		if (i->id >= j->id)
			break ;
		temp = i->number;
		i->number = j->number;
		j->number = i->number;
	}
	temp = i->number;
	i->number = v;
	tail->number = temp;
	//print_quickso_dlst(head, tail, i, j);
	if (i != head)
		quickso_dlst(stack, head, i->previous);
	if (i != tail)
		quickso_dlst(stack, i->next, tail);
}
