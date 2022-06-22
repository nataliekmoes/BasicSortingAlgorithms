/*
 * QuickSort.c
 */

#include <stdio.h>
int count = 0, qCalls = 0;
void print(int* A, int r)
{
	int i = 0;
	for(; i < r; i++)
	{
		printf("%i ", A[i]);
	}
};


int Partition(int* A, int p, int r)
{
	count++;
	int i = p-1, temp, j = p;

	for(; j < r; j++)
	{
		printf("%i <= %i\n", A[j], A[r]);

		if(A[j] <= A[r])
		{
			i++;
			temp = A[j];
			A[j] = A[i];
			A[i] = temp;
		}
	}

	temp = A[i+1];
	A[i+1] = A[r];
	A[r] = temp;

	return i+1;
};


void Quicksort (int* A, int p, int r)
{
	qCalls++;

	if(p < r)
	{
		int k = Partition(A, p, r);
		Quicksort (A, p, k-1);
		Quicksort (A, k+1, r);
	}
};



int main()
{
	int right = 5, left = 0;
	int array[] = {3, 1, 2, 5, 4};

	Quicksort(array, left, right-1);

	return 0;
};
