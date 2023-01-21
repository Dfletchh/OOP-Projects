#include "customer.h"

// Initializes all fields as blank or 0
customer::customer()
{
	id = 0;
	first_name = "";
	last_name = "";
	company = "";
	address = "";
	city = "";
	state = "";
	postal_code = 0;
}

// Initializes a customer object using passed fields
customer::customer(int id, 
	std::string first_name, 
	std::string last_name,
	std::string company, 
	std::string address, 
	std::string city, 
	std::string state, 
	int postal_code)
{
	// Shadowing field names in constructors and setters and resolving using "this" is common in Java.
	// No idea if people do it in C++, though.
	this->id = id;
	this->first_name = first_name;
	this->last_name = last_name;
	this->company = company;
	this->address = address;
	this->city = city;
	this->state = state;
	this->postal_code = postal_code;
}

// Getters
unsigned int customer::get_id() { return id; }
std::string customer::get_first_name() { return first_name; }
std::string customer::get_last_name() { return last_name; }
std::string customer::get_company() { return company; }
std::string customer::get_address() { return address; }
std::string customer::get_city() { return city; }
std::string customer::get_state() { return state; }
unsigned int customer::get_postal_code() { return postal_code; }

// Setters
void customer::set_id(int id) { this->id = id; }
void customer::set_first_name(std::string first_name) { this->first_name = first_name; }
void customer::set_last_name(std::string last_name) { this->last_name = last_name; }
void customer::set_company(std::string company) { this->company = company; }
void customer::set_address(std::string address) { this->address = address; }
void customer::set_city(std::string city) { this->city = city; }
void customer::set_state(std::string state) { this->state = state; }
void customer::set_postal_code(int postal_code) { this->postal_code = postal_code; }

// Overload of << operator for customer objects - this allows us to print the customer lines only using cout << (customer)
std::ostream& operator<<(std::ostream& os, const customer& cust)
{
	if (cust.company == "") 
		return (os << cust.first_name << " " << cust.last_name << std::endl <<
		cust.address << std::endl <<
		cust.city << ", " << cust.state << " " << cust.postal_code
		);
	else 
		return (os << cust.first_name << " " << cust.last_name << std::endl <<
		cust.address << std::endl <<
		cust.company << std::endl <<
		cust.city << ", " << cust.state << " " << cust.postal_code
		);
}