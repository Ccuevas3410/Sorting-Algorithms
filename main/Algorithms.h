#pragma once



class Algorithms
{

	
	
public:
	Algorithms();
	~Algorithms();


	void swap(int &, int &);

	void selectionSort(int*, int);
	void insertionSort(int*,int);

	void mergeSort(int *, int , int);
	void merge(int*, int, int, int , int);

	void quickSort(int*, int, int);
	int partition(int*, int, int);

	void heapSort(int[], int);
	void heapDown(int[], int, int);

	void printArr(int [], int);

	int swaps = 0;
	int comparisons = 0;


};

