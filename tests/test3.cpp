#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "./doctest/doctest.h"
#include "LZespolona.hh"
#include "WyrazenieZesp.hh"

TEST_CASE("Wyswietlanie Wyrazenia zespolonego"){
  WyrazenieZesp x;
  LZespolona y,z;
  
    y.re = 2;
    y.im = 2;
    x.Arg1 = y;
  
  x.Op = Op_Dodaj;

    z.re = 3;
    z.im = 3;
    x.Arg2 = z;

  std::ostringstream out;
  out << x;
  CHECK( "(2.00+2.00i)+(3.00+3.00i)" == out. str() );
}

TEST_CASE("Wczytywanie Wyrazenia zespolonego"){
  WyrazenieZesp x;

  std::istringstream in("(2+2i)+(3+3i)");
  in >> x;
  std::ostringstream out;
  out << x;
  
  CHECK( "(2.00+2.00i)+(3.00+3.00i)" == out. str() );
}

TEST_CASE("Obliczanie Wyrazenia zespolonego +"){
  WyrazenieZesp x;
  LZespolona y;

  std::istringstream in("(2+2i)+(3+3i)");
  in >> x;
  y = Oblicz (x);
  std::ostringstream out;
  out << y;
  
  CHECK( "(5.00+5.00i)" == out. str() );
}

TEST_CASE("Obliczanie Wyrazenia zespolonego -"){
  WyrazenieZesp x;
  LZespolona y;

  std::istringstream in("(2+2i)-(3+3i)");
  in >> x;
  y = Oblicz (x);
  std::ostringstream out;
  out << y;
  
  CHECK( "(-1.00-1.00i)" == out. str() );
}

TEST_CASE("Obliczanie Wyrazenia zespolonego *"){
  WyrazenieZesp x;
  LZespolona y;

  std::istringstream in("(2+2i)*(3+3i)");
  in >> x;
  y = Oblicz (x);
  std::ostringstream out;
  out << y;
  
  CHECK( "(0.00+12.00i)" == out. str() );
}

TEST_CASE("Obliczanie Wyrazenia zespolonego /"){
  WyrazenieZesp x;
  LZespolona y;

  std::istringstream in("(4+5i)/(2+3i)");
  in >> x;
  y = Oblicz (x);
  std::ostringstream out;
  out << y;
  
  CHECK( "(1.77-0.15i)" == out. str() );
}

