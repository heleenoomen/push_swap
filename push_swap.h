#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include<unistd.h>
# include<stdlib.h>
# include<stdbool.h>
# include<stdio.h>
# include"ft_printf/ft_printf.h"
# include"libft/libft.h"

typedef struct s_dnode
{
	struct s_dnode	*prev;
	int				nb;
	int				id;
	struct s_dnode	*next;
}					t_dnode;

typedef struct s_dlst
{
	t_dnode	*head;
	t_dnode	*tail;
	char	name;
	int		size;
	int		min;
	int		max;
}			t_dlst;

typedef struct s_p
{
	int		nb;
	int		ops;
	int		rev;  // 1 when rr is fastest, 0 when r is fastest, -1 when both are equally fast
	int		r;  // number of rotations
	int		r_sim;
}			t_p;

# define MAX_INT	2147483647

# define ps		print_stacks(a, b)
# define ps2	print_stacks(a, &b)

//push_swap.c
bool	ft_strisnumeric(const char *s);
void	check_usage(int argc, char **argv, t_dlst *stack_a);

//dlst_basics.c
void	dlst_init(t_dlst *stack, char name);
void	dlst_addnew(const char *s, t_dlst *stack);
void	dlst_addlast(t_dnode *newn, t_dlst *stack);
void	dlst_addfront(t_dnode *newn, t_dlst *stack);
void	dlst_clear(t_dlst *stack);
void	reset_min(t_dlst *stack);
void	reset_max(t_dlst *stack);
t_dnode	*dlst_detachfirst(t_dlst *stack);
void	dlst_dup(t_dlst *source, t_dlst *dest);

//ops_gen.c
void	ft_swap(t_dlst *stack);
void	ft_rotate(t_dlst *stack);
void	ft_rotate_rev(t_dlst *stack);
void	ft_push(t_dlst *org, t_dlst *dest);
void	ft_s(t_dlst *stack);
void	ft_r(t_dlst *stack);
void	ft_rr(t_dlst *stack);
void	ft_p(t_dlst *org, t_dlst *dest);
void	ft_r_sim(t_dlst *a, t_dlst *b);
void	ft_rr_sim(t_dlst *a, t_dlst *b);

//sort.c
void	ft_sort(t_dlst *a);

//push_to_dest.c
void	push_to_dest(t_dlst *a, t_dlst *b);
void	push_last_q(t_dlst *a, t_dlst *b);

//ins_dest.c
void	ins_dest(t_dlst *a, t_dlst *b, t_p *org, t_p *dest);
void	r_dest(t_dlst *b, t_p *dest);

//print_dlst.c
void	print_sorted(t_dlst *stack_t);
void	print_quickso_dlst(t_dnode *head, t_dnode *tail, t_dnode *i, t_dnode *j);
void	print_stacks(t_dlst *a, t_dlst *b);
void	print_p(t_p *p, char *name);

//quickso_dlst.c
void	quickso_dlst(t_dlst *stack, t_dnode *head, t_dnode *tail);
void	simplify_sequence(t_dlst *a, t_dlst *sor);

#endif