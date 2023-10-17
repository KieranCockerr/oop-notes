#pragma once

#include "Cylinder.h"

class Cone : public Cylinder
{
public: 
	Cone(float t_x, float t_y, float t_radius, float t_height);

	  float radius() const;
	  float area() const;
	  float volume() const;

private:
	float m_height;
};

