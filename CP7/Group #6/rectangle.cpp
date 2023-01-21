#include "rectangle.h"

Rectangle::Rectangle(double width, double height_param) : Square(width) // inherits square
{
	height = height_param;
}

void Rectangle::set_height(double height_param)
{
	height = height_param;
}

double Rectangle::get_height() const
{
	return height;
}

double Rectangle::get_area()
{
	return width * height;
}