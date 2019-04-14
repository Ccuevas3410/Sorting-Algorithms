// main.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include "Algorithms.h"
#include "Algorithms.cpp"
#include <iostream>
#include <string>
#include <ctime>
#include <chrono>
#include <fstream>
#include <time.h>


using namespace std;



 
int main()
{
	Algorithms obj;
	srand(time(NULL));
	ofstream fileArray("randArray.txt");

	
	int choice = 0;
	int size = 0;


	cout << "Enter size of the array, 100 or 1000\n";
	cin >> size;

	int *aArray = new int [size];
	int *bArray = new int[size];
	int *cArray = new int[size];
	int *dArray = new int[size];

	if (fileArray)
	{

		fileArray << "UNSORTED ARRAYS" << endl;
		//RANDOM ARRAY
		for (int i = 0; i <= size; i++)
		{
			aArray[i] = rand() % size + 1;
			fileArray << aArray[i] << " ";
		}
		fileArray << endl;


		//Almost sorted in ascending order(about 90 % of items are in increasing order, 10 % are random)
		for (int i = 0; i <= size; i++)
			if (i <= 900)
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

		for (int i = 0; i <= size; i++)
			if (size == 1000 && i <= 900 || size == 100 && i <= 90)
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
			if ((size == 1000 && i <= 900 || size == 100 && i <= 90))
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



	do
	{
		cout << "Choose your algorithm: " << endl;
		cout << "0.Exit\n1.Selection Sort\n2.Insertion Sort\n3.Quick Sort\n4.Merge Sort\n5.Heap sort" << endl;
		cin >> choice;

		switch (choice)
		{

		case 1:

			fileArray << "Selection Sort: " << endl;
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
			obj.quickSort(aArray, 0, size - 1);

			for (int i = 0; i < size; i++)
			{
				fileArray << aArray[i] << " ";
			}
			
		
		
			fileArray << endl;


			obj.quickSort(bArray, 0, size - 1);
			for (int i = 0; i < size; i++)
			{
				fileArray << bArray[i] << " ";
			}
			
			fileArray << endl;


			obj.quickSort(cArray, 0, size - 1);
			for (int i = 0; i < size; i++)
			{
				fileArray << cArray[i] << " ";
			}

			fileArray << endl;

			obj.quickSort(dArray,0, size-1);
			for (int i = 0; i < size; i++)
			{
				fileArray << dArray[i] << " ";
			}
			break;

		case 4:
			obj.selectionSort(aArray, 100);
			obj.selectionSort(bArray, 100);
			obj.selectionSort(cArray, 100);
			obj.selectionSort(dArray, 100);
			break;

		case 0:
			system("EXIT");
		default:
			break;
		}


	} while (choice != 0);











	//WORKS

	//obj.mergeSort(randArr, 0, 9);
	//obj.selectionSort(randArr, 10);
	//obj.insertSort(randArr, 10);


}





