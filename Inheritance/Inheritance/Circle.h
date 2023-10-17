#pragma once

#include "Shape2D.h"

class Circle : public Shape2D {
public:
	Circle(float t_x, float t_y, float t_radius);

	float area() const;
	float radius() const;

private:
	float m_radius;
};

