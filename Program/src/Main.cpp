/**********************************************************************\
**				         	SAKARYA ÜNİVERSİTESİ
**				  BİLGİSAYAR VE BİLİŞİM BİLİMLERİ FAKÜLTESİ
**				     BİLGİSAYAR MÜHENDİSLİĞİ BÖLÜMÜ
**					       VERİ YAPILARI DERSİ
**
**		   	  ÖDEV NUMARASI.............:   1
**			  ÖĞRENCİ ADI...............:   Eren Kara
**			  ÖĞRENCİ NUMARASI..........:   B211210031
**			  DERS GRUBU................:   1-B
\***********************************************************************/

/***********************************************************************\
* @file main.cpp
* @description İç içe bağlı liste ile verileri kontrol etmek 
* @course Veri Yapıları 1-B
* @assignment 1
* @date 11/10/2022
* @author Eren Kara errennkaaraa@hotmail.com
\***********************************************************************/


#include <iostream>
#include "DugumSatir.hpp"
#include "DugumYonetici.hpp"
#include "SatirListesi.hpp"
#include "YoneticiListesi.hpp"
#include "Fonksiyonlar.hpp"

using namespace std;
int main(int argc,char** argv)
{
    YoneticiListesi* yonetici=new YoneticiListesi();
    int rowCount=0;
    SatirListesi **list = GetFromText("veriler.txt", rowCount);
    yonetici->AddLinkedListArray(list,rowCount);
    yonetici->PrintForSchool();
    
    delete yonetici;

    
    return 0;
}