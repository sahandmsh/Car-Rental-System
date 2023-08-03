#ifndef Car_Rental_hpp
#define Car_Rental_hpp

#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <utility>
#include <ctime>
#include <sstream>
#include "Car.hpp"
//using namespace std;

class Car_Rental{
    std::map < std::string , std::vector<car> > car_list;
    std::vector <std::string> car_id_list;
    std::map < std::string , std::vector<std::pair<int,int>> > reserved_cars;
    std::map <char , float> car_price;
    void make_invoice(std::string, std::pair <int , int>);
    bool available_for_rent(std::string, std::pair <int,int>);
    bool check_leap_year(int);
    bool valid_date(int);
    int convert_date (std::string);
    long calculate_days(int);
    float cost_calculator(char, int);
    std::pair <int, int> get_customer_dates();
    void show_car_list(std::pair <int,int>);
public:
    Car_Rental();
    void add_car(std::string, std::string, std::string, std::string, int);
    void customer_request();
};

#endif /* Car_Rental_hpp */
