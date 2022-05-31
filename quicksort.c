#define true 1
#include<stdio.h>



void	quicksort(int a[], int l, int r)
{
	int	v;  // value we check against
	int	i;  // pointer from the left
	int	j;  // pointer from the right
	int	t;  // temporary storage container

	if (r > l)
	{
		v = a[r];  // this is the value we check against
		i = l - 1; // the position of the pointer at the beginning of the array. Should be 1 the first time around
		j = r; // the position of the pointer at the end oof the array, should be the last element in the array the first time around
		while (true)
		{
			while (a[++i] < v) ;  // increment i, then check if smaller than v. Keep doing this until we find a value bigger than v
			while (a[--j] > v) ;  // decrement j, then check if bigger than v. Keep doing this until we find a value smaller than v
			if (i >= j)
				break ;
			t = a[i];  // swap a[i] and a[j] everytime a[i] is smaller than v and a[j] is bigger than v
			a[i] = a[j];
			a[j] = t;
		}
		t = a[i]; // swap a[i] and a[r], so that
		a[i] = a[r];
		a[r] = t;
		quicksort(a, l, i - l);  // quicksort from the beginning of the array until 
		quicksort(a, i + 1, r);
	}
}

int	main(void)
{
	int	arr[21] = {0, 'a', 'n', 'e', 'x', 'a', 'm', 'p', 'l', 'e', 'o', 'f', 'q', 'u', 'i', 'c', 'k', 's', 'o', 'r', 't'};
	quicksort(arr, 1, 21);
	int n = 0;
	while (n < 21)
	{
		printf("%c, ", (unsigned char) arr[n]);
		n++;
	}
}