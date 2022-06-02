#include<stdio.h>

void	quicksort(int a[], int l, int r)
{
	int	i;
	int	j;
	int	pivot;
	int	t;
 
	if (l < r)
	{
		pivot = l;
		i = l;
		j = r;
		while(1)
		{
			while(a[i] <= a[pivot] && i < r)
	 	 		i++;
 	 		while(a[j] > a[pivot] && j > 0)
	 	 		j--;
 	 		if(i >= j)
				break;
			t = a[i];
			a[i] = a[j];
			a[j] = t;
		}
		t = a[pivot];
		a[pivot] = a[j];
		a[j] = t;
		quicksort(a, l, j - 1);
		quicksort(a, j + 1, r);
	}
}

int main(void)
{
	int	arr[20] = {'a', 'n', 'e', 'x', 'a', 'm', 'p', 'l', 'e', 'o', 'f', 'q', 'u', 'i', 'c', 'k', 's', 'o', 'r', 't'};
	quicksort(arr, 0, 19);
	int n = 0;
	while (n < 20)
	{
		printf("%c, ", (unsigned char) arr[n]);
		n++;
	}
	return 0;
}