#include "Statystyki.hh"
using namespace std;
#include <iostream>

/*
 * Tu nalezy zdefiniowac funkcje, ktorych zapowiedzi znajduja sie
 * w pliku naglowkowym.
 */

void statystyka(stat odpowiedzi) 
{
	cout << "Ilosc poprawnych odpowiedzi:" << odpowiedzi.poprawne << endl;
	cout << "Ilosc blednych odpowiedzi:" << odpowiedzi.wszystkie - odpowiedzi.poprawne << endl;
	cout << "Wynik procentowy poptawnych odpowiedzi:" << (odpowiedzi.poprawne * 100) / odpowiedzi.wszystkie << "%" << endl;

}