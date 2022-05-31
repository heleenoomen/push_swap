#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include<unistd.h>
# include<stdlib.h>
# include<stdbool.h>
# include"ft_printf/ft_printf.h"
# include"libft/libft.h"

typedef struct s_dnode
{
	struct s_dnode	*previous;
	int				number;
	struct s_dnode	*next;
}						t_dnode;

typedef struct s_dlst
{
	t_dnode	*head;
	t_dnode	*tail;
}			t_dlst;

//push_swap.c
bool	ft_strisnumeric(const char *s);
void	check_usage(int argc, char **argv, t_dlst *stack_a);

//dlst_basics.c
void	dlst_init(t_dlst *stack);
void	dlst_addnew(const char *s, t_dlst *stack);
void	dlst_addlast(t_dnode *new, t_dlst *stack);
void	dlst_clear(t_dnode **head);

//sort.c
void	ft_sort_two(t_dlst *stack_a, int *ops);
void	ft_sort_three(t_dlst *stack_a, t_dlst *stack_b, int *ops);
void	ft_sort_four(t_dlst *stack_a, t_dlst *stack_b, int *ops);
void	ft_sort_five(t_dlst *stack_a, t_dlst *stack_b, int *ops);
void	ft_sort(int argc, t_dlst *stack_a, t_dlst *stack_b, int *ops);

//ops.c
void	ft_sa(t_dlst *stack_a, int *ops);

//print_dlst.c
void	print_dlst(t_dlst *stack, char *name);
void	print_sorted(t_dlst *stack_t, int *ops);


#endif