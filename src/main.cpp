#include <iostream>
#include "BazaTestu.hh"
#include "WyrazenieZesp.hh"
#include "Statystyki.hh"
using namespace std;




int main(int argc, char **argv)
{

  if (argc < 2) {
    cout << endl;
    cout << " Brak opcji okreslajacej rodzaj testu." << endl;
    cout << " Dopuszczalne nazwy to:  latwy, trudny." << endl;
    cout << endl;
    return 1;
  }


  BazaTestu   BazaT = { nullptr, 0, 0 };

  if (InicjalizujTest(&BazaT,argv[1]) == false) {
    cerr << " Inicjalizacja testu nie powiodla sie." << endl;
    return 1;
  }


  
  cout << endl;
  cout << " Start testu arytmetyki zespolonej: " << argv[1] << endl;
  cout << endl;

  WyrazenieZesp   WyrZ_PytanieTestowe;
  
 /* while (PobierzNastpnePytanie(&BazaT,&WyrZ_PytanieTestowe)) {
    cout << " Czesc rzeczywista pierwszego argumentu: ";
    cout << WyrZ_PytanieTestowe.Arg1.re << endl;
  }*/

  LZespolona WynikL, Wczytane;
  int a = 0;
  staty odpowiedzi;
  odpowiedzi.poprawne = 0;
  odpowiedzi.wszystkie = 0;

  while (PobierzNastpnePytanie(&BazaT, &WyrZ_PytanieTestowe)) 
  {
    cin.clear();
      WynikL = Oblicz(WyrZ_PytanieTestowe);
      cout << "Podaj wynik operacji: " << WyrZ_PytanieTestowe << endl << "Twoja odpowiedz: ";
      cin >> Wczytane;
      cout << endl;
      while (cin.fail() && a < 2) 
      {
          cerr << "Bledny zapis liczby. Sprobuj jeszcze raz: ";
          cin.clear();
          cin.ignore(10000, '\n');
          cin >> Wczytane;
          cout << endl;
          a++;
      }
      if (WynikL == Wczytane)
      {
          cout << "Odpowiedz poprawna" << endl;
          odpowiedzi.poprawne++;
          cin.clear();
      }
      else 
      {
          cout << "Blad. Prawidlowym wynikiem jest: " << WynikL << endl;
      }
      a = 0;
      odpowiedzi.wszystkie++;
      cout << endl;




  }
  statystyka(odpowiedzi);
  cout << endl;
  cout << " Koniec testu" << endl;
  cout << endl;

}
