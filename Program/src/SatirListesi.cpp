/***********************************************************************\
* @file SatirListesi.cpp
* @description İç içe bağlı liste ile verileri kontrol etmek 
* @course Veri Yapıları 1-B
* @assignment 1
* @date 11/10/2022
* @author Eren Kara errennkaaraa@hotmail.com
\***********************************************************************/

#include "SatirListesi.hpp"
#include <iostream>
#include <iomanip>

using namespace std;

void SatirListesi::AverageCalculation(int value)  // her bir eklemeden sonra average hesaplatıyorum.
{
    total+=value;
    average=total/length;

}
double SatirListesi::GetAverage() 
{
    return average;
}
DugumSatir* SatirListesi::FindPreviousByPosition(int index)  // istenilen indexin bir önceki düğümünü döndürüyor.
{
    if(index<1 || index>length ) throw "Yanlis bir index girdiniz..";
    
    DugumSatir* temp=head;
    for (size_t i = 0; temp!=NULL && index-1!=i; i++)
    {
        temp=temp->next;
    }
    return temp;    
}
DugumSatir* SatirListesi::Head()
{
    return head;
}
SatirListesi::SatirListesi()
{
    head=NULL;
    length=0;
    total=0;
    average=0;
}

int SatirListesi::GetLength()
{
    return length;
}

bool SatirListesi::IsEmpty() // satir listesinin içi boşmu diye kontrol ediyor.
{
    if(head==NULL) return true;
    return false;
}

void SatirListesi::Add(int value)
{
    Insert(length,value);
}

void SatirListesi::Insert(int index, int value) // istenilen bir index'e istenilen bir değeri ekliyor.
{
    
    if (index<0 || index>length ) throw "index out of range";
    if(head==NULL && index==0)
    {
        head=new DugumSatir(value);  // dugum satırın constructurı otomatik oalrak null atıyor next ve previousa 
        ++length;
        AverageCalculation(value);
        return;
    }
    if(index == 0)  // sıfır için ayrı düşündüm 
    {
        DugumSatir* temp=head;
        temp->previous=new DugumSatir(value,temp);  // benim constructer'ın cogu işi benim için yapıyor burda. previos=NULL
        head=temp->previous;
        ++length;
        AverageCalculation(value);
        return;
    }
    
    DugumSatir* temp=FindPreviousByPosition(index);  // rastgele 0 hariç diğer indexlere eleman eklemek.
    
    if(temp->next!=NULL)
    {
        temp->next= new DugumSatir(value,temp->next,temp);
        temp->next->next->previous=temp->next;
    }  
    else
    {
        temp->next= new DugumSatir(value,NULL,temp);
    }
    ++length;
    AverageCalculation(value);
    return;
}

int SatirListesi::IndexOf(int value)  
{
    DugumSatir* temp=head;
    for (size_t i = 0; i < length; i++)
    {
        if (value==temp->value)
        {
            return i;
        }
    }
    return -1;
}

void SatirListesi::Remove()
{
    RemoveAtSatir(length-1);
}

void SatirListesi::RemoveAtSatir(int index)
{
    if(index<0 || index>=length) throw "exception";

    DugumSatir* del=FindPreviousByPosition(index+1);
    if(index==0 )
    {
        head=del->next;
        if (head!=NULL)
            head->previous=NULL;
    } 
    else
    {  
        DugumSatir* temp=FindPreviousByPosition(index);
        temp->next=del->next;
        if(del->next!=NULL)
            temp->next->previous=temp;  
    }
    --length;
    AverageCalculation(-(del->value));
    delete del;
    
    return;
}

void SatirListesi::Print()
{
    DugumSatir* temp=head;
    for (size_t i = 0; i < length; i++)
    {
        cout<<i+1<<". eleman:"<<temp->value<<endl;
        temp=temp->next;
    }   
}

void SatirListesi::PrintReverse()  // tersten yazdırma
{
    DugumSatir* temp=FindPreviousByPosition(length);
    for (size_t i = length-1; i >= 0; --i)
    {
        cout<<i+1<<". eleman:"<<temp->value<<endl;
        temp=temp->previous;
    }
}

void SatirListesi::Clear()
{
    DugumSatir* temp=head;
    DugumSatir* del=temp;
    for (size_t i = 0; i < length; i--) // bütün düğümleri siliyorum
    {
        temp=temp->next;
        delete del;
        del=temp;
    }
    average=0;
    length=0;
    total=0;
    head=NULL;
}

int SatirListesi::ElementAt(int index) // index'teki eleman.
{
    DugumSatir* temp=head;
    for (size_t i = 0; i < index; i++)
    {
        temp=temp->next;
    }
    return temp->value;
}

SatirListesi::~SatirListesi()
{
    Clear();
}

ostream& operator<<(ostream& print, SatirListesi*& list)
{
    print<<setw(15)<<"Dugum Adresi"<<setw(15)<<"veri"<<setw(15)<<"onceki"<<setw(15)<<"sonraki"<<endl;
    DugumSatir* temp=list->head;
    for (int i = 0; i < list->length; i++)
    {
        print<<setw(15)<<temp<<setw(15)<<temp->value<<setw(15)<<temp->previous<<setw(15)<<temp->next<<endl;
        temp=temp->next;
    }
    print<<endl;
    return print;
}