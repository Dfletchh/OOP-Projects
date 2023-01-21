/* 
* Auhtor: CP3 Group 1
* Purpose: 
*/

#include <iostream>
#include <iomanip>
#include "console.h"
//#include "console.cpp"

using namespace std;

void calculate_tax(double sum);

int main()
{
    cout << "Sales Tax Calculator"
         << endl;
    char request = 'y';
    while (tolower(request) == 'y')
    {
        double sum = 0;
        cout << "\nENTER ITEMS (ENTER 0 TO END)" << endl;
        while (true)
        {
            double cost = console::get_double("Cost of item: ", 0, 10000);
            if (cost <= 0)
                break;
            sum += cost;
        }
        cout << "\n";
        calculate_tax(sum);                                  // function call for tax calculation and console output
        request = console::get_char("Again? (y/n): ", true); // loop test
    }
    cout << "Bye!" << endl;
    return 0;
}
void calculate_tax(double sum)
{
    cout << fixed << setprecision(2);
    cout << left << setw(17) << "Total:"
         << right << setw(6) << sum << endl; // total without tax
    cout << left << setw(17) << "Sales tax:"
         << right << setw(6) << console::tax_due(sum) << endl; // sales tax
    cout << left << setw(17) << "Total after tax:"
         << right << setw(6) << console::total_due(sum) << endl
         << endl; // total with tax
}