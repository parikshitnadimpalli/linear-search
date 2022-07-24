#include <iostream>
#include <limits>
#include <new>
using namespace std;

int integerInput();
int getSize();
int* linearSearch(int, int, int[]);

int main()
{
	int size, *arr;

	cout << "Enter the size of the array: ";
	size = getSize();
	arr = new (nothrow) int[size];
	if (arr == nullptr)
	{
		cout << endl << "Failed to allocate memory! Please restart the application.";
		exit(0);
	}

	cout << endl << "Enter all the elements of the array: ";
	for (int i = 0; i < size; i++)
	{
		arr[i] = integerInput();
		cout << "Elements remaining to be entered: " << size - i - 1 << endl;
	}

	int* d = linearSearch(integerInput(), size, arr);
	if (d == nullptr)
		cout << endl << "Given data not found!";
	else
		cout << endl << "Data found at memory address: " << d;
	
	return 0;
}

int integerInput()
{
	int n;

	while (!(cin >> n))
	{
		cin.clear();
		cin.ignore(numeric_limits <streamsize>::max(), '\n');
		cout << endl << "Invalid integer input! Please try again with correct input: ";
	}

	return n;
}

int getSize()
{
	int size = integerInput();

	if (size <= 0)
	{
		cout << endl << "Invalid size! Please try again: ";
		size = getSize();
	}

	return size;
}

int* linearSearch(int data, int size, int arr[])
{
	for (int i = 0; i < size; i++)
	{
		if (arr[i] == data)
			return &arr[i];
	}

	return nullptr;
}