#include <iostream>
#include "Cylinder.h"


int main()
{
	void printArea(Shape2D * t_shape);
	// use typeid to get the object type

	// NB Research at home
	// look up dynamic casts, allows you to access functions that you otherwise would not be able to
	// synamic_cast<Cylinder*>(t_shape); Used with types that are polymorphic

	Circle cl(0, 0, 1);

	// Virtual functions allow you to point them directly at a class
	// 
	// pointer array allows to dynamically create new objects
	// Remember to delete them afterwards
	Shape2D* shapes[] = { new Cylinder(4,4,10,15), new Circle(2,2,3) };
	
	// Static binding
	// Pointer type determines which function is called, early binding
	Shape2D* basePtr = shapes[0];

	// Area is now a polymorphic function call
	// The derived instance (Cylinder) pointer to by nasePtr
	// recieves the function call
	// This is known as dynamic (late) binding
	Cylinder cyl(4, 4, 10, 15);
	basePtr = &cyl;
	std::cout << basePtr->area() << "\n";


}

