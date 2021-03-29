#include "WyrazenieZesp.hh"
#include "LZespolona.hh"
#include <iostream>
using namespace std;

/*
 * Tu nalezy zdefiniowac funkcje, ktorych zapowiedzi znajduja sie
 * w pliku naglowkowym.
 */



 /*
  * Funkcja wyswietlania wyrazenia zespolonego na strumieni.
  */
ostream& operator << (ostream& StrmWyj, WyrazenieZesp&  WyrZ) 
{
	StrmWyj << WyrZ.Arg1;
	switch (WyrZ.Op){
	case Op_Dodaj:
		StrmWyj << "+";
		break;
	case Op_Odejmij:
		StrmWyj << "-";
		break;
	case Op_Mnoz:
		StrmWyj << "*";
		break;
	case Op_Dziel:
		StrmWyj << "/";
		break;
	}
	StrmWyj << WyrZ.Arg2;
	return StrmWyj;
}

// funkcja wczytywania wyrazenia zespolonego ze strumienia
istream& operator >> (istream& StrmWej, WyrazenieZesp&  WyrZ) 
{       char Znak;
        StrmWej >> WyrZ.Arg1;
	StrmWej >> Znak;
	switch (Znak){
        case '+':{WyrZ.Op = Op_Dodaj;
	    break;}
	case '-':{WyrZ.Op = Op_Odejmij;
	    break;}
	case '*':{WyrZ.Op = Op_Mnoz;
	    break;}
	case '/':{WyrZ.Op = Op_Dziel;
	    break;}
	default:{throw runtime_error("Bledny operator wyrazenia zespolonego\n");}
	}
	StrmWej >> WyrZ.Arg2;
	return StrmWej;
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
