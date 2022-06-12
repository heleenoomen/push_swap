#include"push_swap.h"

void	r_org_fw(t_dlst *a, t_dlst *b, t_p *org, t_p *dest)
{

	if (dest->rev == -1 || dest->rev == 0)
	{
		while (dest->r_sim)
		{
			ft_r_sim(a, b);
			dest->r_sim--;
			dest->r--;
			org->r--;
		}
	}
	while (org->r)
	{
		ft_r(a);
		org->r--;
	}
}

void	r_org_rev(t_dlst *a, t_dlst *b, t_p *org, t_p *dest)
{
	if (dest->rev == -1 || dest->rev == 1)
	{
		while (dest->r_sim)
		{
			ft_rr_sim(a, b);
			dest->r--;
			org->r--;
			dest->r_sim--;
		}
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

void	r_dest(t_dlst *b, t_p *dest)
{
	int	i = 0;
	ft_printf("dest->r = %i\n", dest->r);
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
		dest->r--;
		i++;
		if (i > 10)
			break ;
	}
}

void	ins_dest(t_dlst *a, t_dlst *b, t_p *org, t_p *dest)
{
	print_p(org, "org");
	print_p(dest, "dest");
	r_org(a, b, org, dest);
	if (a->head->nb < b->min || a->head->nb > b->max)
	{
		if (b->tail->nb != b->max)
			r_dest(b, dest);
	}
	else if (!(a->head->nb > b->head->nb && a->head->nb < b->tail->nb))
		r_dest(b, dest);
	ft_p(a, b);
}