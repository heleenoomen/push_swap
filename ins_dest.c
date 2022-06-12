#include"push_swap.h"

void	r_org_fw(t_dlst *a, t_dlst *b, t_p *org, t_p *dest)
{
	int	r_sim;

	r_sim = 0;
	if (dest->rev == -1 || dest->rev == 0)
	{
		dest->rev = 0;
		if (dest->r > org->r)
			r_sim = dest->r - org->r;
		else
			r_sim = org->r - dest->r;
	}
	while (r_sim)
	{
		ft_r_sim(a, b);
		r_sim--;
		dest->r--;
		org->r--;
	}
	while (org->r)
	{
		ft_r(a);
		org->r--;
	}
}

void	r_org_rev(t_dlst *a, t_dlst *b, t_p *org, t_p *dest)
{
	int	rr_sim;

	rr_sim = 0;
	if (dest->rev == -1 || dest->rev == 1)
	{
		dest->rev = 1;
		if (dest->r > org->r)
			rr_sim = dest->r - org->r;
		else
			rr_sim = org->r - dest->r;
	}
	while (rr_sim)
	{
		ft_rr_sim(a, b);
		rr_sim--;
		dest->r--;
		org->r--;
	}
	while (org->r)
	{
		ft_rr(a);
		org->r--;
	}
}

void	r_org(t_dlst *a, t_dlst *b, t_p *org, t_p *dest)
{
	if (!org->rev)
		r_org_fw(a, b, org, dest);
	else
		r_org_rev(a, b, org, dest);
}

void	ins_first_second(t_dlst *a, t_dlst *b)
{
	if (b->head == NULL)
		ft_p(a, b);
	else if (b->head == b->tail && a->head->nb < b->head->nb)
		ft_p(a, b);
	else if (b->head == b->tail)
	{
		ft_p(a, b);
		ft_r(b);
	}
}

void	r_dest(t_dlst *b, t_p *dest)
{
	if (!dest->rev)
	{
		while (dest->r)
		{
			ft_r(b);
			dest->r--;
		}
		return ;
	}
	while (dest->r)
	{
		ft_rr(b);
	}
}

void	ins_dest(t_dlst *a, t_dlst *b, t_p *org, t_p *dest)
{
	r_org(a, b, org, dest);
	if (b->head == NULL || b->head == b->tail)
	{
		ins_first_second(a, b);
		return ;
	}
	if (a->head->nb > b->max)
		r_dest(b, dest);
	ft_p(a, b);
}