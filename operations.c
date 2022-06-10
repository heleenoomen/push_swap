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

bool	ft_push(t_dlst *from, t_dlst *to)
{
	t_dnode	*temp;

	temp = dlst_detachfirst(from);
	if (temp == NULL)
		return (-1);
	dlst_addfront(temp, to);
	return (0);
}

void	ft_sa(t_dlst *stack_a, int *ops)
{
	ft_swap(stack_a);
	ft_printf("sa\n");
	(*ops)++;
}

void	ft_sb(t_dlst *stack_b, int *ops)
{
	ft_swap(stack_b);
	ft_printf("sb\n");
	(*ops)++;
}

void	ft_ra(t_dlst *stack_a, int *ops)
{
	ft_rotate(stack_a);
	ft_printf("ra\n");
	(*ops)++;
}

void	ft_rb(t_dlst *stack_b, int *ops)
{
	ft_rotate(stack_b);
	ft_printf("rb\n");
	(*ops)++;
}

void	ft_rra(t_dlst *stack_a, int *ops)
{
	ft_rotate_rev(stack_a);
	ft_printf("rra\n");
	(*ops)++;
}

void	ft_rrb(t_dlst *stack_b, int *ops)
{
	ft_rotate_rev(stack_b);
	ft_printf("rrb\n");
	(*ops)++;
}


void	ft_pb(t_dlst *stack_a, t_dlst *stack_b, int *ops)
{
	ft_push(stack_a, stack_b);
	ft_printf("pb\n");
	(*ops)++;
}

void	ft_pa(t_dlst *stack_a, t_dlst *stack_b, int *ops)
{
	ft_push(stack_b, stack_a);
	ft_printf("pa\n");
	(*ops)++;
}
