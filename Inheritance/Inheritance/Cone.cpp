#include "Cone.h"

Cone::Cone(float t_x, float t_y, float t_radius, float t_height) :
	Cylinder(t_x, t_y, t_height, t_radius),
	m_height(t_height)
{
	// Empty body
}

float Cone::radius() const
{
	return Circle::radius(); // return radius of cylinder
}

float Cone::area() const
{
	return (2 * Circle::area() + 2 * Shape2D::PI * radius()
		* m_height);
}

float Cone::volume() const
{
	return Shape2D::PI * Circle::radius() * (Circle::radius() + sqrt(m_height * m_height + Circle::radius() * Circle::radius()));
}


