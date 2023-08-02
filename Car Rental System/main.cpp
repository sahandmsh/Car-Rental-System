#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <utility>
#include "Car.hpp"
using namespace std;

class Car_Rental{
    map < string , vector<car> > car_list;
    map < car , vector<pair<int,int>> > reserved_car;
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
    int convert_date (string s_date){
        int s=0;
        s = stoi(string (s_date.begin()+6,s_date.end()));
        s = s*100 + stoi(string (s_date.begin(),s_date.begin()+2));
        s = s*100 + stoi(string (s_date.begin()+3,s_date.begin()+5));
        return s;
    }
    void customer_request(){
        pair <int , int> d;
        d = get_customer_dates();
        while (d.first>=d.second){
            cout<< "Invalid entries! Please enter valid dates!\n";
            d = get_customer_dates();
        }
        cout<<"Available cars for the selected time slot:\n";
    }
    pair <int, int> get_customer_dates(){
        string s,e;
        cout<<"Please enter your desired start date in the format mm/dd/yyyy (e.g., 01/12/2023)   ";
        cin>>s;
        cout<<"Please enter your desired end date in the format mm/dd/yyyy   (e.g., 01/15/2023)   ";
        cin>>e;
        return make_pair (convert_date(s) , convert_date(e));
    }
};


int main(){
    Car_Rental ABC;
    ABC.add_car ("S", "Lexus", "ES350", "Burgendy", 2007);
    ABC.add_car ("C", "Kia", "Forte", "Grey", 2022);
    ABC.add_car ("C", "Toyota", "Corolla", "Blue", 2022);
    ABC.show_car_list("NA");
//    ABC.customer_request();
}
