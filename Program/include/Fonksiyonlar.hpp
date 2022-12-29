#ifndef Fonksiyonlar_hpp
#define Fonksiyonlar_hpp
#include "SatirListesi.hpp"

SatirListesi** GetFromText(string adress,int& rowCount);
void UserInterface(); // switch case ile 1 2 3 basınca bu olacak diye yaz 
char GetKey(); // _getch ile karakter oku
void LigthBlue(); // secili olanı kırmızı yap. 
void Red();
void Green();
void White(); // beyaza geri dön.

#endif