#include "Dosya.h"

Dosya new_Dosya(char* dosyaAdi,int satirSayisi){
   Dosya this;
   //dosya icin bellek ayriliyor
   this=(Dosya)malloc(sizeof(struct DOSYA));
   //degiskenler
   this->dosyaAdi = dosyaAdi;
   this->satirSayisi=satirSayisi;
   //fonksiyonlar
   this->dosyaOku = &dosyaOku;
   this->delete_DOSYA  =  &delete_DOSYA;

return this;
}
char** icerik; //delete dosyanın erişebileceği yerde


char ** dosyaOku(const Dosya this){

		int uzunluk =40;
		char satir[uzunluk];
		int satirSayisi=0;
		this->satirSayisi=(int)calloc(5,sizeof(int*));
		int i=0,k=0;
		char yol[20]="";
		char a='*';


		strcat(yol,"./lib/");
		strcat(yol,this->dosyaAdi);
		strcat(yol,".txt");




		//fp2 satir sayisi ogrenmek icin 
		FILE *fp2;
		fp2 = fopen (yol, "r");

		//satir sayisi
		while(a!=EOF) //dosyanın sonuna kadar
		{

			a=fgetc(fp2); //karakter oku


			if(a=='\n') //alt satıra geçme
			{
			satirSayisi++;

			}

		}

		//satir sayisi atanıyor
		this->satirSayisi=satirSayisi;
		//dosya kapan
		fclose(fp2);




		///////////gelen  txt yi, iceriğe satırsatır atmak için 2. kez dosyayı açıyorum

		FILE *fp;
		fp = fopen (yol, "r");
		//dosya ayiklaya gidecek olan icerik icin bellek tahsis ediliyor
		icerik=calloc(satirSayisi,sizeof(char*));

		//satir sayisi kadar bellek alanı atanıyor
		for(i=0;i<=satirSayisi;i++)		icerik[i]=calloc(uzunluk,sizeof(char));
			
		//satir sayisi kadar doner ve satir satir icerige atama yapar
		while(k<=satirSayisi){
			fgets(icerik[k],uzunluk, fp);
			k++;
		}
		//dosya kapan
		fclose(fp);

return icerik;

}
void delete_DOSYA(const Dosya this){
	if(this  ==  NULL) return;
	//önce icerik için ayrılan bellek alanı geri veriliyor.
	free(icerik);
	free(this);

}
