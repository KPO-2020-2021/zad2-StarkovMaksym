#ifndef STATYSTYKI_HH
#define STATYSTYKI_HH



#include "LZespolona.hh"
#include "WyrazenieZesp.hh"

/*
 * Tu nalezy zdefiniowac funkcje, ktore definiuja model statystyki 
 */

struct stat{
	int poprawne;
	int wszystkie;
};


void statystyka(stat odpowiedzi);




#endif
