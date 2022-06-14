#include"push_swap.h"

void	dlst_init(t_dlst *stack, char name)
{
	stack->head = NULL;
	stack->tail = NULL;
	stack->name = name;
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

