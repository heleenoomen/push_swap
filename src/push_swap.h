/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoomen <hoomen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/14 13:48:33 by hoomen            #+#    #+#             */
/*   Updated: 2022/06/15 16:39:01 by hoomen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include<unistd.h>
# include<stdlib.h>
# include<stdbool.h>
# include<stdio.h>
# include<stddef.h>
# include"../ft_printf/ft_printf.h"
# include"../libft/libft.h"
# include"../get_next_line/get_next_line.h"

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
	int		rev;
	int		r;
	int		r_sim;
}			t_p;

# define MAX_INT (unsigned int) 2147483647

//input_utils1.c
void	parse_argv(int *argc, char ***argv);
void	make_dllst(char **argv, t_dlst *a);
void	make_stack_a(int argc, char **argv, t_dlst *a);

//input_utils2.c
bool	ft_strisnumeric(const char *s);
void	ft_free_argv_ps(char **arr);
char	**ft_split_shift(char *s, char c);

//dlst_basics1.c
void	dlst_init(t_dlst *stack, char name);
void	dlst_addnew(t_dlst *stack, int i);
void	dlst_addlast(t_dnode *newn, t_dlst *stack);
void	dlst_addfront(t_dnode *newn, t_dlst *stack);

//dlst_basics2.c
void	dlst_clear(t_dlst *stack);
void	reset_min(t_dlst *stack);
void	reset_max(t_dlst *stack);
t_dnode	*dlst_detachfirst(t_dlst *stack);
void	dlst_dup(t_dlst *source, t_dlst *dest);

//operations1.c
void	ft_swap(t_dlst *stack);
void	ft_rotate(t_dlst *stack);
void	ft_rotate_rev(t_dlst *stack);
void	ft_push(t_dlst *org, t_dlst *dest);
void	ft_s(t_dlst *stack);

//operations2.c
void	ft_r(t_dlst *stack);
void	ft_rr(t_dlst *stack);
void	ft_p(t_dlst *org, t_dlst *dest);
void	ft_r_sim(t_dlst *a, t_dlst *b);
void	ft_rr_sim(t_dlst *a, t_dlst *b);
void	ft_ss(t_dlst *a, t_dlst *b);

//sort.c
void	sort(t_dlst *a, t_dlst *sor);
bool	is_sorted(t_dlst *a);

//sort_utils.c
void	sort_three_b(t_dlst *a, t_dlst *b);
void	push_second_last(t_dlst *a, t_dlst *b);
void	push_last(t_dlst *a, t_dlst *b);
void	final_r(t_dlst *a);

//push_sort.c
void	push_sort(t_dlst *o, t_dlst *d);

//calc_o.c
void	calc_o_rev(t_dlst *o, t_dlst *d, t_p *org, t_p *dst);
void	calc_o_fw(t_dlst *o, t_dlst *d, t_p *org, t_p *dst);

//calc_d.c
void	calc_r_dst(t_dlst *d, int nb, int mid, t_p *dst_new);

//calc_d_min.c
void	calc_r_dst_min_a(t_dlst *d, int mid, t_p *dst_new);

//calc_d_max.c
void	calc_r_dst_max_a(t_dlst *d, int mid, t_p *dst_new);

//ins_dst.c
void	ins_dst(t_dlst *a, t_dlst *b, t_p *org, t_p *dst);

//print_dlst.c
void	print_sorted(t_dlst *stack_t);
void	print_quickso_dlst(t_dnode *hd, t_dnode *tl, t_dnode *i, t_dnode *j);
void	print_stacks(t_dlst *a, t_dlst *b);
void	print_p(t_p *p, char *name);

//check_dupl.c
void	check_dupl(t_dlst *a, t_dlst *sor);
void	quickso_dlst(t_dlst *stack, t_dnode *head, t_dnode *tail);

//push_portion.c
void	push_half(t_dlst *a, t_dlst *b, t_dlst *sor);

//push_half_ss_utils
void	ft_ss(t_dlst *a, t_dlst *b);
void	get_key(t_dlst *a, t_dlst *sor, int *key);
bool	bigger_first(t_dlst *a, int key);
bool	fw_faster_bg(t_dlst *a, int key);
bool	fw_faster_sm(t_dlst *a, int key);

#endif