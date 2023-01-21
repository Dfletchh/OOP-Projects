#ifndef RECTANGLE_H
#define RECTANGLE_H

#include "square.h"

class Rectangle : public Square // inherits square
{
private:
	double height;

public:
	Rectangle(double width, double height_param);
	
	void set_height(double height_param);
	
	double get_height() const;
	
	double get_area();
};

#endif