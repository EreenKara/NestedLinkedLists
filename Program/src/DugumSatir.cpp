/***********************************************************************\
* @file DugumSatir.cpp
* @description İç içe bağlı liste ile verileri kontrol etmek 
* @course Veri Yapıları 1-B
* @assignment 1
* @date 11/10/2022
* @author Eren Kara errennkaaraa@hotmail.com
\***********************************************************************/

#include "DugumSatir.hpp"

DugumSatir::DugumSatir(int value,DugumSatir* next,DugumSatir* previous)
{
    this->value=value;
    this->next=next;
    this->previous=previous;
}

// değer verildiyse ilk atamalarını yapıyor. Değer verilmediyse ya 0 ya da NULL atıyor.
