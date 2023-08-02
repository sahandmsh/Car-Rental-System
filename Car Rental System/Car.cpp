#include "Car.hpp"

car::car(std::string id, std::string make, std::string model, std::string color, int year):
id(id), make (make), model(model), color(color), year(year){}

car::car(std::string make, std::string model, std::string color, int year):
id("-NA"), make (make), model(model), color(color), year(year){}

void car::print_info(){
    std::cout<<id<<") "<<make<< "  "<< model<< "  "<< year<< "  "<< color<<"\n";
//    std::cout<<"-------------------------------------------------------\n";
    
}
