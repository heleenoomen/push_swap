#include"push_swap.h"

void	dlst_init(t_dlst **head)
{
	*head = NULL;
}

void	dlst_addnew(const char *s, t_dlst **head)
{
	t_dlst	*new;

	new = malloc(sizeof(t_dlst));
	new->previous = NULL;
	new->number = ft_atoi(s);
	new->next = NULL;
	dlst_addlast(new, head);
}

void	dlst_addlast(t_dlst *new, t_dlst **head)
{
	t_dlst *i;

	if (*head == NULL)
	{
		*head = new;
		return ;
	}
	i = *head;
	while (i->next != NULL)
		i = i->next;
	i->next = new;
	new->previous = i;
}

void	dlst_clear(t_dlst **head)
{
	if (*head == NULL)
		return ;
	dlst_clear(&((*head)->next));
	free(*head);
	*head = NULL;
}
