#pragma once
#include "Circle.h"

class Cylinder : public Circle { // cylinder is part of circle, radius is stored in circle
public:
	Cylinder(float t_x, float t_y, float t_height, float t_radius);

	float radius() const;
	float area() const;
	float volume() const;

private:
	float m_height;

};

