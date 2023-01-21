#ifndef SQUARE_H
#define SQUARE_H

#include "shape.h"

class Square : public Shape // // inherits shape
{
protected:
	double width;

public:
	Square(double width_param);

	void set_width(double width_param);

	double get_width() const;

	double get_area();
};

#endif