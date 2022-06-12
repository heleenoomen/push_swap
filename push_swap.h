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
	int		size;
	int		min;
	int		max;
}			t_dlst;

typedef struct s_p
{
	int		nb;
	int		ops;
	bool	ra;
	int		nra;
	bool	rb;
	int		nrb;
}			t_p;

# define MIN_INT	-2147483648
# define MAX_INT	2147483647

# define pr_sb	print_dlst(b, "stack b")
# define pr_sa	print_dlst(a, "stack a")
# define ps		print_stacks(a, b)

# define PORTION 12
// for 100 items, 12 is optimal  (850-950 ops)
// for 500 items, 20 is optimal  (10.000 - 11.500 ops)
//push_swap.c
bool	ft_strisnumeric(const char *s);
void	check_usage(int argc, char **argv, t_dlst *stack_a);

//dlst_basics.c
void	dlst_init(t_dlst *stack);
void	dlst_addnew(const char *s, t_dlst *stack);
void	dlst_addlast(t_dnode *newn, t_dlst *stack);
void	dlst_addfront(t_dnode *newn, t_dlst *stack);
void	dlst_clear(t_dlst *stack);
void	reset_min(t_dlst *stack);
void	reset_max(t_dlst *stack);
t_dnode	*dlst_detachfirst(t_dlst *stack);
void	dlst_dup(t_dlst *source, t_dlst *dest);

//sort.c
// void	ft_sort_two(t_dlst *stack_a, int *ops);
// void	ft_sort_three(t_dlst *stack_a, int *ops);
// void	ft_sort(t_dlst *stack_a, t_dlst *sor, int *ops);
// void	ft_sort_v2(int argc, t_dlst *stack_a, t_dlst *stack_b, int *ops);
void	ft_sort_sba(t_dlst *a);

//sort_b.c
void	push_nb_b(t_dlst *a, t_dlst *b);
void	push_to_b(t_dlst *a, t_dlst *b);

//pick_nb_a.c
int		det_nrb_max_top(t_dlst *b, int mid, bool *rb);
int		det_nrb_max_bot(t_dlst *b, bool *rb);
int		det_nrb_min_top(t_dlst *b, int mid, bool *rb);
int		det_nrb_min_bot(t_dlst *b, bool *rb);
int		det_nrb_inbtw_top(t_dlst *b, int nb, int mid, bool *rb);
int		det_nrb_inbtw_bot(t_dlst *b, int nb, bool *rb);
int		det_nrb_max(t_dlst *b, int mid, bool *rb);
int		det_nrb_min(t_dlst *b, int mid, bool *rb);
int		det_nrb_inbtw(t_dlst *b, int nb, int mid, bool *rb);
int		det_nrb(t_dlst *b, int nb, int mid, bool *rb);
void	pick_nb_a_top(t_dlst *a, t_dlst *b, int mid, t_p *r);
void	pick_nb_a_bot(t_dlst *a, t_dlst *b, int mid, t_p *r);

//ins_b.c
void	ins_b_max(t_dlst *b, t_p *r);
void	ins_b_min(t_dlst *b, t_p *r);
void	ins_b_inbtw(t_dlst *b, t_p *r);
void	ins_b(t_dlst *a, t_dlst *b, t_p *r);

//sort_small.c
// void	insert_max(t_dlst *stack_a, t_dlst *stack_b, int *ops);
// void	insert_min(t_dlst *stack_a, t_dlst *stack_b, int *ops);
// void	insert_inbetw(t_dlst *stack_a, t_dlst *stack_b, int *ops);
// void	sort_small(t_dlst *stack_a, t_dlst *stack_b, int *ops);

//operations.c
// void	ft_swap(t_dlst *stack);
// void	ft_rotate(t_dlst *stack);
// void	ft_rotate_rev(t_dlst *stack);
// bool	ft_push(t_dlst *from, t_dlst *to);
// void	ft_sa(t_dlst *stack_a, int *ops);
// void	ft_sb(t_dlst *stack_b, int *ops);
// void	ft_ra(t_dlst *stack_a, int *ops);
// void	ft_rb(t_dlst *stack_b, int *ops);
// void	ft_rra(t_dlst *stack_a, int *ops);
// void	ft_rrb(t_dlst *stack_b, int *ops);
// void	ft_pb(t_dlst *stack_a, t_dlst *stack_b, int *ops);
// void	ft_pa(t_dlst *stack_a, t_dlst *stack_b, int *ops);

//ops.c
void	ft_swap(t_dlst *stack);
void	ft_rotate(t_dlst *stack);
void	ft_rotate_rev(t_dlst *stack);
bool	ft_push(t_dlst *from, t_dlst *to);
void	ft_sa(t_dlst *stack_a);
void	ft_sb(t_dlst *stack_b);
void	ft_ra(t_dlst *stack_a);
void	ft_rb(t_dlst *stack_b);
void	ft_rra(t_dlst *stack_a);
void	ft_rrb(t_dlst *stack_b);
void	ft_pb(t_dlst *stack_a, t_dlst *stack_b);
void	ft_pa(t_dlst *stack_a, t_dlst *stack_b);

//print_dlst.c
// void	print_dlst(t_dlst *stack, char *name);
// void	print_dlst_rev(t_dlst *stack, char *name);
void	print_sorted(t_dlst *stack_t);
void	print_quickso_dlst(t_dnode *head, t_dnode *tail, t_dnode *i, t_dnode *j);
void	print_stacks(t_dlst *a, t_dlst *b);

//quickso_dlst.c
void	quickso_dlst(t_dlst *stack, t_dnode *head, t_dnode *tail);
void	simplify_sequence(t_dlst *a, t_dlst *sor);

//sort_big.c
//void	sort_big(t_dlst *a, t_dlst *b, t_dlst *sor, int *ops);

//pb_sort.c
//void	pb_portion_sort(t_dlst *a, t_dlst *b, int lim, int *ops);


#endif