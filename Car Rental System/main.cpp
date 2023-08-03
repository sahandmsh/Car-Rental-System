#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <utility>
#include <ctime>
#include "Car.hpp"
using namespace std;

class Car_Rental{
    map < string , vector<car> > car_list;
    vector <string> car_id_list;
    map < string , vector<pair<int,int>> > reserved_cars;
    map <char , float> car_price;
public:
    Car_Rental(){
        car_price['C'] = 30.5;
        car_price['M'] = 45;
        car_price['F'] = 60;
        car_price['S'] = 63;
        car_price['T'] = 70.3;
    }
    void add_car(string car_type, std::string make, std::string model, std::string color, int year){
        car_list[car_type].push_back(car(car_type+to_string(car_list[car_type].size()+1), make, model, color, year));
        car_id_list.push_back(car_type+to_string(car_list[car_type].size()));
    }
//%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
    void show_car_list(pair <int,int> d){
        for (auto i:car_list){
            cout<<"\n------------------- CAR Type: "<< i.first << "  ----------------------\n";
            for (auto j:i.second){
                if (available_for_rent(j.id,d)){j.print_info();}
            }
        }
        cout<<"\n-------------------------------------------------------\n";
        cout<<"-------------------------------------------------------\n";
    }
//%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
    bool available_for_rent(string j, pair <int,int> d){
        if (find(car_id_list.begin(),car_id_list.end(),j)==car_id_list.end()){return false;}
        if (reserved_cars.find(j)==reserved_cars.end()){return true;}
        else{
            for (auto k:reserved_cars[j]){
                if ( (k.first<=d.first && k.second>=d.first) || (k.first<=d.second && k.second>=d.second) ){
                    return false;
                }
            }
        }
        return true;
    }
//%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
    int convert_date (string s_date){
        int s=0;
        s = stoi(string (s_date.begin()+6,s_date.end()));
        s = s*100 + stoi(string (s_date.begin(),s_date.begin()+2));
        s = s*100 + stoi(string (s_date.begin()+3,s_date.begin()+5));
        return s;
    }
//%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
    void customer_request(){
        pair <int , int> d;
        string car_id;
        d = get_customer_dates();
        while (d.first>=d.second){
            cout<< "Invalid entries! Please enter valid dates!\n";
            d = get_customer_dates();
        }
        cout<<"Available cars for the selected time slot:\n";
        show_car_list(d);
        cout<<"Please enter your desired car id:  ";
        cin>>car_id;
        if (static_cast <int> (car_id[0])>=97){car_id[0]-=32;}
        while (!available_for_rent(car_id,d)){
            cout<<"The id "<<car_id<<" is invalid id; please make a valid selection:  ";
            cin>>car_id;
            if (static_cast <int> (car_id[0])>=97){car_id[0]-=32;}
        }
        make_invoice(car_id,d);
    }
//%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
    pair <int, int> get_customer_dates(){
        string s,e;
        cout<<"Please enter your desired start date in the format mm/dd/yyyy (e.g., 01/12/2023)   ";
        cin>>s;
        cout<<"Please enter your desired end date in the format mm/dd/yyyy   (e.g., 01/15/2023)   ";
        cin>>e;
        if (s.size()!=10 || s[2]!='/' || s[5]!='/'){return make_pair (convert_date("01/01/2000") , convert_date("01/01/2000"));}
        else if (e.size()!=10 || e[2]!='/' || e[5]!='/'){return make_pair (convert_date("01/01/2000") , convert_date("01/01/2000"));}
        return make_pair (convert_date(s) , convert_date(e));
    }
//%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
    long calculate_days(int d){
        vector <int> m={0,31,59,90,120,151,181,212,243,273,304,334};
        long d1 = 0;
        d1 += (d/10000)*365 + (d/10000-1)/4 - (d/10000-1)/100 + (d/10000-1)/400;
        if (  (d/10000%4 == 0 && d/10000%100 !=0) || (d/10000%400 == 0)  ){
            if (d/100%100>2){d1 += 1;}
        }
        d1 += d%100 + m[d/100%100-1];
        return d1;
    }
//%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
    void make_invoice(string car_id, pair <int , int> d){
        float c;
        string s;
        reserved_cars[car_id].push_back(d);
        cout<<"Please enter your name:  ";
        cin>>s;
        cout<<"\n\n----------------INVOICE----------------\n";
        time_t timetoday;
        time (&timetoday);
        cout<< asctime(localtime(&timetoday));
        cout<<"Invoice number:  "<<d.first<<car_id<<endl;
        for (auto i:car_list){
            for (auto j:i.second){
                if (j.id == car_id){
                    j.print_info();
                    break;
                }
            }
        }
        cout<<"Customer:       "<<s<<endl;
        cout<< "Days:           "<<calculate_days(d.second)-calculate_days(d.first)+1<<endl;
        c = cost_calculator(car_id[0],int(calculate_days(d.second)-calculate_days(d.first)+1));
        cout<<"price:          $" <<c<<endl;
        cout<<"Estimated tax:  $"<<c*0.07<<endl;
        cout<<"---------------------------------------\n";
        cout<<"Total price:    $"<<c*1.07<<endl;
        cout<<"---------------------------------------\n";
    }
//%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
    float cost_calculator(char& c, int d){
        return car_price[c]*d;
    }
};







int main(){
    Car_Rental ABC;
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
    ABC.show_car_list(make_pair(2,3));
    ABC.customer_request();
    ABC.customer_request();
    ABC.customer_request();
       
}
