int	binsearch(int a[], int size, int v)
{
	int	l;
	int	r;
	int	x;

	l = 0;
	r = size - 1;
	
	while (r >= l)
	{
		x = (l + r) / 2;
		if (v < a[x])
			r = x - 1;
		else if (v > a[x])
			l = x + 1;
		else
			return (x);
	}
}

void	quicksort(int a[], int l, int r)
{
	int	i;
	int	j;
	int	p;
	int	t;

	if (r <= l)
		return ;
	
	i = l;
	j = r;
	p = a[r];

	while (1)
	{
		while (a[i] < p)
			i++;
		while (a[j] >= p)
			j--;
		if (i >= j)
			break;
		t = a[i];
		a[i] = a[j];
		a[j] = t;
	}
	t = a[i];
	a[i] = p;
	a[r] = t;
	quicksort(a, l, i - 1);
	quicksort(a, i + 1, r);
}

int	main(void)
{
	int	a[20] = {'a', 'n', 'e', 'x', 'a', 'm', 'p', 'l', 'e', 'o', 'f', 'q', 'u', 'i', 'c', 'k', 's', 'o', 'r', 't'};

	quicksort(a, 0, 19);
	int i = 0;
	while (i < 19)
	{
		printf("%c ,", (unsigned char) a[i]);
		i++;
	}
	printf(" %c\n", (unsigned char) a[i]);
}