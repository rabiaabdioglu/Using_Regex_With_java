#include "Kisi.h"



Kisi new_KISI(char **isim,double **bakiye,double **oran,int **sayi,boolean **OyundaMi,int uzunluk){
		Kisi this;
		//kisi sınıfı icin bellek tahsisi
		this=(Kisi)malloc(sizeof(struct KISI));

		//degiskenler
		this->isim  =  isim;
		this->bakiye  =  bakiye;
		this->oran  =  oran;
		this->sayi  =  sayi;
		this->OyundaMi  =  OyundaMi;
		this->uzunluk =uzunluk;
		//fonksiyonlar
		this->kisiSayisi=&kisiSayisi;
		this->bakiyeGuncelle=&bakiyeGuncelle;
		this->delete_KISI  =  &delete_KISI;
		this->enZenginBul=&enZenginBul;

		//dosya islemleri
		this->dosya2 = new_Dosya("Kisiler",0);
		this->dosya2->dosyaAyikla = &dosyaAyikla2;
		

		this->dosya2->dosyaAyikla(this);
		//ayiklama sonrası dosyada sınıfındaki bellek ayırmaları iade ediliyor 
		this->dosya2->delete_DOSYA(this->dosya2);

return this;
}
//oyunda her tur bakiyeler guncellenir
void bakiyeGuncelle	(const Kisi this,double** guncelBakiyeler){
		int x=this->uzunluk;

		for (int i = 0; i <x; ++i)
			this->bakiye[i]=(double*)guncelBakiyeler[i];

}

//oyuna girebilen kisi sayisini dondurur
int kisiSayisi(const Kisi this){
		int sayac = 0;	 
		int x=this->uzunluk;
		float y;

			  for (int i  =  0; i <x; i++) {
					y=atof((char*)this->bakiye[i]);

					//kisi bakiyesi 1000 altında iste oyundami degiskeni false olur
					if(y<1000) 	this->OyundaMi[i] = (boolean*)0;		
					else sayac++;
					
}


	
return sayac;
}

//en zengin kisinin indexini bulur
int enZenginBul(const Kisi this){
	
	int index = 0;//en yüksek bakiyeli kişinin indexi
		
		for (int i  =  0; i <this->uzunluk; i++) {
			if(atof((char*)this->bakiye[index])<atof((char*)this->bakiye[i]))   index = i; 		

		}
return index;
}




void dosyaAyikla2(const Kisi this){
		//dosya icerigini tutar char pointer
		char** icerik;
		icerik=this->dosya2->dosyaOku(this->dosya2);
		//ayrilan satir parcalarini tutar
		char *parca;
		
		int i=0;
		//uzunluk degiskenine dosya2 de hesaplanan kisiuzunlugu atılır
		this->uzunluk=this->dosya2->satirSayisi ;

		int uzunluk=this->uzunluk;

		//her degisken icin bellek alanı ayrılıyor
		this->isim=calloc(uzunluk,sizeof(char*));

		this->bakiye=calloc(uzunluk,sizeof(double*));

		this->oran=calloc(uzunluk,sizeof(double*));

		this->sayi=calloc(uzunluk,sizeof(int*));

		this->OyundaMi=calloc(uzunluk,sizeof(int*));

			for(i=0;i<uzunluk;i++)
			{
			this->isim[i]=calloc(30,sizeof(char));
			this->bakiye[i]=calloc(20,sizeof(double));
			this->oran[i]=calloc(5,sizeof(double));
			this->sayi[i]=calloc(3,sizeof(int));
			this->OyundaMi[i]=calloc(6,sizeof(int));
				
			}


		i=0;

			while(i<=uzunluk){

			//strtok ile her satir # ile parcalaniyor ve sirayla degiskenlere atiliyor
			parca = strtok(icerik[i],"#");
			this->isim[i] = parca;

			parca = strtok (NULL, "#");
			this->bakiye[i] = (double*)parca;

			parca = strtok (NULL, "#");
			this->oran[i] = (double*)parca;

			parca = strtok (NULL, "#");
			this->sayi[i] = (int*)parca;

			//her kisi icin true 
			this->OyundaMi[i]=(boolean*)true;
			i++;

			}

}
void delete_KISI(const Kisi this){
		//kisi yoketmeden once ayrılan bellekler iade ediliyor.
		if(this  ==  NULL) return;

		free(this->isim);
		free(this->bakiye);
		free(this->OyundaMi);
		free(this->oran);
		free(this->sayi);
		free(this);

}
