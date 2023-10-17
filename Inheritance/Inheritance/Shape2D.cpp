#include "Shape2D.h"

const double Shape2D::PI = acos(-1.0);

Shape2D::Shape2D(float t_x, float t_y) : m_centroid(t_x, t_y)
{

}

float Shape2D::area() const
{
	return 0;
}
