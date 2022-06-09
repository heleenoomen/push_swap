#include"push_swap.h"

void	dlst_init(t_dlst *stack)
{
	stack->head = NULL;
	stack->tail = NULL;
	stack->size = 0;
	stack->min = 0;
	stack->max = 0;
}

void	dlst_addnew(const char *s, t_dlst *stack)
{
	t_dnode	*new;

	new = malloc(sizeof(t_dnode));
	new->previous = NULL;
	new->number = ft_atoi(s);
	new->next = NULL;
	dlst_addlast(new, stack);
}

void	dlst_addlast(t_dnode *new, t_dlst *stack)
{
	if (stack->head == NULL)
	{
		stack->head = new;
		stack->tail = new;
		new->next = new;
		new->previous = new;
		stack->size++;
		stack->min = new->number;
		stack->max = new->number;
		return ;
	}
	new->next = stack->head;
	new->previous = stack->tail;
	stack->head->previous = new;
	stack->tail->next = new;
	stack->tail = new;
	stack->size++;
	if (new->number < stack->min)
		stack->min = new->number;
	if (new->number > stack->max)
		stack->max = new->number;
}

void	dlst_addfront(t_dnode *new, t_dlst *stack)
{
	if (stack->head == NULL)
	{
		stack->head = new;
		stack->tail = new;
		new->next = new;
		new->previous = new;
		stack->size++;
		return ;
	}
	new->next = stack->head;
	stack->head = new;
	stack->head->next->previous = stack->head;
	stack->head->previous = stack->tail;
	stack->tail->next = stack->head;
	stack->size++;
}

void	dlst_clear(t_dlst *stack)
{
	t_dlst	i;
	
	if (stack->head == stack->tail)
	{
		free (stack->head);
		return ;
	}
	i.head = stack->head->next;
	i.tail = stack->tail;
	dlst_clear(&i);
	free(stack->head);
	stack->head = NULL;
}

void	reset_min(t_dlst *stack)
{
	int		min;
	t_dnode	*i;

	min = stack->head->number;
	i = stack->head;
	while (i != stack->head)
	{
		if (i->number < min)
			min = i->number;
		i = i->next;
	}
	stack->min = min;
}

void	reset_max(t_dlst *stack)
{
	int		max;
	t_dnode	*i;

	max = stack->head->number;
	i = stack->head;
	while (i != stack->head)
	{
		if (i->number > max)
			max = i->number;
		i = i->next;
	}
	stack->max = max;
}

t_dnode	*dlst_detachfirst(t_dlst *stack)
{
	t_dnode	*first_node;

	if (stack->head == NULL)
		return (NULL);
	first_node = stack->head;
	if (stack->head == stack->tail)
	{
		stack->head = NULL;
		stack->tail = NULL;
		stack->max = 0;
		stack->min = 0;
		stack->size = 0;
		return (first_node);
	}
	stack->head = stack->head->next;
	stack->head->previous = stack->tail;
	stack->tail->next = stack->head;
	first_node->next = NULL;
	first_node->previous = NULL;
	stack->size--;
	if (first_node->number == stack->max)
		reset_max(stack);
	if (first_node->number == stack->min)
		reset_min(stack);
	return (first_node);
}
