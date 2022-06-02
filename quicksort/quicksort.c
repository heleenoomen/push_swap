#define true 1
#include<stdio.h>

void	quicksort(int a[], int l, int r) // l = left, r = right
{
	int	v;
	int	i;
	int	j;
	int	t;

	if (r > l)
	{
		v = r;
		i = l - 1;
		j = r;
		while (1)
		{
			while (a[++i] < a[v]) ;
			while (a[j] > a[v])
				j--;
			if (i >= j)
				break ;
			t = a[i];
			a[i] = a[j];
			a[j] = t;
		}
		t = a[i];
		a[i] = a[r];
		a[r] = t;
		quicksort(a, l, i - l);
		quicksort(a, i + 1, r);
	}
}

int	main(void)
{
	int	arr[21] = {0, 'a', 'n', 'e', 'x', 'a', 'm', 'p', 'l', 'e', 'o', 'f', 'q', 'u', 'i', 'c', 'k', 's', 'o', 'r', 't'};
	quicksort(arr, 1, 20);
	int n = 0;
	while (n < 21)
	{
		printf("%c, ", (unsigned char) arr[n]);
		n++;
	}
}

