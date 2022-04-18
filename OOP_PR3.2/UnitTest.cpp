#define CATCH_CONFIG_MAIN
#include "catch.h"
#include "Vehicle.cpp"
#include "Vehicle.hpp"
#include "Plane.cpp"
#include "Plane.hpp"

TEST_CASE( "Arguments initialized") {
    Plane p;
    p.set_make("Airbus");
    p.set_year(1999);
    p.set_price(899999);
    p.set_ttaf(8000);
    
    REQUIRE( p.get_make() == "Airbus" );
    REQUIRE( p.get_year() == 1999 );
    REQUIRE( p.get_price() == 899999);
    REQUIRE( p.get_ttaf() == 8000);
}
