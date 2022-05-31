#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include<unistd.h>
# include<stdlib.h>
# include<stdbool.h>
# include"ft_printf/ft_printf.h"
# include"libft/libft.h"

typedef struct s_dlst
{
	struct s_dlst	*previous;
	int				number;
	struct s_dlst	*next;
}					t_dlst;

//push_swap.c
bool	ft_strisnumeric(const char *s);
void	check_usage(int argc, char **argv, t_dlst **head);

//dlst_basics.c
void	dlst_init(t_dlst **head);
void	dlst_addnew(const char *s, t_dlst **head);
void	dlst_addlast(t_dlst *new, t_dlst **head);
void	dlst_clear(t_dlst **head);

//sort.c
void	ft_sort_two(t_dlst **head_a, t_dlst **head_b);
void	ft_sort_three(t_dlst **head_a, t_dlst **head_b);
void	ft_sort_four(t_dlst **head_a, t_dlst **head_b);
void	ft_sort_five(t_dlst **head_a, t_dlst **head_b);
void	ft_sort(int argc, t_dlst **head_a, t_dlst **head_b, int *ops);

//print_dlst.c

//ops.c




#endif