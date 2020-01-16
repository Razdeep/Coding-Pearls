/**
 * Insertion in heap
 * 
 */
#include <iostream>
#define MAX 100
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

int parent(int i)
{
	return (i - 1) / 2;
}
void shiftUp(int a[], int k)
{
	while (k > 0 && a[k] > a[parent(k)])
	{
		swap(a[k], a[parent(k)]);
		k = parent(k);
	}
}
void insertKey(int a[], int key, int &n)
{
	n++;
	a[n - 1] = key;
	shiftUp(a, n - 1);
}
int main()
{
	int a[MAX] = {1, 2, 3, 4, 5, 6};
	int n = 6;

	for (int i = (n - 1) / 2; i >= 0; --i)
		heapify(a, i, n);

	cout << "Displaying the heap...\n";
	for (int i = 0; i < n; i++)
		cout << a[i] << (i + 1 == n ? "\n" : " ");

	insertKey(a, 20, n);
	cout << "Displaying heap after insertion\n";
	for (int i = 0; i < n; i++)
		cout << a[i] << (i + 1 == n ? "\n" : " ");

	return 0;
}