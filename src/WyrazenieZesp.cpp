#include "WyrazenieZesp.hh"
#include <iostream>
using namespace std;

/*
 * Tu nalezy zdefiniowac funkcje, ktorych zapowiedzi znajduja sie
 * w pliku naglowkowym.
 */



 /*
  * Funkcja wyswietlania bez uzycia strumieni.
  */
ostream& operator << (ostream& StrmWyj, WyrazenieZesp&  WyrZ) 
{
	StrmWyj << WyrZ.Arg1;
	switch (WyrZ.Op){
	case Op_Dodaj:
		StrmWyj << " + ";
		break;
	case Op_Odejmij:
		StrmWyj << " - ";
		break;
	case Op_Mnoz:
		StrmWyj << " * ";
		break;
	case Op_Dziel:
		StrmWyj << " / ";
		break;
	}
	StrmWyj << WyrZ.Arg2;
	return StrmWyj;
}



/*
 * Funkcja obliczania wyrazow zespolonych.
 */
LZespolona Oblicz(WyrazenieZesp  WyrZ) 
{
  LZespolona wynik;
	switch (WyrZ.Op) {
	case Op_Dodaj:{ 
	        wynik = WyrZ.Arg1 + WyrZ.Arg2;
	break;
	}
	case Op_Odejmij:{
	        wynik = WyrZ.Arg1 - WyrZ.Arg2;
	break;
	}
	case Op_Mnoz:{
		wynik = WyrZ.Arg1 * WyrZ.Arg2;
	break;
	}
	case Op_Dziel:{
		wynik = WyrZ.Arg1 / WyrZ.Arg2;
	break;
	}
	default: {
	         wynik = WyrZ.Arg1;
	}
	}
	return wynik;
}
