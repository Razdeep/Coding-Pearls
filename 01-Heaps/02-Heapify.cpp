/**
 * Iterative Implementation of Heapify
 * 
 */
#include <iostream>
using namespace std;

void heapify(int a[], int i, int n)
{
	int temp = a[i];
	int j = 2 * i + 1;
	while (j < n)
	{
		if (j < n - 1 && a[j] < a[j + 1])
		{
			j = j + 1;
		}
		if (temp > a[j])
		{
			break;
		}
		i = j;
		a[(j - 1) / 2] = a[j];
		j = 2 * i + 1;
	}
	a[(j - 1) / 2] = temp;
}
int main()
{
	int a[] = {1, 2, 3, 4, 5, 6};
	int n = sizeof(a) / sizeof(int);

	for (int i = (n - 1) / 2; i >= 0; --i)
		heapify(a, i, n);

	for (int i = 0; i < n; i++)
		cout << a[i] << (i + 1 == n ? "\n" : " ");

	return 0;
}