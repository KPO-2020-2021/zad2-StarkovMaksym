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
