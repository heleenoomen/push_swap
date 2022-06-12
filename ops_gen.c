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

void	ft_r(t_dlst *stack)
{
	ft_rotate(stack);
	ft_printf("r%c\n", stack->name);
}

void	ft_rr(t_dlst *stack)
{
	ft_rotate_rev(stack);
	ft_printf("rr%c\n", stack->name);
}

void	ft_p(t_dlst *org, t_dlst *dest)
{
	ft_push(org, dest);
	ft_printf("p%c\n", dest->name);
}

void	ft_r_sim(t_dlst *a, t_dlst *b)
{
	ft_rotate(a);
	ft_rotate(b);
	ft_printf("rr\n");
}

void	ft_rr_sim(t_dlst *a, t_dlst *b)
{
	ft_rotate_rev(a);
	ft_rotate_rev(b);
	ft_printf("rrr\n");
}