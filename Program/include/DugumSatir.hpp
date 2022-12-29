#ifndef DugumSatir_hpp
#define DugumSatir_hpp

class DugumSatir
{
public:
    int value;
    DugumSatir* next;
    DugumSatir* previous;

    DugumSatir(int value=0,DugumSatir* next=nullptr,DugumSatir* previous=nullptr);
};

#endif