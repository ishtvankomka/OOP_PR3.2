#pragma once
#include <iostream>
#include <sstream>
#include <string>
#include "Automobile.hpp"
#include "Vehicle.hpp"
using namespace std;

class Truck : public Automobile
{
private:
    double loadcapacity;

public:
    Truck();
    Truck(string, int, double, double);
    Truck(Truck&);
    Truck& operator = (const Truck&);
    ~Truck();
    
    operator string() const;
    friend ostream& operator << (ostream&, const Truck&);
    friend istream& operator >> (istream&, Truck&);
    
    friend void Read(Truck&);
    friend void Display(Truck&);

    void set_loadcapacity(double value) { loadcapacity = value; };
    double get_loadcapacity() const { return loadcapacity; };
};
