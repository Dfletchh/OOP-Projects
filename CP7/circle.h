#ifndef CIRCLE_H
#define CIRCLE_H

#include "shape.h"

class Circle : public Shape
{
private:
	double radius;
	const double pi = 3.141592653589793;

public:
	Circle(double radius_param);

	void set_radius(double radius_param);
	
	double get_radius() const;

	double get_area();
};

#endif