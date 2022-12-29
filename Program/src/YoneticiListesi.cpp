/***********************************************************************\
* @file YoneticiListesi.cpp
* @description İç içe bağlı liste ile verileri kontrol etmek 
* @course Veri Yapıları 1-B
* @assignment 1
* @date 11/10/2022
* @author Eren Kara errennkaaraa@hotmail.com
\***********************************************************************/

#include "YoneticiListesi.hpp"
#include "Fonksiyonlar.hpp"
#include <iostream>
#include <time.h>
#include <iomanip>

using namespace std;

YoneticiListesi::YoneticiListesi()
{
    start=NULL;
    size=0;
}
int YoneticiListesi::PositionByAverage(double average)  // ortalamaya göre index veriyor ancak o düğüm listede olmaması gerekiyor.
{
    DugumYonetici* temp=start;
    int i;
    for (i = 0; i < size; i++)
    {
        if (average<temp->list->GetAverage()) // bütün satır listesinde dolaşarak average'leri karşılaştır.
        {
            return i;
        }
        temp=temp->next;
    }
    return size;
}
DugumYonetici* YoneticiListesi::FindPreviousNodeByIndex(int index)
{
    if(index<=0 && index>size ) throw  "out of bound";
    DugumYonetici* temp=start;
    for (size_t i = 0; i < index-1; i++)
    {
        temp=temp->next;
    }
    return temp;
}
int YoneticiListesi::NodeSize(int index)  // verilen indexteki düğümün listesinin kaç elemanı var onu hesaplıyor.
{
    DugumYonetici* temp=FindPreviousNodeByIndex(index+1);
    return temp->list->GetLength();
}
void YoneticiListesi::Add(SatirListesi* listt)
{
    double tempAverage=listt->GetAverage();
    if(start==NULL)        // liste boşsa direkt başlangıcına elemanı ekledim
    {
        start=new DugumYonetici(listt); // aritmetik ortalamaya göre yap bunu
        size++;
    }  
    else if(PositionByAverage(tempAverage)==0) // indexi eğerki 0'sa ayrı düşündüm head veya start bizim için önemli
    {
        start->previous=new DugumYonetici(listt,start,NULL);
        start=start->previous;
        size++;
    }
    else // diğer durumlar için
    {
        DugumYonetici* temp=FindPreviousNodeByIndex(PositionByAverage(tempAverage));
        DugumYonetici* tempNext=temp->next;
        temp->next=new DugumYonetici(listt,NULL,temp);
        
        if(tempNext!=NULL)
        {
            tempNext->previous=temp->next;
            temp->next->next=tempNext;
        }
        size++;
    }
}
void YoneticiListesi::AddLinkedListArray(SatirListesi** lists,int rowCount) // başka bir yerde listeleri oluşturdum buraya transfer ettim.
{
    for (int i = 0; i<rowCount; i++)
    {
        Add(lists[i]);
    }
    cout<<endl;
}
void YoneticiListesi::Remove()
{
    RemoveAt(size-1);
}
void YoneticiListesi::RemoveAt(int index)
{
    if(index<0 && index>size) return;
    
    DugumYonetici* del;
    if(index==0)  // index 0'sa ordaki elemanı silme
    {
        del=start;
        if(del->next!=NULL) // sileceğim düğüm son düğüm mü diye baktım.
        {
            del->next->previous=NULL;
            start=del->next;
        }
    }
    else
    {
        del=FindPreviousNodeByIndex(index+1); 
        if(del->next!=NULL) // sileceğim düğüm son düğüm mü diye baktım.
        {
            del->previous->next=del->next;
            del->next->previous=del->previous;
        }
        else // sileceğim düğüm son düğümse onu sileceğim için ondan öncekinin nextini null yaptım.
        {
            del->previous->next=NULL;
        }
    }
    delete del;
    size--;
}
ostream& operator<<(ostream& print, YoneticiListesi*& list)
{
    print<<setw(15)<<"Dugum Adresi"<<setw(15)<<"veri"<<setw(15)<<"onceki"<<setw(15)<<"sonraki"<<endl;
    DugumYonetici* temp=list->start;
    for (int i = 0; i < list->size; i++)
    {
        print<<setw(15)<<temp<<setw(15)<<temp->list->GetAverage()<<setw(15)<<temp->previous<<setw(15)<<temp->next<<endl;
        temp=temp->next;
    }
    print<<endl;
    return print;
}
void YoneticiListesi::PrintDebug() // dugumleri bastırdım hatam var mı diye.
{
    DugumYonetici* temp=start;
    for (size_t i = 0; i < size; i++)
    {
        cout<<temp->list;
        temp=temp->next;
    }
}
void YoneticiListesi::YoneticiDugumunListesiPrint(int openedPage, int selectedYoneticiDugum,int pageNumber,int selectedSatirDugum)
{
    DugumYonetici* temp=FindPreviousNodeByIndex(selectedYoneticiDugum+1);
    DugumSatir* current=temp->list->Head();
    for (size_t i = 0; i < NodeSize(selectedYoneticiDugum)*6+1; i++)  // yoneticidugumun listesinin dugum sayısının 6 katı kadar dönüyor.
    {  
        if(i>selectedSatirDugum*6&&i<=(selectedSatirDugum+1)*6) // seçili olan düğümü kırmızı ile gösterdim.
        {
            Red();
        }
        else
        {
            Green();
        }
        if(i%6==1&&i!=1)  // her 6 tane bir diğer düğüme geçtim çünkü bir düğümü basmak için 6 iterasyon gerekiyor
        // her bir iterasyonda ya düğümün adresini yazdırdım ya araya bir çizgi koydurdum ya da değerini felan bastırdım.
        {
            current=current->next;
            cout<<endl;
        }
        for (size_t j = (openedPage-1)*8; j <openedPage*8 ; j++) // açık olan sayfanın başından sonuna kadar
        {
            if(j>=size) // son sayfa için. size'a kadar gitsin orda break'lesin.
            {
                break;
            }
            if(j!=selectedYoneticiDugum)
            { 
                cout<<setw(14)<<right<<"";
            }
            else
            {
                break;
            }
        }
        if (i==0)
        {
            White();
            cout<<"^^^^^^^^^^^"<<setw(3)<<"";
        }
        else if(i%6==1)
        {
            cout<<" "<<setw(9)<<right<<current<<setw(3)<<"";
        }
        else if (i%6==3)
        {
            cout<<"|"<<setw(9)<<right<<current->value<<"|"<<setw(3)<<"";
        }
        else if (i%6==5)
        {
            cout<<"|"<<setw(9)<<right<<current->next<<"|"<<setw(3)<<""  ;
        }
        else if(i!=0)
        {
            cout<<"-----------";
        }
        cout<<endl;
    }
    White();
}
void YoneticiListesi::YoneticiDugumleriPrint(int openedPage, int selectedYoneticiDugum,int pageNumber)
{
    DugumYonetici* temp=FindPreviousNodeByIndex(((openedPage-1)*8)+1);   
    
    for (size_t i = 0; i < 9; i++)
    {
        temp=FindPreviousNodeByIndex(((openedPage-1)*8)+1);
        
        for (size_t j = (openedPage-1)*8; j < openedPage*8; j++)  // açık olan sayfanın başından sonuna kadar gidiyor.
        {
            if(j>=size) // son sayfa için. Eğer daha az sayıda bir eleman varsa break'liyor.
            {
                break;
            }
            if (j==selectedYoneticiDugum)  // seçili olan düğümü renklendirmek için.
            {
                LigthBlue();
            }
            if(i==0)
            {
                if(j==(openedPage-1)*8 && openedPage==1)
                {
                    cout<<setw(14)<<left<<"ilk";
                }
                else if(j==(openedPage-1)*8)
                {
                    cout<<setw(14)<<left<<"<---";
                }
                else if(j==size-1)
                {
                    cout<<setw(11)<<right<<"son";
                }
                else if(j==openedPage*8-1)
                {
                    cout<<setw(11)<<right<<"--->";
                }
                else
                {
                    cout<<setw(14)<<""; // 10 tane
                }
            }
            else if(i%2==0)  // i'nin durumuna göre basmayı ayarladım.
            {
                cout<<"-----------"<<setw(3)<<"";
            }
            else if(i==1)
            {
                cout<<" "<<setw(9)<<right<<temp<<" "<<setw(3)<<"";
            }
            else if(i==3)
            {
                cout<<"|"<<setw(9)<<right<<temp->previous<<"|"<<setw(3)<<"";
            }
            else if(i==5)
            {
                cout<<"|"<<setw(9)<<right<<temp->list->GetAverage()<<"|"<<setw(3)<<"";
            }
            else if(i==7)
            {
                cout<<"|"<<setw(9)<<right<<temp->next<<"|"<<setw(3)<<"";
            }
            
            temp=temp->next;
            
            White();
        }
        cout<<endl;
    } 
}
void YoneticiListesi::IndexUpdate(int index)
{
    if(index==0)
    {
        DugumYonetici* current=start;
        double average=current->list->GetAverage();  // suanda bu yerini degistirecegim dugumu tutuyor.
        start->next->previous=NULL;
        size--;  // aşağıdaki yazmış olduğum fonksiyonlar size üzerinden hesaplamalar yaptığı için size'ı bir azaltmam gerekti.
        start=start->next; // bu satırlarda yerini degistirecegim dugumu dugumler arasından cıkardım.
        current->next = current->previous=NULL;
        int newPosition=PositionByAverage(average);  // newPosition dugumun yeni adresi oluyor
        if(newPosition==0)  // 0'sa düğümün öncesi olmayacağından bu durumu ayrı düşündüm.
        {
            current->next=start;
            current->previous=NULL;
            start->previous=current;
            start=current;
        }
        else if(newPosition==size)  // son düğümse düğümün sonrası olmayacağından bu durumu ayrı düşündüm.
        {
            DugumYonetici* temp= FindPreviousNodeByIndex(size);
            temp->next=current;
            current->previous=temp;
            current->next=NULL;
        }
        else
        {
            DugumYonetici* temp= FindPreviousNodeByIndex(newPosition);
            temp->next->previous=current;
            current->next=temp->next;
            temp->next=current;
            current->previous=temp;
        }
        
    }
    else
    {
        // ilk once baglı listeden silip ondan sonra yerini bulup sonra tekrar ekliyorum.
        DugumYonetici* current = FindPreviousNodeByIndex(index+1);
        double average = current->list->GetAverage();
        DugumYonetici* lastNode=FindPreviousNodeByIndex(size);
        if(current!=lastNode)  // son düğümse next'inin previousu olmayacağından onu kontrol ettim.
        { 
            current->next->previous=current->previous;
        }
        current->previous->next=current->next;
        current->next=current->previous=NULL;
        size--;

        lastNode=FindPreviousNodeByIndex(size); // indexler degistigi icin ve suan last node da degisti belki current lastnode'du.
        int newPosition= PositionByAverage(average);
        if(newPosition==0)      // 0'sa düğümün öncesi olmayacağından bu durumu ayrı düşündüm.
        {
            current->next=start;
            current->previous=NULL;
            start->previous=current;
            start=current;
        }
        else if(newPosition==size)      // son düğümse düğümün sonrası olmayacağından bu durumu ayrı düşündüm.
        {
            DugumYonetici* temp= FindPreviousNodeByIndex(size);
            temp->next=current;
            current->previous=temp;
            current->next=NULL;
        }
        else // diğer durumlar
        {
            DugumYonetici* temp= FindPreviousNodeByIndex(newPosition);
            temp->next->previous=current;
            current->next=temp->next;
            temp->next=current;
            current->previous=temp;
        }
    }
    size++;
}
void YoneticiListesi::PrintForSchool()
{
    srand(time(0));
    int selectedYoneticiDugum=0;  // 0. indexli eleman
    int openedPage=1;            // 1. sayfa diye yazdım
    char key;
    bool isPressed=false;  // K tuşuna basıldı mı diye kontrol ediyor.
    int selectedSatirDugum=-1;  // K tuşu ile herhangi bir düğüm seçilmediyse -1 başlangıç değerini verdim.
    int pageNumber=((size-1)/8)+1;
    do
    {
        system("cls");
        YoneticiDugumleriPrint(openedPage,selectedYoneticiDugum,pageNumber);
        YoneticiDugumunListesiPrint(openedPage,selectedYoneticiDugum,pageNumber,selectedSatirDugum);
        UserInterface();
        key=GetKey();
        switch (key)
        {
        case 'z':  
            if (selectedYoneticiDugum>(openedPage-1)*8)  // sayfanın başlangıcındaki düğümden gerisine gidemesin diye
            {
                selectedYoneticiDugum--;
                isPressed=false;
                selectedSatirDugum=-1;
            }
            break;
        case 'c':
            if (selectedYoneticiDugum<openedPage*8-1 && selectedYoneticiDugum < size-1  )  // sayfanın sonundaki düğümden ileri gidemesin diye
            {
                selectedYoneticiDugum++;
                isPressed=false;
                selectedSatirDugum=-1;
            }
            break;
        case 'a':       
            if (openedPage>1) // sayfa sayısı 1'den daha düşük olamaz 
            {
                openedPage--;
                selectedYoneticiDugum=(openedPage-1)*8;
                isPressed=false;
                selectedSatirDugum=-1;
            }
            break;
        case 'd':
            if (openedPage<pageNumber)      // açık olan sayfa, sayfa sayısından daha büyük olamaz 
            {
                openedPage++;
                selectedYoneticiDugum=(openedPage-1)*8;
                isPressed=false;
                selectedSatirDugum=-1;
            }
            break;
        case 'p':  // düğümü silmek için
            RemoveAt(selectedYoneticiDugum);
            if(selectedYoneticiDugum>=size)
            {
                selectedYoneticiDugum--;
                if(size==0)  // eğerki geriye bir düğüm kalmamışsa uygulamadan çıksın diye
                {
                    key=27;
                }
            }
            pageNumber=((size-1)/8)+1;
            if(openedPage>pageNumber)  // son sayfadaki bir düğümü sildiyse ve o sayfadaki son düğümse bir önceki sayfaya döndüm.
            {
                openedPage--;
            }
            
            isPressed=false;
            selectedSatirDugum=-1;
            break;    
        case 'k':
            if(!isPressed)
            {
                selectedSatirDugum=rand() % NodeSize(selectedYoneticiDugum); // rastgele bir satir düğüm seçtim
                isPressed=true;
            }
            else
            {
                DugumYonetici* temp=FindPreviousNodeByIndex(selectedYoneticiDugum+1); 
                temp->list->RemoveAtSatir(selectedSatirDugum);
                
                if(temp->list->GetLength()==0)  // seçili düğümde satir düğümü kalmamışsa o düğümü sildim
                {
                    RemoveAt(selectedYoneticiDugum);
                    if(selectedYoneticiDugum>=size)
                    {
                        selectedYoneticiDugum--;
                        if(size==0) // eğerki geriye bir düğüm kalmamışsa uygulamadan çıksın diye
                        {
                            key=27;
                        }
                    }
                    pageNumber=((size-1)/8)+1;
                    if(openedPage>pageNumber)// son sayfadaki bir düğümü sildiyse ve o sayfadaki son düğümse bir önceki sayfaya döndüm.
                    {
                        openedPage--;
                    }
                }
                else
                {
                    IndexUpdate(selectedYoneticiDugum); // satir düğümü sildiğimde değişen ortalamya göre indexleri güncelledim
                }
                
                isPressed=false;
                selectedSatirDugum=-1;
            }
            break;
        default:
            break;
        }
        
    } while (key!=27); // ESC tusu
    cout<<endl<<"Cikis Yaptiniz!";
}
void YoneticiListesi::Clear()  // bütün bağlı listeyi temizlemek için
{
    DugumYonetici* temp=start;
    DugumYonetici* del=temp;
    for (size_t i = 0; i < size; i++)
    {
        temp=temp->next;
        delete del;
        del=temp;
    }
    start=NULL;
    size=0;   
}
YoneticiListesi::~YoneticiListesi()
{
    Clear();
}




