#ifndef STATYSTYKI_HH
#define STATYSTYKI_HH



#include "LZespolona.hh"
#include "WyrazenieZesp.hh"

/*
 * Tu nalezy zdefiniowac funkcje, ktore definiuja model statystyki 
 */

struct staty{
	int poprawne;
	int wszystkie;
};


void statystyka(staty odpowiedzi);




#endif
