// ch9sortingBenchmarks.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

// Function prototypes
void displayArray(int[], int);
void bubbleSort(int[], int);
void selectionSort(int[], int);
int exchanges;
int main()
{
    std::cout << "Chapter 9 Sorting Benchmarks by Kevin Bell\n\n";

	// generate random numbers
	const int SIZE = 25;
	int numbers[SIZE];
	for (int i = 0; i < SIZE; i++)
	{
		numbers[i] = rand() % 100;
	} // end for loop

	//unsorted array of 25 elements of random numbers in the range 1-500
	cout << "Unsorted array: \n";
	displayArray(numbers, SIZE);

	//bubble sorted array of 25 elements of random numbers in the range 1-500
	//bubble sort made X amount of exchanges
	cout << "Bubble sorted array: \n";
	displayArray(numbers, SIZE);
	bubbleSort(numbers, SIZE);
	cout << endl;
	//selection sorted array of 25 elements of random numbers in the range 1-500
	//selection sort made X amount of exchanges
	cout << "Selection sorted array: \n";
	displayArray(numbers, SIZE);
	selectionSort(numbers, SIZE);

	system("pause");
	return 0;
} // end main

// functions
//display contents of array with 5 elements per line
void displayArray(int array[], int size)
{
	for (int i = 0; i < size; i++)
	{
		cout << array[i] << " ";
		if ((i + 1) % 5 == 0)
			cout << endl;
	}
	cout << endl;
} // end displayArray

//bubble sort in ascending order, counting number of exchanges
void bubbleSort(int array[], int size)
{
	int temp;
	int exchanges = 0;
	bool swap;
	do
	{
		swap = false;
		for (int count = 0; count < (size - 1); count++)
		{
			if (array[count] > array[count + 1])
			{
				temp = array[count];
				array[count] = array[count + 1];
				array[count + 1] = temp;
				swap = true;
				exchanges++;
			} // end if
		} // end for
	} while (swap);
	cout << "Bubble sort made " << exchanges << " exchanges." << endl;
} // end bubbleSort

//selection sort in ascending order, counting number of exchanges
void selectionSort(int array[], int size)
{
	int startScan, minIndex, minValue;
	int exchanges = 0;
	for (startScan = 0; startScan < (size - 1); startScan++)
	{
		minIndex = startScan;
		minValue = array[startScan];
		for (int index = startScan + 1; index < size; index++)
		{
			if (array[index] < minValue)
			{
				minValue = array[index];
				minIndex = index;
			} // end if
		} // end for
		array[minIndex] = array[startScan];
		array[startScan] = minValue;
		exchanges++;
	} // end for
	cout << "Selection sort made " << exchanges << " exchanges." << endl;
} // end selectionSort