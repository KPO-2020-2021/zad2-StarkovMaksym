#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "./doctest/doctest.h"
#include "LZespolona.hh"

TEST_CASE("test LZespolona Suma"){
    LZespolona x, y, z;

    x.re = 1;
    x.im = 1;

    y.re = 1;
    y.im = -3;

    z.re = 2;
    z.im = -2;
    
    CHECK(x+y == z);
}

TEST_CASE("test LZespolona Suma - zaokronglenie wdol"){
    LZespolona x, y, z;

    x.re = 1.011;
    x.im = 1.1;

    y.re = 1.1;
    y.im = 1.011;

    z.re = 2.11;
    z.im = 2.11;
    
    CHECK(x+y == z);
}

TEST_CASE("test LZespolona Suma - zaokraglenie wgore"){
    LZespolona x, y, z;

    x.re = 1.019;
    x.im = 1.1;

    y.re = 1.1;
    y.im = 1.019;

    z.re = 2.12;
    z.im = 2.12;
    
    CHECK(x+y == z);
}

TEST_CASE("test LZespolona Roznica"){
    LZespolona x, y, z;

    x.re = 2;
    x.im = 2;

    y.re = 0.99;
    y.im = 0.98;

    z.re = 1.01;
    z.im = 1.02;
    
    CHECK(x-y == z);
}

TEST_CASE("test LZespolona Rownosc liczb - zaokraglenie wdol"){
    LZespolona x, y;

    x.re = 1.001;
    x.im = 1;

    y.re = 1;
    y.im = 1.001;
    
    CHECK(x == y);
}

TEST_CASE("test LZespolona Rownosc liczb - zaokraglenie wgore"){
    LZespolona x, y;

    x.re = 1.009;
    x.im = 1.01;

    y.re = 1.01;
    y.im = 1.009;
    
    CHECK(x == y);
}

TEST_CASE("test LZespolona sprzezenie (1+1i)"){
    LZespolona x, y;

    x.re = 1;
    x.im = 1;

    y.re = 1;
    y.im = -1;

    CHECK(Sprzezenie(x) == y);
}

TEST_CASE("test LZespolona sprzezenie (1+0i)"){
    LZespolona x, y;

    x.re = 1;
    x.im = 0;

    y.re = 1;
    y.im = 0;

    CHECK(Sprzezenie(x) == y);
}

TEST_CASE("test LZespolona kwadrat z modulu"){
    LZespolona x;
    double y;

    x.re = 2;
    x.im = -3;

    y = 13;
    
    CHECK(Modul2(x) == y);
}
