#pragma once

#include "Shape2D.h"

class Circle : public Shape2D {
public:
	Circle(float t_x, float t_y, float t_radius);

	// Compiler checks if you have overridden an inherited function
	// Use it in subclasses to call any abstract functions from the base class
	// Only applies to virtual functions
	virtual float area() const override;
	float radius() const;

private:
	float m_radius;
};

