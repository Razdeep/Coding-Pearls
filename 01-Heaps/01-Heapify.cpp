/**
 * Implement heapify
 * 
 */
#include <iostream>
#include <vector>

using namespace std;

void heapify(vector<int>& arr, int start)
{
	int n 		= int(arr.size());

	int largest	= start;
	int left 	= (2 * start) + 1;
	int right 	= (2 * start) + 2;

	if (left < n && arr[left] > arr[largest])
	{
		largest = left;
	}

	if (right < n && arr[right] > arr[largest])
	{
		largest = right;
	}

	if (largest != start)
	{
		swap(arr[start], arr[largest]);
		heapify(arr, largest);
	}
}

int main()
{
	int n;
	cout << "Enter the number of elements of heap: ";
	cin >> n;

	vector<int> arr(n);
	for (int i = 0; i < n; ++i)
		cin >> arr[i];
	heapify(arr, 0);
	
	cout << "\nDisplaying heapified array...\n";
	for (auto &it: arr)
		cout << it << " ";
	cout << endl;

	return 0;
}