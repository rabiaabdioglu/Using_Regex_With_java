#include "Oyun.h"
#include "string.h"
#include <math.h>
#include <conio.h> 
#include <unistd.h>

 
Oyun new_Oyun(double masaBakiye,int** sansliSayi,int turSayisi,int enZengin,int simdikiSansliSayi){
		Oyun this;
		//oyun sinifi icin bellek tahsisi
		this=(Oyun)malloc(sizeof(struct OYUN));
		//degiskenler
		this->masaBakiye = masaBakiye;
		this->sansliSayi = sansliSayi;
		this->turSayisi = turSayisi;
		this->enZengin = enZengin;
		this->simdikiSansliSayi=simdikiSansliSayi;
		//fonksiyon gostericileri
		this->masaGuncelle=&masaGuncelle;
		this->oyunBasla=&oyunBasla;
		this->yaz=&yaz;
		this->delete_Oyun=&delete_Oyun;

		//dosya islemleri
		this->dosya = new_Dosya("Sayilar",0);
		this->dosya->dosyaAyikla=&dosyaAyikla1;

		//kisi olusturma
		this->kisi = new_KISI(NULL,NULL,NULL,NULL,NULL,0);
		
		this->dosya->dosyaAyikla(this);
		//ayiklama sonrasi dosyada sinifindaki bellek ayirmalari iade ediliyor 
		this->dosya->delete_DOSYA(this->dosya);


return this;
}

int uzunluk;

void oyunBasla(const Oyun this){
		
	
	//	system("CLS");

		this->masaBakiye = 0;
		this->turSayisi = 0;
		double toplam ;
		float yatirilan_para = 0;
		float x;
		int i,j;
		
		//guncel bakiyeler icin ayri bir dizi olusturuluyor. Kisi sinifinda bakiyeler guncellenecek
		double** guncelBakiyeler;
		guncelBakiyeler=calloc(this->kisi->uzunluk,sizeof(double*));

		//guncel bakiyeler icin bellek tahsisi.
		for( i=0;i<this->kisi->uzunluk;i++) guncelBakiyeler[i]=calloc(10,sizeof(double));
			
		


		//kisi sayisi  fonksiyonu 1000 bakiye ustundeki kisi sayisini dondurecek oyun 1 kisi kalana kadar devam eder.
		while(this->kisi->kisiSayisi(this->kisi)>=1){		

			//sansli sayi kadar donecek olan dongu  - her dongu tur demek
			for ( i  =  0; i<uzunluk; i++) {
			//toplam degiskeni tur sonuna kadar olan kar zarari tutar masa bakiyesini gunceller
				toplam=0;
				if(this->kisi->kisiSayisi(this->kisi)>=1){
					//Her tur kisiler uzunlugu kadar doner
						for ( j  =  0; j <this->kisi->uzunluk;j++) { 

							//eger kisi 1000 bakiyenin altinda degil ise oyundami degiskeni true olur
							if((boolean)(this->kisi->OyundaMi[j]) == (boolean)1) {
								
							//kisilerin parasinin ne kadarini yatirdigini tutar
							yatirilan_para = atof((char*)this->kisi->bakiye[j])*atof((char*)this->kisi->oran[j]);
									
									//kullanicinin oynadigi sansli sayi değilse yatirdiği para gider
									if(atof((char*)this->kisi->sayi[j])!=atof((char*)this->sansliSayi[i])) {  
										
										//x degiskeni kisinin guncel bakiyesini tutar
										x=atof((char*)this->kisi->bakiye[j])-(yatirilan_para);	
										//guncel bakiyeler listesine atilir
										sprintf((char*)guncelBakiyeler[j],"%.6f",x);
										//masaya gelen  para
									//	printf("\n%s  -  ( %s  *  %s  ) =  %s ",this->kisi->bakiye[j],this->kisi->bakiye[j],this->kisi->oran[j],guncelBakiyeler[j]);
										toplam+=yatirilan_para;


									}
									//sansli sayi ise kisi 10 kat kazanir
									else {
								
										//x degiskeni kisinin guncel bakiyesini tutar
										x=atof((char*)this->kisi->bakiye[j])-(yatirilan_para)+(yatirilan_para*10);
										//guncel bakiyeler listesine atilir
										sprintf((char*)guncelBakiyeler[j],"%.6f",x);
										//masadan giden para
										toplam=toplam-(yatirilan_para*10)+(yatirilan_para);
									//	printf("\n%s  -  ( %s  *  %s  ) +   ( %.2f  *  10  )=  %s ",this->kisi->bakiye[j],this->kisi->bakiye[j],this->kisi->oran[j],yatirilan_para,guncelBakiyeler[j]);

									}					
							yatirilan_para=0;
						}


					}			


				//simdiki sansli sayi  ekrana yazdirmak icin
				this->simdikiSansliSayi=atoi((char*)this->sansliSayi[i]);
				//kisiler sinifindaki fonksiyona guncellemek icin yeni bakiyeler yollanir
				this->kisi->bakiyeGuncelle(this->kisi,guncelBakiyeler);
				system("CLS");	
				masaGuncelle(this,toplam);
				sleep(0.99999999999999988888888888888);
				
			}

				
			else break;
			}	

		}			

					
		//oyun bitiminde guncel bakiyeler alani iade ediliyor
free(guncelBakiyeler);
sleep(20);
this->delete_Oyun(this);

}



