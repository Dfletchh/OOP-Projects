#include "circle.h"

Circle::Circle(double radius_param)
{
	radius = radius_param;
}

void Circle::set_radius(double radius_param)
{
	radius = radius_param;
}

double Circle::get_radius() const
{
	return radius;
}

double Circle::get_area()
{
	return pi * radius * radius;
}