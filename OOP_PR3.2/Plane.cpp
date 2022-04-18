#include "Plane.hpp"
#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <string>
#include <sstream>

Plane::Plane() {
    set_make("");
    set_year(0);
    set_price(0);
    set_ttaf(0);
}

Plane::Plane(string m, int y, double p, double mil) {
    set_make("");
    set_year(0);
    set_price(0);
    set_ttaf(0);
}

Plane::Plane(Plane& f) {
    set_make(f.get_make());
    set_year(f.get_year());
    set_price(f.get_price());
    set_ttaf(f.get_ttaf());
}

Plane& Plane::operator = (const Plane& f) {
    if (!((f.get_year() <= 1800 || f.get_year() > 2022) ||
        (f.get_price() <= 0) ||
        (f.get_ttaf() < 0)))
    {
        set_make(f.get_make());
        set_year(f.get_year());
        set_price(f.get_price());
        set_ttaf(f.get_ttaf());
    }
    return *this;
}
Plane::~Plane()
{
    ttaf = {};
}
istream& operator >> (istream& in, Plane& f)
{
    string m;
    double t, p;
    int y;
    cout << "Set Plane characteristic" << endl;
    cout << " Make: "; in >> m;
    f.set_make(m);
    cout << " Year: "; in >> y;
    f.set_year(y);
    cout << " Pricce($): "; in >> p;
    f.set_price(p);
    cout << " Total time air frame (hours): "; in >> t;
    f.set_ttaf(t);
    while((f.get_year() <= 1800 || f.get_year() > 2022) ||
          (f.get_price() <= 0) ||
          (f.get_ttaf() < 0))
        {
            cout << "Wrong arguments to init!" << endl;
            cout << " Make: "; in >> m;
            f.set_make(m);
            cout << " Year: "; in >> y;
            f.set_year(y);
            cout << " Pricce($): "; in >> p;
            f.set_price(p);
            cout << " ttaf(hours): "; in >> t;
            f.set_ttaf(t);
        }
    return in;
}

ostream& operator << (ostream& out, const Plane& a)
{
    out << string(a);
    return out;
}

Plane::operator string () const
{
    stringstream f;
    f << "Plane characteristic \n"
      <<  " Make: " << get_make() << "\n"
      <<  " Year: " << get_year() << "\n"
      <<  " Price: " << get_price() << "$" << "\n"
      <<  " Total time air frame: " << get_ttaf() << "hours" << endl;
    return f.str();
}

void Read(Plane& f)
{
    cin >> f;
}

void Display(Plane& f)
{
    cout << f;
}
