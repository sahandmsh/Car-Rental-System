#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include "Car.hpp"
using namespace std;

class Car_Rental{
    map <string , vector<car>> car_list;
    vector <string> rented_cars_id;
public:
    void add_car(string car_type, std::string make, std::string model, std::string color, int year){
        car_list[car_type].push_back(car(car_type+to_string(car_list[car_type].size()+1), make, model, color, year));
    }
    void show_car_list(string id){
        for (auto i:car_list){
            cout<<"\n------------------- CAR Type: "<< i.first << "  ----------------------\n";
            for (auto j:i.second){
                    j.print_info();
            }
        }
    }
    void customer_request(){
        show_car_list("NA");
        int id;
        cout<< "**Please enter the vehicle number from the list**";
        cin>> id;
//        if (find(rented_cars_id.begin(),rented_cars_id.end(),id)==rented_cars_id.end()){}
        
    }
};


int main(){
    Car_Rental ABC;
    ABC.add_car ("S", "Lexus", "ES350", "Burgendy", 2007);
    ABC.add_car ("C", "Kia", "Forte", "Grey", 2022);
    ABC.add_car ("C", "Toyota", "Corolla", "Blue", 2022);
    ABC.show_car_list("NA");
    
    string a,b;
}
