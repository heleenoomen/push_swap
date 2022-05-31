#include"push_swap.h"

void	ft_swap(t_dlst *stack)
{
	t_dnode	*t;

	t = stack->head;
	stack->head = stack->head->next;
	if (stack->head->next == NULL)
		t->next = NULL;
	else
		t->next = stack->head->next;
	stack->head->next = t;
	stack->head->previous = NULL;
	stack->head->next->previous = stack->head;
	stack->head->next->next->previous = stack->head->next;
}

void	ft_rotate(t_dlst *stack)
{
	t_dnode	*new_tail;

	new_tail = stack->head;
	new_tail->previous = stack->tail;
	stack->head = stack->head->next;
	stack->tail->next = new_tail;
	new_tail->next = NULL;
	stack->tail = new_tail;
	stack->head->previous = NULL;
	stack->head->next->previous = stack->head;
}

void	ft_rotate_rev(t_dlst *stack)
{
	t_dnode	*new_head;

	new_head = stack->tail;
	stack->tail = stack->tail->previous;
	stack->tail->next = NULL;
	new_head->next = stack->head;
	new_head->next->previous = new_head;
	stack->head = new_head;
	stack->head->previous = NULL;
}

void	ft_push(t_dlst *from, t_dlst *to)
{
	t_dnode	*t;

	dlst_addfront(from->head, to);
	t = from->head;
	from->head = from->head->next;
	from->head->previous = NULL;
	free(t);
}

void	ft_sa(t_dlst *stack_a, int *ops)
{
	ft_swap(stack_a);
	ft_printf("sa\n");
	(*ops)++;
}

void	ft_ra(t_dlst *stack_a, int *ops)
{
	ft_rotate(stack_a);
	ft_printf("ra\n");
	(*ops)++;
}

void	ft_rra(t_dlst *stack_a, int *ops)
{
	ft_rotate_rev(stack_a);
	ft_printf("rra\n");
	(*ops)++;
}

void	ft_pb(t_dlst *stack_a, t_dlst *stack_b, int *ops)
{
	ft_push(stack_a, stack_b);
	ft_printf("pb\n");
	(*ops)++;
}
