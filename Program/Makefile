Tum:Derleme Calistirma

Calistirma:
	.\bin\program.exe
Derleme:DugumSatir DugumYonetici SatirListesi YoneticiListesi Fonksiyonlar Main Link
Main:
	g++ -I ./include/ -c ./src/Main.cpp -o ./lib/Main.o
SatirListesi:
	g++ -I ./include/ -c ./src/SatirListesi.cpp -o ./lib/SatirListesi.o
YoneticiListesi:
	g++ -I ./include/ -c ./src/YoneticiListesi.cpp -o ./lib/YoneticiListesi.o
DugumSatir:
	g++ -I ./include/ -c ./src/DugumSatir.cpp -o ./lib/DugumSatir.o
DugumYonetici:
	g++ -I ./include/ -c ./src/DugumYonetici.cpp -o ./lib/DugumYonetici.o
Fonksiyonlar:
	g++ -I ./include/ -c ./src/Fonksiyonlar.cpp -o ./lib/Fonksiyonlar.o
Link:
	g++ ./lib/Main.o ./lib/SatirListesi.o ./lib/YoneticiListesi.o ./lib/DugumYonetici.o ./lib/DugumSatir.o ./lib/Fonksiyonlar.o -o ./bin/program.exe

