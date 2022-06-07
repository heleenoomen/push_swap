//	1)	if a[i] is smallest among all end candidates of active lists, 
//		we will start new active list of length 1.
//	2)	if a[i] is largest among all end candidates of active lists, we will clone the largest
//		active list and extend it by A[i]
//	3)	if A[i] is in between, we will find a list with largest end element that is smaller than a[i],
//		extend by A[i]

int	liss(int a[], int N)
{
	int	M[N];
	int	L;
	int	i;
	int	j;

	M[0] = -1;
	M[1] = 0;
	L = 0;
	i = 0;
	while (i < N)
	{
		if (a[i] <= a[M[1]])
		{
			M[1] = i;
			if (i == 0)
				L++;
		}
		else if (a[i] > M[L])
		{
			M[L+1] = i;
			L++;
		}
		else
		{
			j = 1;
			while (j <= L)
			{
				if (a[i] < a[M[j]])
					M[j] = i;
				j++;
			}
		}
		i++;
	}
}