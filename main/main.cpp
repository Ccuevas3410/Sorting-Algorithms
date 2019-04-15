// main.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include "Algorithms.h"

#include <iostream>
#include <string>
#include <ctime>
#include <chrono>
#include <fstream>
#include <time.h>


using namespace std;

//	GLOBAL VARIABLES FOR TO PASS TO RECURSIVE FUNCTIONS
int SWAPS = 0;
int COMPARISONS = 0;


int main()
{
	Algorithms obj;
	srand(time(NULL));
	ofstream fileArray("randArray.txt");


	int choice = 0;
	int size = 0;


	cout << "Enter size of the array, 100 or 1000\n";
	cin >> size;

	int *aArray = new int[size];
	int *bArray = new int[size];
	int *cArray = new int[size];
	int *dArray = new int[size];

	if (fileArray)
	{

		fileArray << "UNSORTED ARRAYS" << endl;
		// A) RANDOM ARRAY
		for (int i = 0; i <= size; i++)
		{
			aArray[i] = rand() % size + 1;
			fileArray << aArray[i] << " ";
		}
		fileArray << endl;


		// B) Almost sorted in ascending order(about 90 % of items are in increasing order, 10 % are random)
		for (int i = 0; i <= size; i++)
			if (i <= 900 && size == 1000 || i <= 90 && size == 100)
			{
				bArray[i] = i;
				fileArray << bArray[i] << " ";
			}
			else
			{
				bArray[i] = (rand() % size + 1);
				fileArray << bArray[i] << " ";
			}
		fileArray << endl;


		// C) Almost sorted in descending order(about 90 % of items are in increasing order, 10 % are random)
		for (int i = size; i >= 0; i--)
			if (i >= 100 && size == 1000 || i >= 10 && size == 100)
			{
				cArray[i] = i;
				fileArray << cArray[i] << " ";
			}
			else
			{
				cArray[i] = (rand() % size + 1);
				fileArray << cArray[i] << " ";
			}
		fileArray << endl;

		//D) Array is sorted except for the last 10 %
		for (int i = 0; i <= size; i++)
			if (i <= 900 && size == 1000 || i <= 90 && size == 100)
			{
				dArray[i] = i;
				fileArray << dArray[i] << " ";
			}
			else
			{
				dArray[i] = (rand() % size + 1);
				fileArray << dArray[i] << " ";
			}
	}

	fileArray << endl;
	fileArray << "SORTED ARRAYS " << endl;



	cout << "Choose your algorithm: " << endl;
	cout << "0.Exit\n1.Selection Sort\n2.Insertion Sort\n3.Quick Sort\n4.Merge Sort\n5.Heap sort" << endl;
	cin >> choice;

	switch (choice)
	{

	case 1:

		fileArray << "Selection Sort: " << endl;
		cout << "ARRAY SIZE: " << size << "\n";

		obj.selectionSort(aArray, size);
		for (int i = 0; i < size; i++)
		{
			fileArray << aArray[i] << " ";
		}
		fileArray << endl;
		obj.selectionSort(bArray, size);
		for (int i = 0; i < size; i++)
		{
			fileArray << bArray[i] << " ";
		}
		fileArray << endl;
		obj.selectionSort(cArray, size);
		for (int i = 0; i < size; i++)
		{
			fileArray << cArray[i] << " ";
		}
		fileArray << endl;
		obj.selectionSort(dArray, size);
		for (int i = 0; i < size; i++)
		{
			fileArray << dArray[i] << " ";
		}
		break;



	case 2:
		fileArray << "Insertion Sort: " << endl;

		obj.insertionSort(aArray, size);
		for (int i = 0; i < size; i++)
		{
			fileArray << aArray[i] << " ";
		}
		fileArray << endl;

		obj.insertionSort(bArray, size);
		for (int i = 0; i < size; i++)
		{
			fileArray << bArray[i] << " ";
		}
		fileArray << endl;
		obj.insertionSort(cArray, size);
		for (int i = 0; i < size; i++)
		{
			fileArray << cArray[i] << " ";
		}
		fileArray << endl;

		obj.insertionSort(dArray, size);
		for (int i = 0; i < size; i++)
		{
			fileArray << dArray[i] << " ";
		}
		break;


	case 3:
		fileArray << "Quick Sort: " << endl;
		obj.quickSort(aArray, 0, size - 1, COMPARISONS, SWAPS);

		for (int i = 0; i < size; i++)
		{
			fileArray << aArray[i] << " ";
		}
		cout << "COMPARISONS for Quick Sort: " << COMPARISONS << " , SWAPS for  Quick Sort: " << SWAPS << endl;
		fileArray << endl;

		
		obj.quickSort(bArray, 0, size - 1, COMPARISONS=0, SWAPS=0);
		for (int i = 0; i < size; i++)
		{
			fileArray << bArray[i] << " ";
		}
		cout << "COMPARISONS for Quick Sort: " << COMPARISONS << " , SWAPS for  Quick Sort: " << SWAPS << endl;
		fileArray << endl;


		obj.quickSort(cArray, 0, size - 1, COMPARISONS = 0, SWAPS = 0);
		for (int i = 0; i < size; i++)
		{
			fileArray << cArray[i] << " ";
		}
		cout << "COMPARISONS for Quick Sort: " << COMPARISONS << " , SWAPS for  Quick Sort: " << SWAPS << endl;
		fileArray << endl;

		obj.quickSort(dArray, 0, size - 1, COMPARISONS = 0, SWAPS = 0);
		for (int i = 0; i < size; i++)
		{
			fileArray << dArray[i] << " ";
		}
		cout << "COMPARISONS for Quick Sort: " << COMPARISONS << " , SWAPS for  Quick Sort: " << SWAPS << endl;
		break;

	case 4:

		fileArray << "Merge Sort: " << endl;

		obj.mergeSort(aArray, 0, size, COMPARISONS=0, SWAPS=0);
		for (int i = 0; i < size; i++)
		{
			fileArray << aArray[i] << " ";
		}
		cout << "COMPARISONS for Merge Sort: " << COMPARISONS << " , SWAPS for  Merge Sort: " << SWAPS << endl;
		fileArray << endl;


		obj.mergeSort(bArray, 0, size, COMPARISONS=0, SWAPS=0);
		for (int i = 0; i < size; i++)
		{
			fileArray << bArray[i] << " ";
		}
		cout << "COMPARISONS for Merge Sort: " << COMPARISONS << " , SWAPS for  Merge Sort: " << SWAPS << endl;
		fileArray << endl;

		obj.mergeSort(cArray, 0, size, COMPARISONS=0, SWAPS=0);
		for (int i = 0; i < size; i++)
		{
			fileArray << cArray[i] << " ";
		}
		cout << "COMPARISONS for Merge Sort: " << COMPARISONS << " , SWAPS for  Merge Sort: " << SWAPS << endl;
		fileArray << endl;

		obj.mergeSort(dArray, 0, size, COMPARISONS=0, SWAPS=0);
		for (int i = 0; i < size; i++)
		{
			fileArray << dArray[i] << " ";
		}
		cout << "COMPARISONS for Merge Sort: " << COMPARISONS << " , SWAPS for  Merge Sort: " << SWAPS << endl;
		break;

	case 5:
		fileArray << "Heap Sort: " << endl;

		obj.heapSort(aArray, size, COMPARISONS=0, SWAPS=0);

		for (int i = 0; i < size; i++)
		{
			fileArray << aArray[i] << " ";
		}
		cout << "COMPARISONS for Heap Sort: " << COMPARISONS << " , SWAPS for Heap Sort: " << SWAPS << endl;
		fileArray << endl;

		obj.heapSort(bArray, size, COMPARISONS=0, SWAPS=0);
		for (int i = 0; i < size; i++)
		{
			fileArray << bArray[i] << " ";
		}
		cout << "COMPARISONS for Heap Sort: " << COMPARISONS << " , SWAPS for Heap Sort: " << SWAPS << endl;
		fileArray << endl;

		obj.heapSort(cArray, size, COMPARISONS=0, SWAPS=0);
		for (int i = 0; i < size; i++)
		{
			fileArray << cArray[i] << " ";
		}
		cout << "COMPARISONS for Heap Sort: " << COMPARISONS << " , SWAPS for Heap Sort: " << SWAPS << endl;
		fileArray << endl;

		obj.heapSort(dArray, size, COMPARISONS=0, SWAPS=0);
		for (int i = 0; i < size; i++)
		{
			fileArray << dArray[i] << " ";
		}
		cout << "COMPARISONS for Heap Sort: " << COMPARISONS << " , SWAPS for Heap Sort: " << SWAPS << endl;
		break;

	case 0:
		system("EXIT");
	default:
		break;
	}

}





