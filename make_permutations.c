#include"push_swap.h"

int		ft_factorial(int nbr)
{
	if (nbr == 1 || nbr == 0)
		return (1);
	nbr = nbr * ft_factorial(nbr - 1);
	return (nbr);
}

// char	**make_permutations(char *s)
// {
// 	char	**arr;
// 	int		count;

// 	arr = ft_split(s, ' ');
// 	count = 0;
// 	while (arr[count] != NULL)
// 		count++;
// 	return (NULL);
// }

int	main(void)
{
	int	nbr;
	int **arr;

	nbr = ft_factorial(4);
	arr = malloc(nbr * sizeof(int *));
	printf("%i\n", nbr);
	free(arr);
}
