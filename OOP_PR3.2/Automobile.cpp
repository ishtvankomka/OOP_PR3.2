#include "Automobile.hpp"
#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <string>
#include <sstream>

Automobile::Automobile() {
    set_make("");
    set_year(0);
    set_price(0);
    set_milage(0);
}

Automobile::Automobile(string m, int y, double p, double mil) {
    set_make("");
    set_year(0);
    set_price(0);
    set_milage(0);
}

Automobile::Automobile(Automobile& f) {
    set_make(f.get_make());
    set_year(f.get_year());
    set_price(f.get_price());
    set_milage(f.get_milage());
}

Automobile& Automobile::operator = (const Automobile& f) {
    if (!((f.get_year() <= 1800 || f.get_year() > 2022) ||
        (f.get_price() <= 0) ||
        (f.get_milage() < 0)))
    {
        set_make(f.get_make());
        set_year(f.get_year());
        set_price(f.get_price());
        set_milage(f.get_milage());
    }
    return *this;
}
Automobile::~Automobile()
{
    milage = {};
}
istream& operator >> (istream& in, Automobile& f)
{
    string m;
    double mil, p;
    int y;
    cout << "Set Automobile characteristic" << endl;
    cout << " Make: "; in >> m;
    f.set_make(m);
    cout << " Year: "; in >> y;
    f.set_year(y);
    cout << " Pricce($): "; in >> p;
    f.set_price(p);
    cout << " Milage(km): "; in >> mil;
    f.set_milage(mil);
    while((f.get_year() <= 1800 || f.get_year() > 2022) ||
          (f.get_price() <= 0) ||
          (f.get_milage() < 0))
        {
            cout << "Wrong arguments to init!" << endl;
            cout << " Make: "; in >> m;
            f.set_make(m);
            cout << " Year: "; in >> y;
            f.set_year(y);
            cout << " Pricce($): "; in >> p;
            f.set_price(p);
            cout << " Milage(km): "; in >> mil;
            f.set_milage(mil);
        }
    return in;
}

ostream& operator << (ostream& out, const Automobile& a)
{
    out << string(a);
    return out;
}

Automobile::operator string () const
{
    stringstream f;
    f << "Automobile characteristic \n"
      <<  " Make: " << get_make() << "\n"
      <<  " Year: " << get_year() << "\n"
      <<  " Price: " << get_price() << "$" << "\n"
      <<  " Milage: " << get_milage() << "km" << endl;
    return f.str();
}

void Read(Automobile& f)
{
    cin >> f;
}

void Display(Automobile& f)
{
    cout << f;
}

