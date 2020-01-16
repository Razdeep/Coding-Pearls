#include <iostream>
#include <vector>
using namespace std;

void maxHeapify(vector<int> &arr, int cur)
{
	int n = (int)arr.size();
	int left = 2 * cur + 1;
	int right = 2 * cur + 2;
	int largest = cur;
	if (left < n && arr[left] > arr[largest])
	{
		largest = left;
	}
	if (right < n && arr[right] > arr[largest])
	{
		largest = right;
	}
	if (largest != cur)
	{
		swap(arr[cur], arr[largest]);
		maxHeapify(arr, largest);
	}
}
void buildMaxHeap(vector<int> &arr)
{
	int n = (int)arr.size();
	for (int i = (n - 1) / 2; i >= 0; --i)
		maxHeapify(arr, i);
}

void minHeapify(vector<int>& arr, int cur)
{
	int n = (int)arr.size();
	int left = 2 * cur + 1;
	int right = 2 * cur + 2;
	int smallest = cur;

	if (left < n && arr[left] < arr[smallest])
		smallest = left;
	
	if (right < n && arr[right] < arr[smallest])
		smallest = right;
	
	if (smallest != cur)
	{
		swap(arr[smallest], arr[cur]);
		minHeapify(arr, smallest);
	}
}
void buildMinHeap(vector<int>& arr)
{
	int n = (int)arr.size();
	for (int i = (n - 1) / 2; i >= 0; --i)
		minHeapify(arr, i);	
}

int main()
{
	int n;
	cout << "Enter the value of n ";
	cin >> n;
	vector<int> arr(n);
	for (int i = 0; i < n; ++i)
		cin >> arr[i];

	buildMaxHeap(arr);
	cout << "Displaying the max heap...\n";
	for (int i = 0; i < int(arr.size()); ++i)
		cout << arr[i] << (i + 1 < n ? " " : "\n");

	buildMinHeap(arr);
	cout << "Displaying the min heap...\n";
	for (int i = 0; i < int(arr.size()); ++i)
		cout << arr[i] << (i + 1 < n ? " " : "\n");

	return 0;
}