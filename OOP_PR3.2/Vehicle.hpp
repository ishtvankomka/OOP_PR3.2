#pragma once
#include <iostream>
#include <sstream>
#include <string>
using namespace std;

class Vehicle
{
private:
    string make;
    int year;
    double price;

public:
    Vehicle();
    Vehicle(string, int, double);
    Vehicle(Vehicle&);
    Vehicle& operator = (const Vehicle&);
    ~Vehicle();
    
    operator string() const;
    friend ostream& operator << (ostream&, const Vehicle&);
    friend istream& operator >> (istream&, Vehicle&);
    
    friend void Read(Vehicle&);
    friend void Display(Vehicle&);

    void set_make(string value) { make = value; };
    void set_year(int value) { year = value; };
    void set_price(double value) { price = value; };
    string get_make() const { return make; };
    int get_year() const { return year; };
    double get_price() const { return price; };
};