void masaGuncelle(const Oyun this ,double toplam){
		//oyuna girebilen kisi sayisi
		this->kisi->kisiSayisi(this->kisi);		

		//masanin bakiyesi guncelleniyor
		this->masaBakiye=toplam+this->masaBakiye;
		//tur sayisi artiyor
		this->turSayisi++;
		//en zengin kisiyi bulmak icin kisi sinifindaki fonksiyon cagriliyor

		this->enZengin=this->kisi->enZenginBul(this->kisi);
		//ekrana yazdiriliyor

		yaz(this);


}

int Uzunluk(double deger){
		char str[50];
		sprintf(str,"%lf",deger);
		int uzunluk = strlen(str);

return uzunluk;
}

void yaz(const Oyun this){
		//yazdirma 
		
		if(this->kisi->kisiSayisi(this->kisi)>=1){

		printf("\n\n\n");

		printf("\n\t\t\t##################################################\n\t\t\t##\t\tSANSLI SAYI:  %d",this->simdikiSansliSayi);
		printf("\t\t\t##\n\t\t\t##################################################\n\t\t\t");
		printf("##################################################\n\t\t\t##\t\tTUR:  %d\t\t\t", this->turSayisi);
		printf("##\n\t\t\t## \tMASA BAKIYE: %.2f",this->masaBakiye);
		printf("\t\t##\n\t\t\t##----------------------------------------------##");
		printf("\n\t\t\t##\t\tEN ZENGIN KISI\t\t\t##\n\t\t\t##\t\t%s",this->kisi->isim[this->enZengin]);
		printf("\t\t\t##\n\t\t\t##\tBAKIYESI:  %s\t\t\t##\n\t\t\t##\t\t\t\t\t\t",this->kisi->bakiye[this->enZengin]);
		printf("##\n\t\t\t##################################################\n");

			}
		else	{
		printf("\n\n\n");

		printf("\n\t\t\t##################################################\n\t\t\t##\t\t");
		printf("\t\t\t\t##\n\t\t\t##################################################\n\t\t\t");
		printf("##################################################\n\t\t\t##\t\tTUR:  %d\t\t\t", this->turSayisi);
		printf("##\n\t\t\t## \tMASA BAKIYE: %.2f",this->masaBakiye);
		printf("\t\t##\n\t\t\t##----------------------------------------------##");
		printf("\n\t\t\t##\t\tOYUN BITTI\t\t\t##\n\t\t\t##\t\t\t\t\t\t");
		printf("##\n\t\t\t##\t\t\t\t\t\t##\n\t\t\t##\t\t\t\t\t\t");
		printf("##\n\t\t\t##################################################\n");


		}
}

void dosyaAyikla1(const Oyun this){

		char* parca ;
		char** icerik ;
		icerik=this->dosya->dosyaOku(this->dosya);

		int i=0;

		uzunluk=this->dosya->satirSayisi;

		//her degisken icin bellek alani ayriliyor
		this->sansliSayi=calloc(uzunluk,sizeof(int*));
		this->turSayisi=(int)calloc(20,sizeof(int*));
		this->masaBakiye=(int)calloc(20,sizeof(double*));
		this->enZengin=(int)calloc(20,sizeof(int*));
		this->simdikiSansliSayi=(int)calloc(5,sizeof(int*));

		//sansli sayi icin atama yapiliyor
		for(i=0;i<uzunluk;i++){
		this->sansliSayi[i]=calloc(4,sizeof(int));	}
		i=0;
		//sansli sayilar satir satir aliniyor
		while(i<=uzunluk)
		{
			parca = strtok(icerik[i],"\n");
			this->sansliSayi[i]=(int*)parca;
			
			i++;}


}
void delete_Oyun(const Oyun this ){
		//oyun silmeden once olusturulanlar siliniyor
		if(this  ==  NULL) return;
		free(this->sansliSayi);

		this->kisi->delete_KISI(this->kisi);

		free(this);
}
