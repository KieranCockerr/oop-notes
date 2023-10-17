#pragma once

#include <cmath>
#include "Point2D.h"

class Shape2D 
{
public:
	Shape2D(float t_x, float t_y);
	float area() const;

	const static double PI;
private:
	Point2D m_centroid;	// Point2D stores an x,y value
};

