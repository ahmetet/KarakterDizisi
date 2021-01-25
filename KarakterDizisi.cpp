#include "KarakterDizisi.h"
#include <stdlib.h>


KarakterDizisi::KarakterDizisi() {
	setlocale(LC_ALL, "turkish");
	this->_KarakterDizisi = new char[2];
	this->_KarakterDizisi[0] = '\0';
	this->uzunluk = 0;
}
void KarakterDizisi::operator=(const KarakterDizisi KD) {

	if (KD.uzunluk == 1) {
		this->_KarakterDizisi = new char[2];
		this->_KarakterDizisi[0] = KD._KarakterDizisi[0];
		this->_KarakterDizisi[1] = '\0';
	}
	else {
		int say = 0;
		this->_KarakterDizisi = new char[KD.uzunluk];
		this->_KarakterDizisi[KD.uzunluk] = '\0';
		while (KD._KarakterDizisi[say] != '\0') {
			this->_KarakterDizisi[say] = KD._KarakterDizisi[say];
			say = say + 1;
		}

	}
	this->uzunluk = KD.uzunluk;

}
void KarakterDizisi::operator=(const char sagVeri) {
	this->_KarakterDizisi = new char[2];
	this->_KarakterDizisi[0] = sagVeri;
	this->_KarakterDizisi[1] = '\0';
	this->uzunluk = 1;

}


void KarakterDizisi::operator=(const char *sagVeri) {
	int say = 0;
	while (sagVeri[say] != '\0') {
		say = say + 1;
	}
	this->uzunluk = say;
	this->_KarakterDizisi = new char[say];
	this->_KarakterDizisi[say] = '\0';

	say = 0;
	while (sagVeri[say] != '\0') {
		this->_KarakterDizisi[say] = sagVeri[say];
		say = say + 1;
	}

}

KarakterDizisi KarakterDizisi::operator+(const char sagVeri)
{
	char*yeni = new char[this->uzunluk + 2];//uzunluk \0 -1 verecek yani 2 ekle hem yeni char hemn \0 için
	
	int say = 0;
	while (say < this->uzunluk) {
		yeni[say] = this->_KarakterDizisi[say];
		say = say + 1;
	}
	yeni[this->uzunluk] = sagVeri;
	yeni[this->uzunluk + 1] = '\0';

	
	KarakterDizisi YeniDizi;
	YeniDizi = yeni;

	return YeniDizi;
}
KarakterDizisi KarakterDizisi::operator+(const char * sagVeri)
{	
	KarakterDizisi Hack;
	Hack = sagVeri;
	char*yeni = new char[this->uzunluk + Hack.Uzunluk()];//uzunluk \0 -1 verecek yani 2 ekle hem yeni char hemn \0 için

	int say = 0;
	while (say < this->uzunluk) {
		yeni[say] = this->_KarakterDizisi[say];
		say = say + 1;
	}
	int say2 = 0;
	while (sagVeri[say2] != '\0') {
		yeni[say] = sagVeri[say2];

		say2 = say2 + 1;
		say = say + 1;
	}
	yeni[this->uzunluk + Hack.Uzunluk()] = '\0';


	KarakterDizisi YeniDizi;
	YeniDizi = yeni;

	return YeniDizi;

}
KarakterDizisi KarakterDizisi::operator+(const KarakterDizisi _KD)
{
	KarakterDizisi Son;
	KarakterDizisi Ben;
	KarakterDizisi O;

	Ben = this->_KarakterDizisi;
	O = _KD;

	Son = Ben + O.Al();

	return Son;


}
ostream & operator<<(ostream &CiktiParcacigi, const KarakterDizisi KD)
{
	int say = 0;
	while (KD._KarakterDizisi[say] != '\0') {
		CiktiParcacigi << KD._KarakterDizisi[say];
		say = say + 1;
	}
	return CiktiParcacigi;
}

int KarakterDizisi::Uzunluk() {

	return (int)this->uzunluk;

}

void KarakterDizisi::BuyukHarflereCevir() {
	int say = 0;
	while (say < this->uzunluk) {
		char olay = this->_KarakterDizisi[say];
		olay &= ~' ';
		this->_KarakterDizisi[say] = olay;
		say = say + 1;
	}
}

void KarakterDizisi::KucukHarflereCevir() {
	int say = 0;
	while (say < this->uzunluk) {
		char olay = this->_KarakterDizisi[say];
		olay |= ' ';
		this->_KarakterDizisi[say] = olay;
		say = say + 1;
	}
}
 

char* KarakterDizisi::Al() {
	char* Son = new char[this->uzunluk];
	int basla = 0;
	while (basla < uzunluk) {
		Son[basla] = _KarakterDizisi[basla];
		basla = basla + 1;
	}
	Son[basla] = '\0';
	return Son;
}



bool KarakterDizisi::operator ==(const KarakterDizisi KD) {
	KarakterDizisi Bu;
	KarakterDizisi O;
	O = KD;
	Bu = this->_KarakterDizisi;

	if (Bu == O.Al()) {
		return true;
	}
	else {
		return false;
	}

	//temiz bir bootstrapping 
}
bool KarakterDizisi::operator ==(const char sagVeri) {

	if (this->uzunluk != 1) {
		return false;
	}
	else {
		if (this->_KarakterDizisi[0] == sagVeri) {
			return true;
		}
		else {
			return false;
		}
	}
}
bool KarakterDizisi::operator ==(const char *sagVeri) {
	KarakterDizisi Sagdaki;
	Sagdaki = sagVeri;
	if (this->uzunluk != Sagdaki.Uzunluk()) {
		return false;
	}
	else {
		int say = 0;
		while (this->_KarakterDizisi[say] != '\0') {
			if (this->_KarakterDizisi[say] != sagVeri[say]) {
				return false;
			}
			say = say + 1;
		}
		return true;
	}


}