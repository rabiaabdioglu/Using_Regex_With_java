#ifndef DOSYA_H
#define DOSYA_H

#include "string.h"
#include <conio.h> 
#include <unistd.h>
#include "stdio.h"
#include "stdlib.h"
#include "math.h"


struct DOSYA{
	//degiskenler
	char* dosyaAdi;
	int satirSayisi;

	//soyut fonksiyon kisi ve oyun sinifinda tanimli
	void (*dosyaAyikla)();
	//fonksiyonlar
	char** (*dosyaOku)(struct DOSYA*);
	void (*delete_DOSYA)(struct DOSYA*);

};
typedef struct DOSYA* Dosya;

Dosya new_Dosya(char*,int);
char** dosyaOku(const Dosya);
void delete_DOSYA(const Dosya);

#endif