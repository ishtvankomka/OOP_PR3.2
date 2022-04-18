#include "Truck.hpp"
#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <string>
#include <sstream>

Truck::Truck() {
    set_make("");
    set_year(0);
    set_price(0);
    set_milage(0);
    set_loadcapacity(0);
}

Truck::Truck(string m, int y, double p, double mil) {
    set_make("");
    set_year(0);
    set_price(0);
    set_milage(0);
    set_loadcapacity(0);
}

Truck::Truck(Truck& f) {
    set_make(f.get_make());
    set_year(f.get_year());
    set_price(f.get_price());
    set_milage(f.get_milage());
    set_loadcapacity(f.get_loadcapacity());
}

Truck& Truck::operator = (const Truck& f) {
    if (!((f.get_year() <= 1800 || f.get_year() > 2022) ||
        (f.get_price() <= 0) ||
        (f.get_milage() < 0) ||
        (f.get_loadcapacity() < 0)))
    {
        set_make(f.get_make());
        set_year(f.get_year());
        set_price(f.get_price());
        set_milage(f.get_milage());
        set_loadcapacity(f.get_loadcapacity());
    }
    return *this;
}
Truck::~Truck()
{
    loadcapacity = {};
}
istream& operator >> (istream& in, Truck& f)
{
    string m;
    double mil, p, lc;
    int y;
    cout << "Set Truck characteristic" << endl;
    cout << " Make: "; in >> m;
    f.set_make(m);
    cout << " Year: "; in >> y;
    f.set_year(y);
    cout << " Pricce($): "; in >> p;
    f.set_price(p);
    cout << " Milage(km): "; in >> mil;
    f.set_milage(mil);
    cout << " Loadcapacity(tons): "; in >> lc;
    f.set_loadcapacity(lc);
    while((f.get_year() <= 1800 || f.get_year() > 2022) ||
          (f.get_price() <= 0) ||
          (f.get_milage() < 0) ||
          (f.get_loadcapacity() < 0))
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
            cout << " Loadcapacity(tons): "; in >> lc;
            f.set_loadcapacity(lc);
        }
    return in;
}

ostream& operator << (ostream& out, const Truck& a)
{
    out << string(a);
    return out;
}

Truck::operator string () const
{
    stringstream f;
    f << "Truck characteristic \n"
      <<  " Make: " << get_make() << "\n"
      <<  " Year: " << get_year() << "\n"
      <<  " Price: " << get_price() << "$" << "\n"
      <<  " Milage: " << get_milage() << "km\n"
      <<  " Loadcpacity: " << get_loadcapacity() << "tons" << endl;
    return f.str();
}

void Read(Truck& f)
{
    cin >> f;
}

void Display(Truck& f)
{
    cout << f;
}


