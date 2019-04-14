#pragma once


//	GLOBAL VARIABLES  TO PASS TO RECURSIVE FUNCTIONS
extern int SWAPS;
extern int COMPARISONS;

class Algorithms
{



public:
	Algorithms();
	~Algorithms();


	void swap(int &, int &);

	void selectionSort(int*, int);
	void insertionSort(int*, int);

	void mergeSort(int *, int, int, int&, int&);
	void merge(int*, int, int, int, int, int&, int&);

	void quickSort(int*, int, int, int&, int&);
	int partition(int*, int, int, int&, int&);

	void heapSort(int*, int, int&, int&);
	void heapDown(int*, int, int, int&, int&);

	void printArr(int[], int);



};

