#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <utility>
#include <ctime>
#include "Car.hpp"
#include "Car_Rental.hpp"
#include <sstream>
using namespace std;







int main(){
    Car_Rental ABC; //creating ABC car rental object
    ABC.add_car ("M", "Lexus", "ES350", "Red", 2021);
    ABC.add_car ("F", "Toyota", "Avalon", "White", 2023);
    ABC.add_car ("M", "Honda", "Accord", "Silver", 2022);
    ABC.add_car ("M", "Acura", "TLX", "Black", 2023);
    ABC.add_car ("C", "Hyundai", "Elantra", "Blue", 2022);
    ABC.add_car ("C", "Tesla", "Model3", "White", 2021);
    ABC.add_car ("C", "Tesla", "Model3", "Black", 2022);
    ABC.add_car ("M", "Hyundai", "Sonata", "red", 2022);
    ABC.add_car ("C", "Toyota", "Corolla", "Silver", 2020);
    ABC.add_car ("M", "Toyota", "Camry", "Blue", 2022);
    ABC.add_car ("T", "Toyota", "Tacoma", "Grey", 2022);
    ABC.add_car ("T", "Ford", "F150", "White", 2022);
    ABC.add_car ("T", "Ford", "F150", "Black", 2022);
    ABC.add_car ("M", "Kia", "K5", "Grey", 2023);
    ABC.add_car ("S", "Nissan", "Rogue", "red", 2020);
    ABC.add_car ("S", "Toyota", "Rav4", "Brown", 2023);
    ABC.add_car ("F", "Nissan", "Maxima", "Blue", 2023);
    ABC.customer_request();// getting a request from customer
    //(from/to date, and desired car from available car list)
}
