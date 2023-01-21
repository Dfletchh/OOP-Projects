#include "square.h"

Square::Square(double width_param)
{
	width = width_param;
}

void Square::set_width(double width_param)
{
	width = width_param;
}

double Square::get_width() const
{
	return width;
}

double Square::get_area()
{
	return width * width;
}