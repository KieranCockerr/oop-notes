#pragma once

#include <cmath>
#include "Point2D.h"

class Shape2D 
{
public:
	Shape2D(float t_x, float t_y);

	// Pure virtual function means it does not need to return anything (no definition)
	// Shape2D is now an abstract class, can no longer create an object of type Shape2D
	// Used for making base classes
	// 0 here means null, or no value
	virtual float area() const = 0;

	const static double PI;
private:
	Point2D m_centroid;	// Point2D stores an x,y value
};

