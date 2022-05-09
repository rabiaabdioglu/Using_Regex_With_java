#ifndef KISI_H
#define KISI_H

#include "Dosya.h"



typedef enum Bool{false, true} boolean;

struct KISI{
	//kullanılacak dosya  icin referans tanım 
	Dosya dosya2;
	//degiskenler
	char **isim;
	double **bakiye;
	double **oran;
	int **sayi;
	boolean **OyundaMi;
	int uzunluk; 	//kişiler.txt nin satır sayısı

	//fonksiyonlar
	int (*kisiSayisi)(struct KISI*);	
	void (*bakiyeGuncelle)(struct KISI*,double**);	
	int (*enZenginBul)(struct KISI*);
	void (*delete_KISI)(struct KISI*);

};
typedef struct KISI* Kisi;

Kisi new_KISI(char**,double**,double**,int**,boolean**,int);

int kisiSayisi(const Kisi); 
void bakiyeGuncelle(const Kisi,double**); 
int enZenginBul(const Kisi);
void delete_KISI(const Kisi);
//soyut sınıfın tanımı
void dosyaAyikla2(const Kisi);

#endif