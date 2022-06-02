

int	partition(int a[], int l, int r)
{
	int	v;
	int	i;
	int	j;
	int	t;
	
	v = a[r];
	i = l - 1;
	j = r;
	while (1)
	{
		while (a[++i] < v) ;
		while (a[--j] > v) ;
		if (i >= j)
			break ;
		t = a[i];
		a[i] = a[j];
		a[j] = t;
	}
	t = a[i];
	a[i] = a[r];
	a[r] = t;
}

quicksort(int a[], int N)
{
	int i;
	int l;
	int r;
	
	l = 1;
	r = N;
	stackinit();
	while (1)
	{
		while (r > l)
		{
			i = partition(a, l, r);
			if (i - l > r - i)
			{
				push(l);
				push(i - 1);
				l = i + 1;
			}
			else
			{
				push(i + 1);
				push(r);
				r = i - 1;
			}
		}
		if (stackempty())
			break;
		r = pop();
		l = pop();
	}
}
