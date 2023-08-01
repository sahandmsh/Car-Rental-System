#ifndef Car_hpp
#define Car_hpp
#include <iostream>
#include <string>
#include <vector>

struct car{
    car(int, std::string, std::string, std::string, int);
    car(std::string, std::string, std::string, int);
    void print_info();
private:
    std::string make, model, color;
    int year, id;
};

#endif /* Car_hpp */
