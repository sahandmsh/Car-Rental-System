#include "Car.hpp"

car::car(std::string id, std::string make, std::string model, std::string color, int year):
id(id), make (make), model(model), color(color), year(year){}

void car::print_info(){
    std::cout<<id<<") "<<make<< "  "<< model<< "  "<< year<< "  "<< color<<"\n";
//    std::cout<<"-------------------------------------------------------\n";
    
}

// defined for the case that car is used as a map key as the (ordered) map needs the operator < to compare and sort keys!
bool car::operator<(const car& c) const
    {
        return (this->id < c.id);
    }
