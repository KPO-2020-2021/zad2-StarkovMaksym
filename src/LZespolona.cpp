#include "LZespolona.hh"
#include <cmath>
#include <iostream>
using namespace std;
#define MIN_DIFF 0.01

/*!
 * Realizuje porównanie dwoch liczb zespolonych.
 * Argumenty:
 *    Skl1 - pierwsza porównywana liczba zespolona,
 *    Skl2 - druga porównywana liczba zespolona.
 * Zwraca:
 *    True dla równych liczb zespolonych.
 */

bool  operator == (LZespolona  Skl1, LZespolona  Skl2) {
  /* if ((Skl1.re == Skl2.re) && (Skl1.im == Skl2.im))
        return true;
    else
    return false;*/
    //alternatywnie, dla MIN_DIFF i wyników od użytkownika
   
  if (abs(Skl1.re - Skl2.re) <= MIN_DIFF && abs(Skl1.im - Skl2.im) <= MIN_DIFF)
      return true;
    else
      return false;
   
}

/*!
 * Realizuje dodanie dwoch liczb zespolonych.
 * Argumenty:
 *    Skl1 - pierwszy skladnik dodawania,
 *    Skl2 - drugi skladnik dodawania.
 * Zwraca:
 *    Sume dwoch skladnikow przekazanych jako parametry.
 */
LZespolona  operator + (LZespolona  Skl1, LZespolona  Skl2)
{
    LZespolona  Wynik;

    Wynik.re = Skl1.re + Skl2.re;
    Wynik.im = Skl1.im + Skl2.im;
    return Wynik;
}

/*!
 * Realizuje odejmowanie dwoch liczb zespolonych.
 * Argumenty:
 *    Skl1 - pierwszy skladnik odejmowania,
 *    Skl2 - drugi skladnik odejmowania.
 * Zwraca:
 *    Roznice dwoch skladnikow przekazanych jako parametry.
 */
LZespolona  operator - (LZespolona  Skl1, LZespolona  Skl2)
{
    LZespolona  Wynik;

    Wynik.re = Skl1.re - Skl2.re;
    Wynik.im = Skl1.im - Skl2.im;
    return Wynik;
}

/*!
 * Realizuje mnozenie dwoch liczb zespolonych.
 * Argumenty:
 *    Skl1 - pierwszy skladnik mnozenia,
 *    Skl2 - drugi skladnik mnozenia.
 * Zwraca:
 *    Iloczyn dwoch skladnikow przekazanych jako parametry.
 */
LZespolona  operator * (LZespolona  Skl1, LZespolona  Skl2)
{
    LZespolona  Wynik;

    Wynik.re = Skl1.re * Skl2.re - Skl1.im * Skl2.im;
    Wynik.im = Skl1.re * Skl2.im + Skl1.im * Skl2.re;
    return Wynik;
}

/*!
 * Realizuje dzielenie dwoch liczb zespolonych.
 * Argumenty:
 *    Skl1 - pierwszy skladnik dzielenia,
 *    Skl2 - drugi skladnik dzielenia.
 * Zwraca:
 *    Iloraz dwoch skladnikow przekazanych jako parametry.
 */
LZespolona  operator / (LZespolona  Skl1, LZespolona  Skl2)
{
    LZespolona  Wynik;
    if ((Skl2.re == 0) && (Skl2.im == 0))
    {
      throw runtime_error("Nie mozna dzielic przez zero\n");
    }

    Wynik.re = ((Skl1.re * Skl2.re + Skl1.im * Skl2.im) / (Skl2.re*Skl2.re + Skl2.im * Skl2.im));
    Wynik.im = ((Skl1.im * Skl2.re - Skl1.re * Skl2.im) / (Skl2.re*Skl2.re + Skl2.im * Skl2.im));
    return Wynik;
}

/*!
 * Realizuje sprzezenia liczby zespolonej.
 * Argumenty:
 *    Skl1 - podana liczba zespolona,
 * Zwraca:
 *    Wynik srzezenia przekazanego jako parametry.
 */
LZespolona  Sprzezenie(LZespolona Skl1)
{
    LZespolona  Wynik;

    Wynik.re = Skl1.re;
    Wynik.im = (-1) * Skl1.im;
    return Wynik;
}

/*!
 * Realizuje kwadrat modulu liczby zespolonej.
 * Argumenty:
 *    Skl1 - podana liczba zespolona,
 * Zwraca:
 *    Wynik kwadratu modulu przekazanego jako liczba.
 */
double Modul2(LZespolona Skl1)
{
    double  Wynik;

    Wynik = abs((Skl1.re * Skl1.re) + (Skl1.im * Skl1.im));
    return Wynik;
}

/*!
 * Realizuje dzielenie liczby zespolonej przez skakar.
 * Argumenty:
 *    Skl1 - dzielona liczba zespolona,
 *    Skl2 - skalar-dzielnik.
 * Zwraca:
 *    Wynik dzielenia dwoch skladnikow przekazanych jako parametry.
 */
LZespolona  operator / (LZespolona  Skl1, double  Skl2)
{
    LZespolona  Wynik;
    if (Skl2 == 0)
    {
       throw runtime_error("Nie mozna dzielic przez zero\n");
    }

    Wynik.re = Skl1.re / Skl2;
    Wynik.im = Skl1.im / Skl2;
    return Wynik;
}


void Wyswietl(LZespolona Skl1)
{
    cout << "(" << Skl1.re << showpos << Skl1.im << noshowpos << "i" << ")";
}







ostream& operator << (ostream& StrmWyj, LZespolona& LZesp)
{   StrmWyj.precision(2);
  StrmWyj << "(" << std::fixed << LZesp.re << showpos << LZesp.im << noshowpos << "i" << ")";
    return StrmWyj;
}



istream& operator >> (istream& StrmWej, LZespolona& LZesp)
{
  char Nawias1, Nawias2, Litera;
    StrmWej >> Nawias1;
    if (StrmWej.fail())
        return StrmWej;
    if (Nawias1 != '(') {
        StrmWej.setstate(ios::failbit);
        return StrmWej;
    }
    StrmWej >> LZesp.re;
    if (StrmWej.fail())
        return StrmWej;
    StrmWej >> LZesp.im;
    if (StrmWej.fail())
        return StrmWej;
    StrmWej >> Litera;
    if (StrmWej.fail())
        return StrmWej;
    if (Litera != 'i') {
        StrmWej.setstate(ios::failbit);
        return StrmWej;
    }
    StrmWej >> Nawias2;
    if (StrmWej.fail())
        return StrmWej;
    if (Nawias2 != ')') {
        StrmWej.setstate(ios::failbit);
        return StrmWej;
    }
    return StrmWej;
}
