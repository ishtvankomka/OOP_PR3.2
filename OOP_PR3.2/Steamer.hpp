#pragma once
#include <iostream>
#include <sstream>
#include <string>
#include "Vehicle.hpp"
using namespace std;

class Steamer : public Vehicle
{
private:
    int lenght;

public:
    Steamer();
    Steamer(string, int, double, int);
    Steamer(Steamer&);
    Steamer& operator = (const Steamer&);
    ~Steamer();
    
    operator string() const;
    friend ostream& operator << (ostream&, const Steamer&);
    friend istream& operator >> (istream&, Steamer&);
    
    friend void Read(Steamer&);
    friend void Display(Steamer&);

    void set_lenght(double value) { lenght = value; };
    double get_lenght() const { return lenght; };
};
