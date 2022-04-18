#pragma once
#include <iostream>
#include <sstream>
#include <string>
#include "Vehicle.hpp"
using namespace std;

class Plane : public Vehicle
{
private:
    double ttaf;

public:
    Plane();
    Plane(string, int, double, double);
    Plane(Plane&);
    Plane& operator = (const Plane&);
    ~Plane();
    
    operator string() const;
    friend ostream& operator << (ostream&, const Plane&);
    friend istream& operator >> (istream&, Plane&);
    
    friend void Read(Plane&);
    friend void Display(Plane&);

    void set_ttaf(double value) { ttaf = value; };
    double get_ttaf() const { return ttaf; };
};
