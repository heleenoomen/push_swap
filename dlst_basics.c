#include"push_swap.h"

void	dlst_init(t_dlst *stack)
{
	stack->head = NULL;
	stack->tail = NULL;
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
	t_dnode *i;

	stack->tail = new;
	if (stack->head == NULL)
	{
		stack->head = new;
		return ;
	}
	i = stack->head;
	while (i->next != NULL)
		i = i->next;
	i->next = new;
	new->previous = i;
}

// void	dlst_clear(t_dnode **head)
// {
// 	if (*head == NULL)
// 		return ;
// 	dlst_clear(&((*head)->next));
// 	free(*head);
// 	*head = NULL;
// }

void	dlst_clear(t_dnode **head)
{
	if (*head == NULL)
		return ;
	dlst_clear(&((*head)->next));
	free(*head);
	*head = NULL;
}