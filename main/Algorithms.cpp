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


/**
	Swaps items in Arrays

	@param biggger array item and smaller array item
	@return void function
*/
void Algorithms::swap(int& bigger, int &smaller) {


	int temp = bigger;
	bigger = smaller;
	smaller = temp;
}

/**
	Selection sort Algorithm

	@param pointer to the array and the size
	@return void function
*/
void Algorithms::selectionSort(int *arr, int size) {

	COMPARISONS = 0;
	SWAPS = 0;

	for (int i = 0; i < size - 1; i++)
	{
		int smallest = i;

		for (int j = i + 1; j < size; j++)
		{
			if (arr[j] < arr[smallest]) {
				smallest = j;
				COMPARISONS++;
			}
		}
		swap(arr[smallest], arr[i]);

		SWAPS++;
	}

	cout << "COMPARISONS for Selection Sort: " << COMPARISONS << " , SWAPS for Selection Sort: " << SWAPS << endl;
}

/**
	Insertion sort Algorithm

	@param pointer to the array and the size
	@return void function
*/
void Algorithms::insertionSort(int *arr, int size) {

	COMPARISONS = 0;
	SWAPS = 0;

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
				SWAPS++;

			}
			else
			{

				less = false;
			}
			COMPARISONS++;
		}

	}
	cout << "COMPARISONS for Insertion Sort: " << COMPARISONS << " , SWAPS for Insertion Sort: " << SWAPS << endl;

}

/**
	Merge Sort helper function that combines arrays

	@param pointer to the array and the size
	@return void function
*/
void Algorithms::merge(int *arr, int low, int mid, int mid2, int high, int& countComparisons, int& countSwaps) {

	int *temp = new int[high + 1];
	int i = low;
	int j = mid2;
	int a = 0;



	while (i <= mid && j <= high)
	{
		countComparisons++;
		if (arr[i] < arr[j])
		{
			countComparisons++;
			countSwaps++;

			temp[a] = arr[i];
			i++;
		}
		else
		{
			countComparisons++;
			countSwaps++;
			temp[a] = arr[j];
			j++;
		}
		a++;
	}
	while (i <= mid) {

		countComparisons++;
		countSwaps++;

		temp[a] = arr[i];
		i++;
		a++;
	}
	while (j <= high) {
		countComparisons++;
		countSwaps++;

		temp[a] = arr[j];
		j++;
		a++;
	}
	for (int i = low, a = 0; i <= high; i++, a++) {
		arr[i] = temp[a];
	}
	delete[] temp;


}

/**
	Merge Sort recursive function Algorithm that halves the arrays

	@param pointer to the array and the size
	@return void function
*/
void Algorithms::mergeSort(int *arr, int low, int high, int& countComparisons, int& countSwaps) {


	if (low < high)
	{
		countComparisons++;
		int mid = (low + high - 1) / 2;
		mergeSort(arr, low, mid, countComparisons, countSwaps);
		mergeSort(arr, mid + 1, high, countComparisons, countSwaps);
		merge(arr, low, mid, mid + 1, high, countComparisons, countSwaps);

	}


}
/**
	Quick Sort function that combines arrays and figures out the middle partition to divide them.

	@param pointer to the array and the size
	@return void function
*/
void Algorithms::quickSort(int *arr, int low, int high, int& countComparisons, int& countSwaps) {



	if (low < high)
	{
		int pi = partition(arr, low, high, countComparisons, countSwaps);
		quickSort(arr, low, pi - 1, countComparisons, countSwaps);
		quickSort(arr, pi + 1, high, countComparisons, countSwaps);


	}

}
/**
	Quick Sort helper function that partitions arrays

	@param pointer to the array, low index of array, high index or array, comparisons by reference and swaps by reference.
	@return partition value where both arrays should be halved.
*/
int Algorithms::partition(int *arr, int low, int high, int& countComparisons, int& countSwaps) {



	int pivot = arr[high];
	int pos = low - 1;

	for (int i = low; i <= high - 1; i++)
	{
		if (arr[i] <= pivot)
		{
			pos++;
			SWAPS++;
			swap(arr[pos], arr[i]);

		}
		countComparisons++;
	}

	swap(arr[pos + 1], arr[high]);
	countSwaps++;

	return (pos + 1);

}
/**
	Heap sort recursive function that creates the unorganized Heap and organizes it.

	@param pointer to the array, size of array,  comparisons by reference and swaps by reference.
	@return void function.
*/
void Algorithms::heapSort(int *arr, int size, int& countComparisons, int& countSwaps) {

	countComparisons = 0;
	countSwaps = 0;

	//create heap unordered heap
	for (int i = size / 2 - 1; i >= 0; i--)
	{
		heapDown(arr, size, i, countComparisons, countSwaps);
	}


	//Change largest item with the smallest and remove largest from tree
	for (int i = size - 1; i >= 0; i--)
	{
		swap(arr[0], arr[i]);
		countSwaps++;
		heapDown(arr, i, 0, countComparisons, countSwaps);
	}

}
/**
	Heap sort recursive function similar to heapsort but it assumes part of the array is sorted

	@param pointer to the array, size of array, root of the heap, comparisons by reference and swaps by reference variables.
	@return void function.
*/

void Algorithms::heapDown(int *arr, int size, int root, int& countComparisons, int& countSwaps) {



	int left = (2 * root) + 1;
	int right = (2 * root) + 2;
	int largest = root;

	if (left <  size && arr[left] > arr[largest]) {

		countComparisons++;
		largest = left;


	}
	if (right < size  &&  arr[right]> arr[largest]) {
		countComparisons++;
		largest = right;
	}

	if (largest != root) {
		countComparisons++;
		countSwaps++;

		//Swaps first and last node
		swap(arr[root], arr[largest]);

		//Creates a max heap on reduced array
		heapDown(arr, size, largest, countComparisons, countSwaps);
	}


}

void Algorithms::printArr(int arr[], int size) {

	for (int i = 0; i < size; i++)
	{
		cout << arr[i] << " ";
	}



}