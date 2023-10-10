#include <iostream>
#include "Collectible.h"

using namespace std;

int* generate(int t_howmany)
{
	int* arr = new int[t_howmany]; //new array

	// loop through array
	for (int i = 0; i < t_howmany; i++)
	{
		arr[i] = (rand() % 100) + 1;
	}

	return arr; // return to main
}

int main()
{
	int* arr = generate(10); // call function

	for (int i = 0; i < 10; i++)
	{
		cout << arr[i] << "\n";
	}

	delete[] arr;


}

// ~Collectible()
// This is a destructor funtion, which is called when an object is deleted from memory