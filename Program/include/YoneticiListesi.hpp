#ifndef YoneticiListesi_hpp
#define YoneticiListesi_hpp
#include "DugumYonetici.hpp"

class YoneticiListesi
{
private:
    DugumYonetici* start;
    int size;
    int PositionByAverage(double average);  // ortalamaya göre index buldum
    DugumYonetici* FindPreviousNodeByIndex(int index);  // indexin bir önceki elemanı
    int NodeSize(int index);  // indexteki elemanın listesinde kaç tane düğüm var.
    void IndexUpdate(int index);  // K tuşuna basarak sildiğimde değişen ortalamalara göre listeyi düzenliyor.
    void YoneticiDugumunListesiPrint(int openedPage, int selectedYoneticiDugum,int pageNumber,int selectedSatirDugum);  
    // Yonetici dugumlerin listesisini bastım.
    void YoneticiDugumleriPrint(int openedPage, int selectedYoneticiDugum,int pageNumber);
    // Yonetici dugumleri bastım.


    // void SatirYazdir(int hangisi,string sekil,int openedPage, int selectedYoneticiDugum,int pageNumber);
    // void Cizgi(int openedPage, int selectedYoneticiDugum,int pageNumber);

public:
       
    YoneticiListesi(); // bailangıç değerlerini atadım
    friend ostream& operator<<(ostream& print, YoneticiListesi*& list);
    void Add(SatirListesi* ); // herhangi bir satir listesi eklemek için
    void AddLinkedListArray(SatirListesi** lists,int rowCount );  // sınıf dışı bir yeden okuduğum listeleri burda bu sınıfa aktardım.
    void Remove();
    void RemoveAt(int index);
    void PrintDebug();  // programım çalışıyor mu diye kontrol ederken kullandığım print yöntemi.
    void PrintForSchool();  // Bizden istenilen sekilde bağlı listeleri basıyor.
    void Clear();
    ~YoneticiListesi();
};
#endif