#pragma once
#include <iostream>
#include <sstream>
#include <string>
#include "Vehicle.hpp"
using namespace std;

class Automobile : public Vehicle
{
private:
    double milage;

public:
    Automobile();
    Automobile(string, int, double, double);
    Automobile(Automobile&);
    Automobile& operator = (const Automobile&);
    ~Automobile();
    
    operator string() const;
    friend ostream& operator << (ostream&, const Automobile&);
    friend istream& operator >> (istream&, Automobile&);
    
    friend void Read(Automobile&);
    friend void Display(Automobile&);

    void set_milage(double value) { milage = value; };
    double get_milage() const { return milage; };
};


