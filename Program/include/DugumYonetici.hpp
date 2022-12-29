#ifndef DugumYonetici_hpp
#define DugumYonetici_hpp
#include "SatirListesi.hpp"

class DugumYonetici
{
public:
    SatirListesi* list;
    DugumYonetici* next;
    DugumYonetici* previous;

    DugumYonetici(SatirListesi* listt=NULL,DugumYonetici* next=NULL, DugumYonetici* previous=NULL);
    ~DugumYonetici();  // list verisi de bir pointer olduğundan onu silmek için bir destructor.

};

#endif