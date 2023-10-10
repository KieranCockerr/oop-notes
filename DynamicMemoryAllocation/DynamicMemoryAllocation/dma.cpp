#include <iostream>

// new: Allocates storage
// delete: Free storage
// These are operators, similiar to + - * 
// You can delete variables from memory to free space, cleans up memory leaks
// VERY important for game development, always delete to avoid memory leaks

int* allocateInt()
{
	int* p = new int; // Allocating new memory
	return p;

}
int main()
{
	int* mainPointer = allocateInt();
	// assign -1 to the allocated int, dereferancing
	*mainPointer = -1;
	// Delete the memory
	delete mainPointer;
	mainPointer = nullptr;
}