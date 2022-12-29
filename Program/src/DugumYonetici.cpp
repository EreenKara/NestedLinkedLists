/***********************************************************************\
* @file DugumYonetici.cpp
* @description İç içe bağlı liste ile verileri kontrol etmek 
* @course Veri Yapıları 1-B
* @assignment 1
* @date 11/10/2022
* @author Eren Kara errennkaaraa@hotmail.com
\***********************************************************************/

#include "DugumYonetici.hpp"
#include <iostream>
using namespace std;

DugumYonetici::DugumYonetici(SatirListesi* listt,DugumYonetici* next,DugumYonetici* previous)
{
    this->list=listt;
    this->next=next;
    this->previous=previous;
}

// değer verildiyse ilk atamalarını yapıyor. Değer verilmediyse NULL atıyor.

DugumYonetici::~DugumYonetici()
{
    delete list;
}