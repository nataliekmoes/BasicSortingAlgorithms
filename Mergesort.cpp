#include <iostream>
using namespace std;

const int size = 3;

void print(int* A, int s)
{
	for(int i = 0; i < s; i++)
	{
		cout << A[i] << " ";
	}

	cout << A[s] << endl;
}

void merge (int* A, int l, int m, int r)
{
	cout << "(" << l << ", " << m << ", " << r << ")\n" ;
	int n1 = m - l + 1;
	int n2 = r - m;
	int L[n1+1], R[n2+1];
	int n = l, i = 0, j = 0;

	// copy elements from A to L & R
	for(int i = 0; i < n1; i++)
	{
		L[i] = A[n++];
	}

	n = m+1;
	for(int i = 0; i < n2; i++)
	{
		R[i] = A[n++];
	}

	// set ends to infinity
	L[n1]= 10000;
	R[n2]= 10000;

	// output for test
	cout << "L: ";
	print(L, n1);
	cout << "R: ";
	print(R, n2);

	// sort & copy L/R values to A
	for (int k=l; k <= r; k++)
	{
		cout << "\nL[" << i << "] <= R[" << j << "]?\n";

		if (L[i] <= R[j])
		{
			cout << "A[" << k << "] = L[" << i << "]\n";
			A[k] = L[i];
			i++;
		}

		else
		{
			cout << "A[" << k << "] = R[" << j << "]\n";
			A[k] = R[j];
			j++;
		}
	}
	print(A,size-1);
	cout << endl;
}


void mergesort(int* A, int l, int r)
{
	if(r > l)
	{
		int m = (r+l)/2;
		mergesort(A, l, m);
		mergesort(A, m+1, r);
		merge(A, l, m, r);
	}
}


int main()
{
	int array[size], j = 0;
	for(int i = 0; i < size; i++)
	{
		array[i] = j++;
	}

	cout << "initial array:  ";
	print(array, size-1);
	cout << endl;
	mergesort(array, 0, size-1);
	cout<< "final array: ";
	print(array, size-1);

	return 0;
}
