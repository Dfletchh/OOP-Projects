#pragma once
#include <string>
#include <iostream>

class customer
{
private:
	unsigned int id;
	std::string first_name;
	std::string last_name;
	std::string company;
	std::string address;
	std::string city;
	std::string state;
	unsigned int postal_code;
	// Friend functions are not considered part of a class, but still have access to the class's private fields.
	friend std::ostream& operator<<(std::ostream& os, const customer& cust); 
public:
	customer();
	customer(int, std::string, std::string, std::string,
		std::string, std::string, std::string, int);
	unsigned int get_id();
	std::string get_first_name();
	std::string get_last_name();
	std::string get_company();
	std::string get_address();
	std::string get_city();
	std::string get_state();
	unsigned int get_postal_code();

	void set_id(int);
	void set_first_name(std::string);
	void set_last_name(std::string);
	void set_company(std::string);
	void set_address(std::string);
	void set_city(std::string);
	void set_state(std::string);
	void set_postal_code(int);

};