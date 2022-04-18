#include "Vehicle.hpp"
#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <string>
#include <sstream>

Vehicle::Vehicle() {
    make = "";
    year = 0;
    price = 0;
}

Vehicle::Vehicle(string m, int y, double p) {
    make = "";
    year = 0;
    price = 0;
}

Vehicle::Vehicle(Vehicle& f) {
    make = f.make;
    year = f.year;
    price = f.price;
}

Vehicle& Vehicle::operator = (const Vehicle& f) {
    make = f.make;
    year = f.year;
    price = f.price;
    return *this;
}
Vehicle::~Vehicle()
{
    make = {};
}
istream& operator >> (istream& in, Vehicle& f)
{
    cout << "Set vehicle characteristic" << endl;
    cout << " Make: "; in >> f.make;
    cout << " Year: "; in >> f.year;
    cout << " Pricce($): "; in >> f.price;
    while((f.year <= 1800 || f.year > 2022) ||
          (f.price <= 0))
        {
            cout << "Wrong arguments to init!" << endl;
            cout << " Make: "; in >> f.make;
            cout << " Year: "; in >> f.year;
            cout << " Pricce($): "; in >> f.price;
        }
    return in;
}

ostream& operator << (ostream& out, const Vehicle& a)
{
    out << string(a);
    return out;
}

Vehicle::operator string () const
{
    stringstream f;
    f << "Vehicle characteristic \n"
      <<  " Make: " << make << "\n"
      <<  " Year: " << year << "\n"
      <<  " Price: " << price << "$" << endl;
    return f.str();
}

void Read(Vehicle& f)
{
    cin >> f;
}

void Display(Vehicle& f)
{
    cout << f;
}
