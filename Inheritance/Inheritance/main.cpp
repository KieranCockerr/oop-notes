#include <iostream>
#include "Cone.h"


int main()
{
	// here we treat the cylinder and circle astype Shape2D
	// The objects are sliced
	// So cylinder and circle that is not in Shape2D is dropped
	Shape2D shapes[] = { Cone(5,5,10,15), Cylinder(4,4,10,15), Circle(2,2,3)};
	
	// Class exercise 1: Print the area of the cylinder above.
	// What is the output? Why?
	// The output is 0 because the cylinder is treated as Shape2d, which does not contain everything that is in cylinder
	std::cout << "Cylinder area: " << shapes[0].area();

	// Class exercise 2: Add a Cone class to the hierarchy.
	// What should be the parent class of Cone? 
	// Create an instance of your Cone and output it's surface area.
	Cone cone(5, 5, 10, 5);
	std::cout << "Cone: Surface area: " << cone.area();

	// Pointer conversions
	// Create a pointer of the base type
	Shape2D* shapePtr;
	// Assign a derived pointer to the base pointer
	shapePtr = &cone; // Implicit conversion of Cone * to Shape2D *
	// The only functions we can see through the base are those defined in Shape 2D e.g.
	shapePtr->area();

}

