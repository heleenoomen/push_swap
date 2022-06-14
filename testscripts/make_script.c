#include"push_swap.h"
#include<fcntl.h>

int	main(void)
{
	int		i;

	i = 1;
	while (i <= 120)
	{
		ft_printf("echo %i:\n", i);
		ft_printf("./push_swap $a%i | wc -l\n", i);
		i++;
	}
}
