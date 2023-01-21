#ifndef CUSTOMER_H
#define CUSTOMER_H



#include <string>
#include <vector>

class Customer {

private:
    int customer_id;
    std::string postal_code;
    std::string first_name;
    std::string last_name;
    std::string street;
    std::string city;
    std::string state;
    std::string customers_company;
    std::vector<std::string> vec;
    std::string address;
public:
    Customer(int id_param);
    std::string full_address();

    std::string get_first_name();
    std::string get_last_name();
    std::string get_company();
    std::string get_street();
    std::string get_city();
    std::string get_state();
    std::string get_postal_code();
    int get_customer_id();

    void set_first_name(std::string);
    void set_last_name(std::string);
    void set_company(std::string);
    void set_street(std::string);
    void set_city(std::string);
    void set_state(std::string);
    void set_postal_code(std::string);
    void set_customer_id(int);
};

#endif