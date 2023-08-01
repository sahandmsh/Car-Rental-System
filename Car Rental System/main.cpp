#include <iostream>
#include <string>
#include <vector>
#include "Car.hpp"
using namespace std;
class abc_car_rental{
public:
    virtual void add_car(int, std::string, std::string, std::string, int) = 0;
    virtual void show_car_list() = 0;
};


class car_rental:public abc_car_rental{
    vector <car> car_list;
public:
    void add_car(int id, std::string make, std::string model, std::string color, int year){
        car_list.push_back(car(id, make, model, color, year));
    }
    void show_car_list(){
        for (car i:car_list){
            i.print_info();
        }
    }
    
};


int main(){
    car_rental ABC;
    ABC.add_car (1, "Lexus", "ES350", "Burgendy", 2007);
    ABC.add_car (2, "Audi", "Q3", "Burgendy", 2023);
    ABC.show_car_list();
}
