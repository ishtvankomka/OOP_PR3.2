#include "Steamer.hpp"
#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <string>
#include <sstream>

Steamer::Steamer() {
    set_make("");
    set_year(0);
    set_price(0);
    set_lenght(0);
}

Steamer::Steamer(string m, int y, double p, int l) {
    set_make("");
    set_year(0);
    set_price(0);
    set_lenght(0);
}

Steamer::Steamer(Steamer& f) {
    set_make(f.get_make());
    set_year(f.get_year());
    set_price(f.get_price());
    set_lenght(f.get_lenght());
}

Steamer& Steamer::operator = (const Steamer& f) {
    if (!((f.get_year() <= 1800 || f.get_year() > 2022) ||
        (f.get_price() <= 0) ||
        (f.get_lenght() <= 0)))
    {
        set_make(f.get_make());
        set_year(f.get_year());
        set_price(f.get_price());
        set_lenght(f.get_lenght());
    }
    return *this;
}
Steamer::~Steamer()
{
    lenght = {};
}
istream& operator >> (istream& in, Steamer& f)
{
    string m;
    double mil, p;
    int y;
    cout << "Set Steamer characteristic" << endl;
    cout << " Make: "; in >> m;
    f.set_make(m);
    cout << " Year: "; in >> y;
    f.set_year(y);
    cout << " Pricce($): "; in >> p;
    f.set_price(p);
    cout << " Lenght(m): "; in >> mil;
    f.set_lenght(mil);
    while((f.get_year() <= 1800 || f.get_year() > 2022) ||
          (f.get_price() <= 0) ||
          (f.get_lenght() <= 0))
        {
            cout << "Wrong arguments to init!" << endl;
            cout << " Make: "; in >> m;
            f.set_make(m);
            cout << " Year: "; in >> y;
            f.set_year(y);
            cout << " Pricce($): "; in >> p;
            f.set_price(p);
            cout << " Lenght(m): "; in >> mil;
            f.set_lenght(mil);
        }
    return in;
}

ostream& operator << (ostream& out, const Steamer& a)
{
    out << string(a);
    return out;
}

Steamer::operator string () const
{
    stringstream f;
    f << "Steamer characteristic \n"
      <<  " Make: " << get_make() << "\n"
      <<  " Year: " << get_year() << "\n"
      <<  " Price: " << get_price() << "$" << "\n"
      <<  " Lenght: " << get_lenght() << "m" << endl;
    return f.str();
}

void Read(Steamer& f)
{
    cin >> f;
}

void Display(Steamer& f)
{
    cout << f;
}


