#include "Circle.h"

Circle::Circle(float t_x, float t_y, float t_radius) :
	Shape2D(t_x, t_y),
	m_radius(t_radius) {
	// Constructor body is empty.
}
// This is an example of function overriding
float Circle::area() const {
	return PI * m_radius * m_radius;
}

float Circle::radius() const {
	return m_radius;
}
