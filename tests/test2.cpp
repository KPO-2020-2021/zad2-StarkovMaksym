#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "./doctest/doctest.h"
#include "LZespolona.hh"

TEST_CASE("Test LZespolona dzielenie przez skalar 1") {
    LZespolona x, y;
    double t = 2;
    
    x.re = 2;
    x.im = 2;

    y.re = 1;
    y.im = 1;
   
    CHECK(x/t == y);
}

TEST_CASE("Test LZespolona dzielenie przez skalar 2") {
    LZespolona x, y;
    double t = 3;
    
    x.re = 1;
    x.im = 1;

    y.re = 0.333;
    y.im = 0.333;
   
    CHECK(x/t == y);
}

TEST_CASE("Test LZespolona dzielenie przez skalar - zero") {
    LZespolona x;
    double t = 0;
    
    x.re = 2;
    x.im = 2;
 
   WARN_THROWS(x/t);
}

TEST_CASE("Test LZespolona dzielenie przez liczbe zespolona - (0+0i)") {
  LZespolona x,y;
    
    x.re = 2;
    x.im = 2;
    y.re = 0;
    y.im = 0;
    
   WARN_THROWS(x/y);
}

TEST_CASE("Test LZespolona mnozenie przez (0+0i)") {
    LZespolona x, y;
    
    x.re = 1;
    x.im = 1;

    y.re = 0;
    y.im = 0;
   
    CHECK(x*y == y);
}

TEST_CASE("Test LZespolona mnozenie przez (1+0i)") {
    LZespolona x, y;
    
    x.re = 1;
    x.im = 1;

    y.re = 1;
    y.im = 0;
   
    CHECK(x*y == x);
}

TEST_CASE("Test LZespolona mnozenie przez (0+1i)") {
  LZespolona x, y, z;
    
    x.re = 1;
    x.im = 1;

    y.re = 0;
    y.im = 1;

    z.re = -1;
    z.im = 1;
    
    CHECK(x*y == z);
}

TEST_CASE("Test LZespolona mnozenie przez (1+1i)") {
  LZespolona x, y, z;
    
    x.re = 1;
    x.im = 1;

    y.re = 1;
    y.im = 1;
    
    z.re = 0;
    z.im = 2;
   
    CHECK(x*y == z);
}

TEST_CASE("Test LZespolona - wyswietlanie standart") {
    LZespolona x;
    
    x.re = 2;
    x.im = 2;

    std::ostringstream out;

    out << x;
    CHECK( "(2.00+2.00i)" == out.str() );
}

TEST_CASE("Test LZespolona - wyswietlanie zaokraglanie") {
    LZespolona x;
    
    x.re = 2.0/3.0;
    x.im = 2.0/3.0;

    std::ostringstream out;

    out << x;
   CHECK( "(0.67+0.67i)" == out.str() );
}

TEST_CASE("Test LZespolona - wczytywanie standart") {
    LZespolona x; 

    std::istringstream in("(10+10.10i)");
    in >> x;
    std::ostringstream out;
    out << x;
    
   CHECK( "(10.00+10.10i)" == out.str() );
}
