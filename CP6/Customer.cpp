#include <string>
#include "Customer.h"

Customer::Customer(int id_param) {
    customer_id = id_param;
}
// Member Function //
std::string Customer::full_address() {
    std::string address = street + '\n' + city + ", " + state + ' ' + postal_code + '\n';
    // std::string str1, std::string str2, std::string str3, std::string str4
    //std::string address = str1 + '\n'+ str2 + ' ' + str3 + ' ' + str4 + '\n';
    return address;
}
// Getters and Setters //
int Customer::get_customer_id() {
    return customer_id;
}
std::string Customer::get_first_name() {
    return first_name;
}
std::string Customer::get_last_name() {
    return last_name;
}
std::string Customer::get_company() {
    return customers_company;
}
std::string Customer::get_street() {
    return street;
}
std::string Customer::get_city() {
    return city;
}
std::string Customer::get_state() {
    return state;
}
std::string Customer::get_postal_code() {
    return postal_code;
}
void Customer::set_customer_id(int id_param) {
    customer_id = id_param;
}
void Customer::set_first_name (std::string first_name_param) {
    first_name = first_name_param;
}
void Customer::set_last_name (std::string last_name_param) {
    last_name = last_name_param;
}
void Customer::set_company (std::string company_param) {
    customers_company = company_param;
}
void Customer::set_street (std::string street_param) {
    street = street_param;
}
void Customer::set_city (std::string city_param) {
    city = city_param;
}
void Customer::set_state (std::string state_param) {
    state = state_param;
}
void Customer::set_postal_code (std::string postal_code_param) {
    postal_code = postal_code_param;
}