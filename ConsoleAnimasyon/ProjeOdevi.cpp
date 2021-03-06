// ProjeOdevi.cpp : Bu dosya 'main' işlevi içeriyor. Program yürütme orada başlayıp biter.
//
/****************************************************************************
**					SAKARYA ÜNİVERSİTESİ
**			         BİLGİSAYAR VE BİLİŞİM BİLİMLERİ FAKÜLTESİ
**				    BİLGİSAYAR MÜHENDİSLİĞİ BÖLÜMÜ
**				          PROGRAMLAMAYA GİRİŞİ DERSİ
**
**				ÖDEV NUMARASI…...: Proje
**				ÖĞRENCİ ADI...............: Merve Yıldızer
**				ÖĞRENCİ NUMARASI.: B181210377
**				DERS GRUBU…………: 1B
****************************************************************************/

#include "pch.h"
#include <iostream>
#include <Windows.h>
#include <iomanip>
#include <time.h>
#include <conio.h>
using namespace std;


enum YON {

	YON_SAG = 1,
	YON_SOL = 2,
	YON_ASAGI = 3,
	YON_YUKARI = 4,
	YON_atesEt



};
struct UcakOlustur {
	int x;
	int y;
	char karakter;
	YON yon;


};
struct AtesEt {
	int x;
	int y;
	char karakter;
	YON yon;

};
struct Dusman {
	int x;
	int y;
	char karakter;
	YON yon;

};


const int genislik = 80;
const int yukseklik = 20;
const int ucakBoyutu = 5;
const int atesSayisi = 500;
const int dusmanBoyutu = 3;
int dusmanBoyutu1 = 3;
char sahne[genislik][yukseklik];
char tuslar[256];
int ates = 55;

UcakOlustur UcakDizi[ucakBoyutu];
Dusman DusmanDizi[dusmanBoyutu][dusmanBoyutu];
AtesEt AtesDizi[atesSayisi];



void gotoxy(int x,int y){
	COORD coord;
	coord.X = x;
	coord.Y = y;

	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);


}
void cursorGizle() {
	HANDLE out = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO cursorInfo;
		GetConsoleCursorInfo(out, &cursorInfo);
			cursorInfo.bVisible = false;
		SetConsoleCursorInfo(out, &cursorInfo);

}

void atesEtOlustur() {


for (int i = 0; i < atesSayisi; i++) {

		AtesDizi[i].x = UcakDizi[2].x+1;
		AtesDizi[i].y = UcakDizi[2].y;
		AtesDizi[i].karakter = 219;
		AtesDizi[i].yon = YON_SAG;

	}
	
}
void atesSahnede() {

	for (int i = 0; i < atesSayisi; i++) {


		int x = AtesDizi[i].x;
		int y = AtesDizi[i].y;

		sahne[x][y] = AtesDizi[i].karakter;
	}

}
void atesHareketEt() {

	for (int i = 0; i < atesSayisi; i++) {
		AtesDizi[i].x++;
	}
}


void ucakCiz() {
	
	for (int i = 0; i < 5; i++) {


		if (i < 2)
		{
			UcakDizi[i].x = 1 + i;
			

		}
		else
		{
			UcakDizi[i].x = 5-i;
			
		}
		UcakDizi[i].y = 7 + i;
		UcakDizi[i].karakter = 219;
	}
}

void UcakSahnede()
{
	for (int i = 0; i < ucakBoyutu; i++) {
		int x = UcakDizi[i].x;
		int y = UcakDizi[i].y;
		sahne[x][y] = 219;
	}

}

void ucakHareketEttir()
{

	if (tuslar['S'] != 0 || tuslar['D'] != 0) {
		for (int i = 0; i < ucakBoyutu; i++) {

			switch (UcakDizi[i].yon) {
			case YON_YUKARI:
				UcakDizi[i].y--;
				break;
			case YON_ASAGI:
				UcakDizi[i].y++;
			default:
				break;

			}

		}


	}
	else
		return;
	
	

}

void DusmanCiz() {

	
	int sayi;
	sayi = rand() % 10 + 1;
	


		for (int i = 0; i < dusmanBoyutu1; i++) {
			for (int j = 0; j < dusmanBoyutu1; j++) {


				DusmanDizi[i][j].x = 78 + j;
				DusmanDizi[i][j].y = sayi + i;
				DusmanDizi[i][j].karakter = 220;
				DusmanDizi[i][j].yon = YON_SOL;
			}

		}
	
}


void DusmanHaraketEttir()
{
	for (int i = 0; i < dusmanBoyutu1; i++) {
		for (int j = 0; j < dusmanBoyutu1; j++) {

			DusmanDizi[i][j].x--;

		}
			
	}
}
void DusmanSahnede() {

	for (int i = 0; i < dusmanBoyutu1; i++) {
		for (int j = 0; j < dusmanBoyutu1; j++) {


			int x = DusmanDizi[i][j].x;
			int y = DusmanDizi[i][j].y;

			sahne[x][y] = DusmanDizi[i][j].karakter;
		}

	}

}
void SahneyiCiz() {

	for (int y = 0; y < yukseklik; y++)
	{
		for (int x = 0; x < genislik; x++)
		{
			cout << sahne[x][y];
		}
		cout << endl;

	}

}
void sahneyiTemizle() 
{
	for (int y = 0; y < yukseklik; y++) 
	{

		for (int x = 0; x < genislik; x++) 
		{
			sahne[x][y] = ' ';
			
		}
	}
}
void sinirlariOlustur()
{
	for (int x = 0; x < genislik; x++)
	{
		sahne[x][0] = 219;
		sahne[x][yukseklik - 1] = 219;
	}
	for (int y = 0; y < yukseklik; y++) {
		sahne[0][y] = 219;
		sahne[genislik - 1][y] = 219;
	}
}
void klavyeOku(char tuslar[])
{
	int x;
	for ( x = 0; x < 256; x++) {

		tuslar[x] = (char)(GetAsyncKeyState(x) >> 8);
	}
}
void klavyeKontrol()
{
	klavyeOku(tuslar);
	
	if (tuslar['A'] != 0) {
		for (int i = 0; i < atesSayisi; i++) {
			AtesDizi[i].yon = YON_SAG;
		}	
	}if (tuslar['S'] != 0) {
		for (int i = 0; i < ucakBoyutu; i++) {
			UcakDizi[i].yon = YON_YUKARI;
		}

	}if (tuslar['D'] != 0) {
		for (int i = 0; i < ucakBoyutu; i++) {
			UcakDizi[i].yon = YON_ASAGI;
		}
	}
}
int main()
{
	srand(time(NULL));
	sinirlariOlustur();
	cursorGizle();
	ucakCiz();
	DusmanCiz();
	
	while (true) {
		
		
		sahneyiTemizle();
		sinirlariOlustur();
		klavyeKontrol();
		UcakSahnede();
		DusmanSahnede();
		DusmanHaraketEttir();
		ucakHareketEttir();
		if (tuslar['A'] != 0) {

			atesEtOlustur();
		}
		atesSahnede();
		atesHareketEt();
		gotoxy(0, 0);
		SahneyiCiz();
		Sleep(80);
	}
	system("pause");

}

