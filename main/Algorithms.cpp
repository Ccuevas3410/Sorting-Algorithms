#include "pch.h"
#include "Algorithms.h"
#include <iostream>
#include <string>

using namespace std;


Algorithms::Algorithms()
{

}


Algorithms::~Algorithms()
{
}

void Algorithms::swap(int
	&bigger, int &smaller) {


	int temp = bigger;
	bigger = smaller;
	smaller = temp;
}

void Algorithms::selectionSort(int *arr, int size) {

  comparisons = 0;
	swaps = 0;

	for (int i = 0; i < size - 1; i++)
	{
		int smallest = i;

		for (int j = i + 1; j < size; j++)
		{
			if (arr[j] < arr[smallest]) {
				smallest = j;
				comparisons++;
			}
		}
		swap(arr[smallest], arr[i]);
		swaps++;
	}
	cout << "\n";
	cout << "COMPARISONS for Selection Sort: " << comparisons << " , SWAPS for Selection Sort: " << swaps << endl;
}


void Algorithms::insertionSort(int *arr, int size) {


	bool less;
	int j = 0;

	for (int i = 1; i < size; i++)
	{
		j = i;
		less = true;
		while (j > 0 && less)
		{

			if (arr[j] < arr[j - 1])
			{

				swap(arr[j - 1], arr[j]);
				j--;
				swaps++;

			}
			else
			{

				less = false;
			}
			comparisons++;
		}

	}
	cout << "COMPARISONS for Insertion Sort: " << comparisons << " , SWAPS for Insertion Sort: " << swaps << endl;
}

void Algorithms::merge(int *arr, int low, int mid, int mid2, int high) {

	int *temp = new int[high + 1];
	int i = low;
	int j = mid2;
	int a = 0;


	while (i <= mid && j <= high)
	{
		comparisons++;
		if (arr[i] < arr[j])
		{
			comparisons++;
			swaps++;

			temp[a] = arr[i];
			i++;
		}
		else
		{
			comparisons++;
			swaps++;
			temp[a] = arr[j];
			j++;
		}
		a++;
	}
	while (i <= mid) {

		comparisons++;
		swaps++;

		temp[a] = arr[i];
		i++;
		a++;
	}
	while (j <= high) {
		comparisons++;
		swaps++;

		temp[a] = arr[j];
		j++;
		a++;
	}
	for (int i = low, a = 0; i <= high; i++, a++) {
		arr[i] = temp[a];
	}
	delete[] temp;


}

void Algorithms::mergeSort(int *arr, int low, int high) {
	comparisons = 0;
	swaps = 0;

	if (low < high)
	{
		comparisons++;
		int mid = (low + high - 1) / 2;
		mergeSort(arr, low, mid);
		mergeSort(arr, mid + 1, high);
		merge(arr, low, mid, mid + 1, high);

	}
	else
	{
		cout << "comparisons for merge sort: " << comparisons << " , swaps for merge sort: " << swaps << endl;
	}

}

void Algorithms::quickSort(int *arr, int low, int high) {

	comparisons = 0;
	swaps = 0;

	if (low < high)
	{
		int pi = partition(arr, low, high);
		quickSort(arr, low, pi - 1);
		quickSort(arr, pi + 1, high);

	
}
}

int Algorithms::partition(int *arr, int low, int high) {

	

	int pivot = arr[high];
	int pos = low - 1;

	for (int i = low; i <=	high - 1; i++)
	{
		if (arr[i] <= pivot)
		{
			pos++;
			swaps++;
			swap(arr[pos], arr[i]);

		}
		comparisons++;
	}

	swap(arr[pos + 1], arr[high]);
	swaps++;
	return (pos + 1);
}

void Algorithms::heapSort(int arr[], int size) {
	//create heap, rearrange array
	for (int i = size / 2 - 1; i >= 0; i--)
	{
		heapDown(arr, size, i);
	}

	for (int i = size - 1; i >= 0; i--)
	{
		swap(arr[0], arr[i]);

		heapDown(arr, i, 0);
	}

	cout << "SWAPS = " << swaps << "COMPARISONS = " << comparisons;

}

void Algorithms::heapDown(int arr[], int size, int root) {

	comparisons = 0;
	swaps = 0;

	int left = (2 * root) + 1;
	int right = (2 * root) + 2;
	int largest = root;

	if (left <  size && arr[left] > arr[largest]) {

		comparisons++;
		largest = left;
	
		
	}
	if (right < size  &&  arr[right]> arr[largest]) {
		comparisons++;
		largest = right;
	}

		if (largest != root) {
			comparisons++;
			swaps++;
			swap(arr[root], arr[largest]);
			heapDown(arr, size, largest);
		}


	}

void Algorithms::printArr(int arr[], int size) {

	for (int i = 0; i < size; i++)
	{
		cout << arr[i] << " ";
	}



}