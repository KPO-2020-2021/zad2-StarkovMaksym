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
void Wyswietl(WyrazenieZesp  WyrZ) 
{
	cout << WyrZ.Arg1;
	switch (WyrZ.Op){
	case Op_Dodaj:
		cout << " + ";
		break;
	case Op_Odejmij:
		cout << " - ";
		break;
	case Op_Mnoz:
		cout << " * ";
		break;
	case Op_Dziel:
		cout << " / ";
		break;
	}
	cout << WyrZ.Arg2;
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
