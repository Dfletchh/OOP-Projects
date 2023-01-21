#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include "Customer.h"

using namespace std;

void create_database(vector<Customer> &vec);

int main() 
{
    int search_id, found_id = 0;
    char ans;
    vector<Customer> customers; // coontainer for customer oobjects

    cout << "Customer Viewer" << endl;

    create_database(customers); // reads in file and creates customer objects

    while (true) {
        bool found = false; // flag

        cout << "\nEnter customer ID: ";
        cin >> search_id;
        cout << endl;

        for (int i = 0; i < customers.size(); i++) // find customer via ID number
        {
            found_id = customers[i].get_customer_id();
            if (found_id == search_id) {
                cout << customers[i].get_first_name() << ' ' << customers[i].get_last_name() << endl;

                string company = customers[i].get_company(); // test if company is stored in object
                if (!company.empty())
                    cout << customers[i].get_company() << endl;
                cout << customers[i].full_address() << endl; // gets the full address of the object
                found = true;
                break;
            } 
        }
        if (!found)
            cout << "No customer with that ID.\n" << endl;

        cout << "Continue? (y/n): ";
        cin >> ans;
        if (ans != 'y')
            break;
    }
    cout << "\nBye!" << endl << endl;

    return 0;
}

void create_database(vector<Customer> &vec) 
{
    ifstream input_file("customers.txt"); // open file
    if (input_file)                       // if opened successfully
    {
        string line, data, first_name, last_name, company_name, street, city, state, zip;
        int cust_id;

        stringstream ss;                  // buffer for string "line"
        getline(input_file, line);        // removes first line of file
        while (getline(input_file, line)) // retrieves each line in file
        {
            int count = 0;
            ss.str(line);                 // replace string stream buffer w/ new_line
            ss.clear();                   // reset string stream error bit

            getline(ss, data, '\t');      // remove first line
            cust_id = stoi(data);         // string to integer conversion
            Customer customer(cust_id);   // cunstruct object with ID

            while (getline(ss, data, '\t')) {
                count++;
                if (count == 1)            // first
                    customer.set_first_name(data);
                else if (count == 2)       // last
                    customer.set_last_name(data);
                else if (count == 3)       // company
                    customer.set_company(data);
                else if (count == 4)       // street
                    customer.set_street(data);
                else if (count == 5)       // city
                    customer.set_city(data);
                else if (count == 6)       // state
                    customer.set_state(data);
                else if (count == 7)       // zip
                    customer.set_postal_code(data);
            }
            vec.push_back(customer);       // add object
        }
        input_file.close();
    } else
        cout << "File error!" << endl;
} 