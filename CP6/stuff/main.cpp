#include "Customer.h"
#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>

using namespace std;

void create_database(vector<Customer> &vec);
Customer create_object();

int main() 
{
    int cust_id;
    char ans;
    vector<Customer> customers; 

    cout << "Customer Viewer\n" << endl;

    create_database(customers);

    while (true) {
        cout << "Enter customer ID: ";
        cin >> cust_id;

        for (int i = 0; i < customers.size(); i++)
        {
            cout << "find loop" << endl; // todo
            // find customer object
             // if (found) {
                // cout << get_first() << ' ' << get_last() << enld;
                // cout << get_company() << endl;
                // cout << full_address(std::string) << endl << enld;
                // break;
            //} else
                // cout << "No customer with that ID.\n" << endl;
        }
        cout << "Continue? (y/n): ";
        cin >> ans;
        if (ans != 'y')
            break;
    }
    cout << "Bye!" << endl << endl;

    return 0;
}

void create_database(vector<Customer> &vec) 
{
    ifstream input_file("customers.txt"); // open file
    if (input_file)                       // if opened successfully
    {
        string line, first_name, last_name, company_name, street, city, state, zip;
        int cust_id;

        stringstream ss;                  // buffer for string "line"
        getline(input_file, line);        // removes first line of file
        while (getline(input_file, line)) // retrieves each line in file
        {
            ss.str(line);                 // replace string stream buffer w/ new_line
            ss.clear();                   // reset string stream error bit
            if (ss >> cust_id >> first_name >> last_name >> company_name >> street >> city >> state >> zip) // parse buffer
            {
                Customer customer = create_object(cust_id,first_name,last_name,company_name,street,city,state,zip);
                vec.push_back(customer);
            }
            else if (ss >> cust_id >> first_name >> last_name >> street >> city >> state >> zip) // parse buffer
            {
                Customer customer = create_object(cust_id,first_name,last_name,street,city,state,zip);
                vec.push_back(customer);
            }
        }
        input_file.close();
    } else
        cout << "File error!" << endl;
}

Customer create_object(int id, string first, string last,string company, string street, string city, string state, string zip) {
    Customer customer;
    customer.set_customer_id(id);
    customer.set_first_name(first);
    customer.set_last_name(last);
    customer.set_street(street);
    customer.set_city(city);
    customer.set_state(state);
    customer.set_postal_code(zip);
    customer.set_company(company);
    return customer;
}
Customer create_object(int id, string first, string last, string street, string city, string state, string zip) {
    Customer customer;
    customer.set_customer_id(id);
    customer.set_first_name(first);
    customer.set_last_name(last);
    customer.set_street(street);
    customer.set_city(city);
    customer.set_state(state);
    customer.set_postal_code(zip);
    return customer;
}
