/*
* Auhtor: (Group 6) Dean Fletcher, Vu Le, Philip Lancaster, Aleksei Khvorostov, Tural Hagverdiyev 
* Purpose: This program creates an abstract class Shape that utilizes 
* 		   a virtual member function that get the area of the given shape.
* 		   With use of classes the user can get the area of a circle,
*	       square, or rectangle. 
*/
#include <iostream>

#include "console.h"
#include "circle.h"
#include "rectangle.h"
#include "square.h"

using namespace std;

void c_s_r(char entry) // choice function
{
	switch (entry)
	{
		case 'c':
		{
			double r = console::get_double("Enter radius: ", 0);
			Circle circle(r); // circle object
			cout << "Area: " << circle.get_area() << endl << endl; // gets the area
			break;
		}

		case 's':
		{
			double w = console::get_double("Enter width: ", 0);
			Square square(w); // square object
			cout << "Area: " << square.get_area() << endl << endl; // gets the area
			break;
		}

		case 'r':
		{
			double w = console::get_double("Enter width: ", 0);
			double h = console::get_double("Enter height: ", 0);
			Rectangle rect(w, h); // rectangle object
			cout << "Area: " << rect.get_area() << endl << endl; // gets the area
			break;
		}
	}
}

int main()
{
	char entry;

	cout << "The Area Calculator\n\n";

	do
	{
		// main prompt
		entry = console::get_char("Circle, square, or rectangle? (c/s/r): ", false);

		// validate choice
		while (entry != 'c' && entry != 's' && entry != 'r')
		{
			cout << "Invalid entry!" << endl;
			entry = console::get_char("Circle, square, or rectangle? (c/s/r): ", false);
		}

		// print area
		c_s_r(entry);

		// continue?
		entry = console::get_char("Continue? (y/n): ");

		while (entry != 'n' && entry != 'y')
		{
			cout << "Invalid entry!" << endl;
			entry = console::get_char("Continue? (y/n): ");
		}

	} while (entry == 'y');

	cout << "Bye!" << endl;

	return EXIT_SUCCESS;
}