#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "./doctest/doctest.h"
#include "LZespolona.hh"

TEST_CASE("test modyfikacja LZespolona +="){
  LZespolona x, y, z;

  x.re = 2;
  x.im = 3;

  y.re = 4;
  y.im = 5;

  z.re = 6;
  z.im = 8;
  x+=y;
  CHECK(x == z);
}

TEST_CASE("test modyfikacja LZespolona /="){
  LZespolona x, y, z;

  x.re = 1;
  x.im = 8;

  y.re = 2;
  y.im = 3;

  z.re = 2;
  z.im = 1;
  x/=y;
  CHECK(x == z);
}

TEST_CASE("test modyfikacja LZespolona /= przez 0"){
  LZespolona x, y;

  x.re = 1;
  x.im = 8;

  y.re = 0;
  y.im = 0;
  
  WARN_THROWS(x/=y);
}

TEST_CASE("test modyfikacja LZespolona Arg(z) a>0"){
  LZespolona x;
  double  y;

  x.re = 2;
  x.im = 3;

  y = Arg(x);

  std::ostringstream out;
  out << y;
  
  CHECK("0.982794" == out.str());
}

TEST_CASE("test modyfikacja LZespolona Arg(z) a<0"){
  LZespolona x;
  double y;

  x.re = -2;
  x.im = 3;

  y = Arg(x);
  std::ostringstream out;
  out << y;
  
  CHECK("5.2988" == out.str());
}

TEST_CASE("test modyfikacja LZespolona Arg(z) a=0 b>0"){
  LZespolona x;
  double z, y;

  x.re = 0;
  x.im = 3;

  y = Arg(x);
  z = 1.57;
  
  CHECK(y == z);
}

TEST_CASE("test modyfikacja LZespolona Arg(z) a=0 b<0"){
  LZespolona x;
  double z, y;

  x.re = 0;
  x.im = -3;

  y = Arg(x);
  z = -1.57;
  
  CHECK(y == z);
}

TEST_CASE("test modyfikacja LZespolona Arg(z) a=0 b=0"){
  LZespolona x;

  x.re = 0;
  x.im = 0;
  
  WARN_THROWS(Arg(x));
}
