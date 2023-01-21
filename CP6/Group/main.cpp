#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <algorithm>
#include <exception>
#include "customer.h"

using namespace std;

int get_id_input();
vector<customer> read_customers(string);
bool ask_to_continue();

int main() 
{
	cout << "Customer viewer" << endl << endl;

	do
	{
		int id_to_find;
		vector<customer> customers = read_customers("customers.txt");

		id_to_find = get_id_input();

		// Lambda function to find customer that matches entered id - all customers have unique ids
		auto it = find_if(customers.begin(), customers.end(), [id_to_find](customer this_customer) {
				return this_customer.get_id() == id_to_find;
			});

		cout << endl;
		// If we reached the end of the vector without finding a customer with the id we want, it doesn't exist.
		if (it == customers.end()) cout << "Customer not found";
		else cout << *it;
		cout << endl << endl;
	} while (ask_to_continue());

	// Runs once user enters n
	cout << endl << "Bye!";
}

// Prompts the user to input the id of the customer they would like to display.
// Returns the user's input as an integer.
// The function will not return until the user enters a positive integer.
int get_id_input() 
{
	string input;
	int result;
	stringstream ss;

	ss.clear();
	string message = "Enter customer ID : ";
	do 
	{
		ss.clear();
		cout << message;
		message = "Invalid input. Enter customer ID : ";
		cin >> input;
		ss.str(input);

		if (ss >> result) continue;
		else result = -1;

	} while (result < 0);

	return result;
}

// Attempts to generate a vector of customer objects and populate it using the passed file name.
// Returns a vector containing the customer objects generated using the information from the file.
// Throws a generic exception if the file cannot be successfully read from or opened, or if
// any of the customer fields cannot be successfully read.
vector<customer> read_customers(string file_name) 
{
	vector<customer> result;
	int id;
	string first_name;
	string last_name;
	string company;
	string address;
	string city;
	string state;
	int postal_code;
	string current_line;
	stringstream ss;

	ifstream input_file(file_name);
	// Check if file is readable
	if (input_file.bad() || !input_file.is_open()) { throw new exception(); }

	// Ignore first line - it is column headers
	getline(input_file, current_line);
	// Iterate over each line in the file
	while (getline(input_file, current_line))
	{
		ss.clear(); // Clear stringstream state flags
		ss.str(current_line);
		if (!(ss >> id >> first_name >> last_name)) throw new exception(); // id and name can be read fairly easily
		// The >> operator leaves the stream on the \t character. It has to be skipped before we read with getline
		getline(ss, company, '\t'); 
		// These values can be multiple words, so we read them with getline up to the next \t character
		if(!getline(ss, company, '\t')) throw new exception();
		if(!getline(ss, address, '\t')) throw new exception();
		if(!getline(ss, city, '\t')) throw new exception();
		// state and postal code shouldn't contain whitespaces
		if (!(ss >> state >> postal_code)) throw new exception();
		
		// Add new customer object to vector
		result.push_back(customer(id, first_name, last_name, company, address, city, state, postal_code));
	}

	return result;
}

// Prompt the user to indicate whether or not they'd like to continue.
// Returns true if the user inputs y, false if the user inputs n.
// The function will not return until either y or n is input.
bool ask_to_continue()
{
	string message = "Continue? (y/n): ";
	char input;
	do
	{
		cout << message;
		message = "Invalid input. Continue? (y/n): ";
		cin >> input;

		if (input == 'y') return true;
		else if (input == 'n') return false;

	} while (input != 'y' && input != 'n');

	return NULL; // So the compiler shuts up
}