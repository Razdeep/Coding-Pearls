/**
 * Deletion in heap
 * 
 */
#include <iostream>
#include <vector>
using namespace std;

void heapify(vector<int> &a, int i)
{
	int n = int(a.size());
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
// @TODO
void shiftUp(vector<int> &a, int k)
{
	
}
// @TODO
void deleteMax(vector<int> &a)
{
	a[0] = a[a.size() - 1];
	a.pop_back();
}
int main()
{
	vector<int> a = {1, 2, 3, 4, 5, 6};
	int n = 6;

	for (int i = (n - 1) / 2; i >= 0; --i)
		heapify(a, i);

	cout << "Displaying the heap...\n";
	for (int i = 0; i < n; i++)
		cout << a[i] << (i + 1 == n ? "\n" : " ");

	deleteMax(a);
	cout << "Displaying heap after deletion\n";
	for (int i = 0; i < n; i++)
		cout << a[i] << (i + 1 == n ? "\n" : " ");

	return 0;
}