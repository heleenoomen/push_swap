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
	new->prev = NULL;
	new->nb = ft_atoi(s);
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
		new->prev = new;
		stack->size++;
		stack->min = new->nb;
		stack->max = new->nb;
		return ;
	}
	new->next = stack->head;
	new->prev = stack->tail;
	stack->head->prev = new;
	stack->tail->next = new;
	stack->tail = new;
	stack->size++;
	if (new->nb < stack->min)
		stack->min = new->nb;
	if (new->nb > stack->max)
		stack->max = new->nb;
}

void	dlst_addfront(t_dnode *new, t_dlst *stack)
{
	if (stack->head == NULL)
	{
		stack->head = new;
		stack->tail = new;
		new->next = new;
		new->prev = new;
		stack->min = new->nb;
		stack->max = new->nb;
		stack->size++;
		return ;
	}
	new->next = stack->head;
	stack->head = new;
	stack->head->next->prev = stack->head;
	stack->head->prev = stack->tail;
	stack->tail->next = stack->head;
	stack->size++;
	if (new->nb < stack->min)
		stack->min = new->nb;
	if (new->nb > stack->max)
		stack->max = new->nb;
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

	min = stack->head->nb;
	i = stack->head;
	while (1)
	{
		if (i->nb < min)
			min = i->nb;
		i = i->next;
		if (i == stack->head)
			break ;
	}
	stack->min = min;
}

void	reset_max(t_dlst *stack)
{
	int		max;
	t_dnode	*i;
;
	max = stack->head->nb;
	i = stack->head;
	while (1)
	{
		if (i->nb > max)
			max = i->nb;
		i = i->next;
		if (i == stack->head)
			break ;
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
	stack->head->prev = stack->tail;
	stack->tail->next = stack->head;
	first_node->next = NULL;
	first_node->prev = NULL;
	stack->size--;
	if (first_node->nb == stack->max)
		reset_max(stack);
	if (first_node->nb == stack->min)
		reset_min(stack);
	return (first_node);
}

void	dlst_dup(t_dlst *source, t_dlst *dup)
{
	t_dnode	*new;
	t_dnode	*i;

	dlst_init(dup);
	i = source->head;
	while(1)
	{
		new = malloc(sizeof(t_dnode));
		new->id = i->id;
		new->nb = i->nb;
		new->next = NULL;
		new->prev = NULL;
		dlst_addlast(new, dup);
		i = i->next;
		if (i == source->head)
			break ;
	}
}