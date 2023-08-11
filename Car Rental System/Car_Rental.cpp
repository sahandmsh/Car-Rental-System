#include "Car_Rental.hpp"
Car_Rental::Car_Rental(){
    // Default values for price/day for different car types
    // compact sedan, mid-size sedan, full-size sedan, SUV, Truck
    car_price['C'] = 30.33;
    car_price['M'] = 45.66;
    car_price['F'] = 60.5;
    car_price['S'] = 63.33;
    car_price['T'] = 70.33;
}
//%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
void Car_Rental:: add_car(std::string car_type, std::string make, std::string model, std::string color, int year){
    car_list[car_type].push_back(car(car_type+std::to_string(car_list[car_type].size()+1), make, model, color, year));
    car_id_list.push_back(car_type+std::to_string(car_list[car_type].size()));
}
//%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
void Car_Rental:: show_car_list(std::pair <int,int> d){
    for (auto i:car_list){
        std::cout<<"\n------------------- CAR Type: "<< i.first << "  ----------------------\n";
        for (auto j:i.second){
            if (available_for_rent(j.id,d)){j.print_info();}
        }
    }
    std::cout<<"\n-------------------------------------------------------\n";
    std::cout<<"-------------------------------------------------------\n";
}
//%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
bool Car_Rental:: available_for_rent(std::string j, std::pair <int,int> d){
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
int Car_Rental:: convert_date (std::string s_date){
    int s=0;
    s = stoi(std::string (s_date.begin()+6,s_date.end()));
    s = s*100 + stoi(std::string (s_date.begin(),s_date.begin()+2));
    s = s*100 + stoi(std::string (s_date.begin()+3,s_date.begin()+5));
    return s;
}
//%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
void Car_Rental:: customer_request(){
    std::pair <int , int> d;
    std::string car_id;
    d = get_customer_dates();
    while (d.first>=d.second || !valid_date(d.first) || !valid_date(d.second)){
        std::cout<< "Invalid entries! Please enter valid dates!\n";
        d = get_customer_dates();
    }
    std::cout<<"Available cars for the selected time slot:\n";
    show_car_list(d);
    std::cout<<"Please enter your desired car id:  ";
    std::cin>>car_id;
    if (static_cast <int> (car_id[0])>=97){car_id[0]-=32;}
    while (!available_for_rent(car_id,d)){
        std::cout<<"The id "<<car_id<<" is invalid id; please make a valid selection:  ";
        std::cin>>car_id;
        if (static_cast <int> (car_id[0])>=97){car_id[0]-=32;}
    }
    make_invoice(car_id,d);
}
//%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
std::pair<int, int> Car_Rental:: get_customer_dates(){
    std::string s,e;
    std::cout<<"Please enter your desired start date in the format mm/dd/yyyy (e.g., 08/05/2023)   ";
    std::cin>>s;
    std::cout<<"Please enter your desired end date in the format mm/dd/yyyy   (e.g., 08/15/2023)   ";
    std::cin>>e;
    if (s.size()!=10 || s[2]!='/' || s[5]!='/'){return std::make_pair (convert_date("01/01/2000") , convert_date("01/01/2000"));}
    else if (e.size()!=10 || e[2]!='/' || e[5]!='/'){return std::make_pair (convert_date("01/01/2000") , convert_date("01/01/2000"));}
    return std::make_pair (convert_date(s) , convert_date(e));
}
//%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
long Car_Rental:: calculate_days(int d){
    std::vector <int> m={0,31,59,90,120,151,181,212,243,273,304,334};
    long d1 = 0;
    d1 += (d/10000)*365 + (d/10000-1)/4 - (d/10000-1)/100 + (d/10000-1)/400;
    if (check_leap_year(d/10000)){
        if (d/100%100>2){d1 += 1;}
    }
    d1 += d%100 + m[d/100%100-1];
    return d1;
}
//%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
void Car_Rental:: make_invoice(std::string car_id, std::pair <int , int> d){
    float c;
    std::string s;
    reserved_cars[car_id].push_back(d);
    std::cout<<"Please enter your name:  ";
    std::cin>>s;
    std::cout<<"\n\n----------------INVOICE----------------\n";
    time_t timetoday;
    time (&timetoday);
    std::cout<< asctime(localtime(&timetoday));
    std::cout<<"Invoice number: "<<d.first<<car_id<<std::endl;
    for (auto i:car_list){
        for (auto j:i.second){
            if (j.id == car_id){
                j.print_info();
                break;
            }
        }
    }
    std::cout<<"Customer:       "<<s<<std::endl;
    std::cout<< "Days:           "<<calculate_days(d.second)-calculate_days(d.first)+1<<std::endl;
    c = cost_calculator(car_id[0],int(calculate_days(d.second)-calculate_days(d.first)+1));
    std::cout<<"price:          $" <<c<<std::endl;
    std::cout<<"Estimated tax:  $"<<c*0.07<<std::endl;
    std::cout<<"---------------------------------------\n";
    std::cout<<"Total price:    $"<<c*1.07<<std::endl;
    std::cout<<"---------------------------------------\n";
}
//%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
float Car_Rental:: cost_calculator(char c, int d){
    return car_price[c]*d;
}
//%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
bool Car_Rental:: valid_date(int d){
    tm* my_time;
    time_t t = time(0);
    my_time = localtime(&t);
    int current_d = ( (1900+my_time->tm_year)*100 + my_time->tm_mon+1 )*100 + my_time->tm_mday;
    if (d<current_d){
        std::cout<<"**The entered date cannot be before today!**    ";
        return false;}
    
    int m[]={31,28,31,30,31,30,31,31,30,31,30,31};
    if (d/100%100>12){return false;}
    // Feb can be 29 days in Leap years.
    else if (d/100%100==2 && d%100==29 && check_leap_year(d/10000)){return true;}
    else if (m[d/100%100-1]<d%100){return false;}
    return true;
}
//%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
bool Car_Rental:: check_leap_year(int y){
    return (y%4 == 0 && y%100 !=0) || (y%400 == 0);
}