// kullanmadığım ama yine de bir kalsın dediğim methodlar

// void YoneticiListesi::Cizgi(int openedPage, int selectedYoneticiDugum,int pageNumber)
// {
//     for (size_t i=(openedPage-1)*8; i < openedPage*8; i++)
//     {
//         cout<<"-----------"<<setw(3)<<"";
//     }
// }
// void YoneticiListesi::SatirYazdir(int hangisi,string sekil,int openedPage, int selectedYoneticiDugum,int pageNumber)
// {
//     // 0 yonetici dugum 
//     // 3 yonetici dugum sayi
//     DugumYonetici* temp=FindPreviousNodeByIndex(((openedPage-1)*8)+1); 
//     DugumSatir* current=temp->list->Head();
    
//     for (size_t i = (openedPage-1)*8; i < openedPage*8; i++)
//     {
//         if(i>=size)
//         {
//             break;
//         }
//         if(hangisi==0)
//         {
//             if (i==selectedYoneticiDugum)
//             {
//                 LigthBlue();
//             }
//             cout<<sekil<<setw(9)<<right<<temp<<sekil<<setw(3)<<"";
//             temp=temp->next;
//         }
//         else if(hangisi==1)
//         {
//             Green();
//             if(i==selectedYoneticiDugum)
//             {
//                 cout<<sekil<<setw(9)<<right<<current<<sekil<<setw(3)<<"";
//             }
//             else
//             {
                
//             }
            
//             current=current->next;
//         }
//         else if(hangisi==2)
//         {
//             Green();
//             cout<<sekil<<setw(9)<<right<<current->value<<sekil<<setw(3)<<"";
//             current=current->next;
//         }
//         else
//         {
//             cout<<sekil<<setw(9)<<right<<temp->list->GetAverage()<<sekil<<setw(3)<<"";
//             temp=temp->next;
//         }
        
//         White();
//         temp=temp->next;
//     }
// }