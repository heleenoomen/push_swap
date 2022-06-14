#include"push_swap.h"

void	ft_swap(t_dlst *stack)
{
	t_dnode	*first;
	t_dnode *second;
	t_dnode *third;

	if (stack->size == 0)
		return ;
	if (stack->size == 1)
		return ;
	first = stack->head;
	second = stack->head->next;
	if (stack->size == 2)
	{
		stack->head = second;
		stack->tail = first;
		return ;
	}
	third = stack->head->next->next;
	stack->head = second;
	second->prev = stack->tail;
	second->next = first;
	first->prev = second;
	first->next = third;
	third->prev = first;
	stack->tail->next = second;
}

void	ft_rotate(t_dlst *stack)
{
	stack->head = stack->head->next;
	stack->tail = stack->head->prev;
}

void	ft_rotate_rev(t_dlst *stack)
{
	stack->head = stack->tail;
	stack->tail = stack->head->prev;
}

void	ft_push(t_dlst *org, t_dlst *dest)
{
	t_dnode	*temp;

	temp = dlst_detachfirst(org);
	if (temp == NULL)
		return ;
	dlst_addfront(temp, dest);
	return ;
}

void	ft_s(t_dlst *stack)
{
	ft_swap(stack);
	ft_printf("s%c\n", stack->name);
}