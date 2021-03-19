#ifndef LZESPOLONA_HH
#define LZESPOLONA_HH

/*!
 *  Plik zawiera definicje struktury LZesplona oraz zapowiedzi
 *  przeciazen operatorow arytmetycznych dzialajacych na tej
 *  strukturze.
 */


 /*!
  * Modeluje pojecie liczby zespolonej
  */
struct  LZespolona {
	double   re;    /*! Pole repezentuje czesc rzeczywista. */
	double   im;    /*! Pole repezentuje czesc urojona. */
};


/*
 * Funkcja porownania dwoch liczb zespolonych.
 */
bool  operator == (LZespolona  Skl1, LZespolona  Skl2);

/*
 * Funkcja dodawania dwoch liczb zespolonych.
 */
LZespolona  operator + (LZespolona  Skl1, LZespolona  Skl2);

/*
 * Funkcja odejmowania dwoch liczb zespolonych.
 */
LZespolona  operator - (LZespolona  Skl1, LZespolona  Skl2);

/*
 * Funkcja mnozenia dwoch liczb zespolonych.
 */
LZespolona  operator * (LZespolona  Skl1, LZespolona  Skl2);

/*
 * Funkcja dzielenia dwoch liczb zespolonych.
 */
LZespolona  operator / (LZespolona  Skl1, LZespolona  Skl2);

/*
 * Funkcja dzielenia liczby zespolonej przez skalar.
 */
LZespolona  operator / (LZespolona  Skl1, double  Skl2);

/*
 * Funkcja sprzezenia liczby zespolonej.
 */
LZespolona Sprzezenie(LZespolona Skl1);
/*
 * Funkcja operacji kwadratu modulu liczby zespolonej.
 */
double Modul2(LZespolona Skl1);

/*
 * Funkcja wyswietlania liczby zespolonej. Nie na stumiemiach.
 */
void Wyswietl(LZespolona Skl1);

/*
 * Funkcja wyswietlania liczby zespolonej za pomoca strumieni.
 */
ostream& operator << (ostream&, LZespolona&);

/*
 * Funkcja wczytywania liczby zespolonej za pomoca strumieni.
 */
istream& operator >> (istream&, LZespolona&);

#endif
