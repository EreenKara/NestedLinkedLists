#ifndef SatirListesi_hpp
#define SatirListesi_hpp
#include "DugumSatir.hpp"
#include<iostream>

using namespace std;

class SatirListesi
{
private:
    DugumSatir* head;
    int length;
    double total;
    double average;
    DugumSatir* FindPreviousByPosition(int index); 
    void AverageCalculation(int value);     // her bir eklemeden sonra ortalama hesaplattığım fonksiyon.

public:
    DugumSatir* Head();
    SatirListesi(); 
    int GetLength();  // satir listesinin düğümlerinin sayısı.
    double GetAverage();
    bool IsEmpty();  // satir listesi bosmu diye kontrol ediyor.
    void Add(int item);
    void Insert(int index, int value);
    int IndexOf(int value);  // varsa indexini yoksa -1 donduruyor.
    void Remove();  // sondan 1 eleamn siliyor.
    void RemoveAtSatir(int index);  // istenilen bir indexten 1 eleman siliyor.
    void Print();  
    void PrintReverse();   // Tersten basıyor. 
    void Clear();
    int ElementAt(int index);
    friend ostream& operator<<(ostream& print, SatirListesi*& list);
    ~SatirListesi();
};

#endif