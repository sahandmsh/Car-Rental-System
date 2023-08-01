#include "Car.hpp"

car::car(int id, std::string make, std::string model, std::string color, int year):
id(id), make (make), model(model), color(color), year(year){}

car::car(std::string make, std::string model, std::string color, int year):
id(-1), make (make), model(model), color(color), year(year){}

void car::print_info(){
    std::cout<<"------------------ CAR ID: "<< id << "  -------------------------\n";
    std::cout<<"Make: "<< make<< ", Model: "<< model<< ", Year: "<< year<< ", Color: "<< color<<"\n";
    std::cout<<"-------------------------------------------------------\n";
    
}
