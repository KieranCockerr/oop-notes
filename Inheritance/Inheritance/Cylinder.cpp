#include "Cylinder.h"

Cylinder::Cylinder(float t_x, float t_y, float t_height, float t_radius) :
	Circle(t_x, t_y, t_radius), // paired constructor
	m_height(t_height)
{
	// Empty body
}

float Cylinder::radius() const {
	return Circle::radius(); // return radius of circle
}

float Cylinder::area() const {
	return (2 * Circle::area() + 2 * Shape2D::PI * radius()
		* m_height);
}

float Cylinder::volume() const {
	return (Circle::area() * m_height);
}
