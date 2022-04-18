#include <iostream>
#include "Vehicle.hpp"
#include "Automobile.hpp"
#include "Truck.hpp"
#include "Steamer.hpp"
#include "Plane.hpp"

using namespace std;

int main() {
    cout << "VEHICLE" << endl;
    Vehicle v;
    Read(v);
    Display(v);
    cout << endl;

    cout << "AUTOMOBILE" << endl;
    Automobile a;
    Read(a);
    Display(a);
    cout << endl;
    
    cout << "TRUCK" << endl;
    Truck t;
    Read(t);
    Display(t);
    cout << endl;
    
    cout << "STEAMER" << endl;
    Steamer s;
    Read(s);
    Display(s);
    cout << endl;

    cout << "PLANE" << endl;
    Plane p;
    Read(p);
    Display(p);
    cout << endl;

    return 0;
}
