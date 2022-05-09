#ifndef OYUN_H
#define OYUN_H

//kisi h da dosya .h tanımı yapıldıgı icin burada gerek yok 
#include "Kisi.h"


struct OYUN{

	//kisi ve dosya icin referans tanım
	Kisi kisi;
	Dosya dosya;
	//degiskenler
	double masaBakiye;
	int **sansliSayi;
	int turSayisi;
	int enZengin;
	int simdikiSansliSayi; 
	
	//fonksiyonlar
	void (*masaGuncelle)(struct OYUN*,double);
	void (*oyunBasla)(struct OYUN*);
	void (*yaz)(struct OYUN*);
	void (*delete_Oyun)(struct OYUN*);
};
typedef struct OYUN* Oyun;

//fonksiyonlar
Oyun new_Oyun(double,int**,int,int,int);
void oyunBasla(const Oyun);
void masaGuncelle(const Oyun, double );
void yaz(const Oyun);
void delete_Oyun(const Oyun);

//soyut sınıfın tanımı
void dosyaAyikla1(const Oyun);


#endif