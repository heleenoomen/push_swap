#include"push_swap.h"

void	push_nb_b(t_dlst *a, t_dlst *b)
{
	t_p	top;
	t_p	bot;
	int	mid;

	mid = a->size / 2;
	pick_nb_a_top(a, b, mid, &top);
	pick_nb_a_bot(a, b, mid, &bot);

	if (top.ops < bot.ops)
		ins_b(a, b, &top);
	else
		ins_b(a, b, &bot);
}

void	push_to_b(t_dlst *a, t_dlst *b)
{
	//int	i;

	//i = 0;
	while (a->size)// && i < 5)
	{
		push_nb_b(a, b);
		//i++;
	}
	//ps;
}