/***********************************************************************\
* @file Fonksiyonlar.cpp
* @description İç içe bağlı liste ile verileri kontrol etmek 
* @course Veri Yapıları 1-B
* @assignment 1
* @date 11/10/2022
* @author Eren Kara errennkaaraa@hotmail.com
\***********************************************************************/

#include "Fonksiyonlar.hpp"
#include "SatirListesi.hpp"
#include <iostream>
#include <fstream>
#include <string>
#include <conio.h>
#include <Windows.h>
using namespace std;

SatirListesi** GetFromText(string adress, int &rowCount)
{
    ifstream Read;
    string yazi="";
    Read.open(adress, ios::in);
    for (size_t i = 0;!Read.eof(); i++) // satır sayısını bulmak için file'ın içerisinde döndüm
    {
        getline(Read, yazi);
        rowCount++;
    }
    Read.close();
    Read.open(adress, ios::in);
    yazi="";
    SatirListesi** lists=new SatirListesi*[rowCount]; // pointer dizisi oluşturdum.
    for (size_t i = 0;!Read.eof(); i++)  // read end of file
    {
        lists[i]=new SatirListesi();
        getline(Read, yazi);
        int counter=0;
        
        for (size_t j = 0; j < yazi.length(); j++) // text'in bir satırındaki eleman sayisini hespaliyorum.
        {
            if(yazi[j]==' ')
                counter++;
        }
        
        int* numbers = new int[counter];
        for (size_t j = 0; j < counter; j++)
        {   
            numbers[j] = stoi(yazi.substr(0, yazi.find(" ")));    // stoi fonksiyonu stringi integer'a çeviriyor.
            yazi = yazi.substr(yazi.find(" ")+1, yazi.length());  // boşluğu bulduğu kısımdan itibaren seçiyor ve yazinin kalan kısmını döndürüyor.
            lists[i][0].Add(numbers[j]);
            
            // lists[i]->Add(numbers[j]);
        }

        delete[] numbers;
    }
    return lists;
}
void UserInterface()
{
    cout<<endl<<endl;
    cout<<"Z-tusu mavi dugumlerin arasinda geri gitmek icin"<<endl;
    cout<<"C-tusu mavi dugumlerin arasinda ileri gitmek icin"<<endl;
    cout<<"A-tusu bir onceki sayfaya gecmek icin"<<endl;
    cout<<"D-tusu bir sonraki sayfa icin"<<endl;
    cout<<"P-tusu secili mavi dugumu silmek icin"<<endl;
    cout<<"K-secili mavi dugumden rastgele bir yesil dugum silmek icin"<<endl;
    cout<<"ESC-cikis icin"<<endl;
}
void Green()
{
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);
}
void Red()
{
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
}
void LigthBlue()
{
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 9);
}
void White()
{
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
}
char GetKey() // Enter tuşuna basmadan key okumak için
{
    char key;
    key=_getch();
    return key;
}
