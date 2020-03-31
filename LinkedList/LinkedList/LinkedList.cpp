#include<iostream>
#include<stdlib.h>
#include<time.h>
#include<conio.h>
using namespace std;
typedef struct dugum
{
	int deger;
	dugum* sonraki;
};
int sayac = 0;
dugum* kok = NULL;
int veriSayisi = 0;
void menu();
void SonaEkle(dugum*, int);
void Listele(dugum*);
int Sayma(dugum*);
void ArayaEkle(dugum*, int, int);
dugum* IlkdugumSil(struct dugum*);
void CokluSil(dugum*, int, int);
int count(dugum*, int);
void silme(dugum*, int);
void Bol(dugum*);
/**
	@author:		Eda CAM --> e-mail: caam.edaa@gmail.com
	@date:			21 Ekim 2019 Pazartesi
	@brief:			Bu kod parcacigi olusturulan bagli listeyi farkli fonksiyonlarda kullanmaya yarar.
*/
int main()
{
	menu();

	system("pause");
}
/**
	@brief:			Bu fonksiyon ile ana menu olusturulmustur.
	@see main():	Fonksiyonun hangi amacla cagirildigini inceleyiniz.
*/
void menu()
{
	int secim;
	int altsecim;
	do///Menu olusturmayi saglar.
	{
		cout << "\n\n\n\t*********ANA MENU*********\n\n";
		cout << "\n\t [1]	-EKLEME";
		cout << "\n\t [2]	-SILME";
		cout << "\n\t [3]	-BOLME";
		cout << "\n\t [4]	-LISTELEME";
		cout << "\n\t [5]	-SAYMA";
		cout << "\n\t [6]	-CIKIS";
		cout << "\t\n\n\n Yapmak Istediginiz Islemi Seciniz: " << endl;


		int sayi;
		cin >> secim;

		if (secim == 1) {
			cout << "OTOMATIK EKLEME(SONA EKLEME YAPILIR)\t----->(1)" << endl;
			cout << "ISTENILEN YERE EKLEME(EKLENILECEK YERIN POZISYONU DA BELIRTILIR)\t----->(2)" << endl;
			cin >> altsecim;///Ekleme seceneginin alt secenegi olusturulmustur.
			system("cls");
			if (altsecim == 1) {
				cout << "Eklemek istediginiz sayiyi giriniz." << endl;
				cin >> sayi;
				system("cls");
				if (kok == NULL)
				{
					kok = (dugum*)malloc(sizeof(dugum));///Liste bosken ilk elemanin eklenme durumu icin yer bellekte actim.
					kok->deger = sayi;
					kok->sonraki = NULL;

					system("cls");


				}
				else {
					SonaEkle(kok, sayi);///Liste bos olmadiginda sondan ekleme yapilir.

					system("cls");

				}
			}
			else if (altsecim == 2)
			{
				int pozisyon;
				cout << "Araya eklemek istediginiz pozisyonu giriniz." << endl;
				cin >> pozisyon;
				cout << "Araya eklemek istediginiz degeri giriniz." << endl;
				cin >> sayi;
				ArayaEkle(kok, sayi, pozisyon);
				system("cls");
			}

		}
		else if (secim == 2) {
			int pozisyon;
			cout << "NORMAL SILME ISLEMI YAPILIR..\t----->(1)" << endl;
			cout << "BELIRLI POZISYONDAN SONRA ISTENILEN MIKTARDA SAYI SILINIR\t----->(2)" << endl;
			cin >> altsecim;///Silme durumlari icin alt secim olusturuldu.
			system("cls");
			if (altsecim == 1)
			{
				cout << "Silmek istediginiz sayiyi giriniz." << endl;
				cin >> sayi;

				silme(kok, sayi);
				system("cls");
			}
			else if (altsecim == 2)
			{
				cout << "Silmek istediginiz pozisyonu ve miktari giriniz." << endl;
				cin >> pozisyon >> sayi;
				if (pozisyon == 1) ///Coklu silmede bastan baslanarak silinme durumu icin fonksiyon duzenlendi.
				{
					CokluSil(kok, pozisyon, sayi - 1);
					kok = IlkdugumSil(kok);
				}
				else
				{
					CokluSil(kok, pozisyon, sayi);
				}
				system("cls");
			}


		}
		else if (secim == 3)
		{
			Bol(kok);
			system("cls");

		}
		else if (secim == 4) {
			if (kok == NULL)///Listenin bos olmasi durumu icin if blogu kullanildi.
			{
				cout << "Listede veri yok lutfen once veri ekleyin." << endl << endl;
				_getch();
				system("cls");
			}
			else
			{
				Listele(kok);
				_getch();
				system("cls");

			}



		}
		else if (secim == 5) {
			int veriSayisi = Sayma(kok);
			cout << "Listedeki eleman sayisi:" << veriSayisi << endl;
			_getch();
			system("cls");
		}
		else if (secim == 6) {
			exit(0);
		}
	} while (secim != 6);
}
/**
	@brief:			Bu fonksiyon ile sondan eleman eklenebilmektedir.
	@see main():	Fonksiyonun hangi amacla cagirildigini inceleyiniz.
*/
void SonaEkle(dugum* kok, int sayi)
{


	while (kok->sonraki != NULL)
	{
		kok = kok->sonraki;
	}
	kok->sonraki = (dugum*)malloc(sizeof(dugum));
	kok = kok->sonraki;
	kok->deger = sayi;
	kok->sonraki = NULL;
	sayac++;

}
/**
	@brief:			Bu fonksiyon ile bagli liste elemanlari listelenmektedir.
	@see main():	Fonksiyonun hangi amacla cagirildigini inceleyiniz.
*/
void Listele(dugum* kok)
{
	if (kok == NULL) ///Hic verinin bulunmama ihtimaline karsi.
	{
		cout << "HIC ELEMAN BULUNMAMAKTADIR LUTFEN ONCE ELEMAN EKLEYINIZ!!" << endl;
	}
	while (kok != NULL)
	{
		cout << kok->deger << "\t";
		kok = kok->sonraki;
	}
}
/**
	@brief:			Bu fonksiyon ile araya ekleme yapilmaktadir.
	@see main():	Fonksiyonun hangi amacla cagirildigini inceleyiniz.
*/
void ArayaEkle(dugum* kok, int sayi, int pozisyon)
{
	dugum* tutan = (dugum*)malloc(sizeof(dugum));
	Sayma(kok);
	if (kok == NULL)
	{
		cout << "Listede eleman yok araya ekleme yapilammaz" << endl;
		menu();
	}
	else if (pozisyon > veriSayisi - 1)///Var olan pozisyondan fazla pozisyon girilme durumu icin uyari.
	{
		cout << "Istediginiz aralik bulunmamaktadir bu nedenle sona ekleme yapilmaktadir." << endl;
		SonaEkle(kok, sayi);
		menu();
	}
	for (int i = 0; i <= pozisyon - 2; i++)
	{

		kok = kok->sonraki;
	}
	if (kok != NULL)
	{
		tutan->sonraki = kok->sonraki;
		kok->sonraki = tutan;
		tutan->deger = sayi;
	}
	sayac++;
}

/**
	@brief:			Bu fonksiyon ile istenen eleman silinmektedir.
	@see main():	Fonksiyonun hangi amacla cagirildigini inceleyiniz.
*/
void silme(dugum* k, int silinecekdeger)
{
	int bayrak = 0; ///Silmek istenen elemanin sistem uzerinde var olup olmadigini tutmak icin
					/// dugum * k olarak alinmistir cunku kok degeri evrensel oldugundan kok olarak yazilmasi basa ekleme ve silme islemleri icin hataya sebebiyet veriyor.

	while (k != NULL) ///ilk elemani silmek gerekirse.
	{
		dugum* gecici2;
		gecici2 = k; ///Olusturulan adres gonderilen baslangic adresine esitlenir.
		if (gecici2->deger == silinecekdeger)
		{
			k = k->sonraki; ///k nin gosterdigi adresi bir ilerisine esitlenir.
			free(gecici2);  ///gecici2 nin tutugu ilk eleman silinir. 
			kok = k;        ///yeni ilk sayi atanir.
			bayrak = 1;     ///Silme isleminin gerceklesmis oldugunu tutar

		}
		else
		{
			break;
		}
	}
	///Butun degerleri kontrol edebilmek icin ic ice iki while kullanildi.
	while (k != NULL && k->sonraki != NULL)///En basa k!=NULL koydum cunku yerlerini degistirince sistem kontrol ediyor ve hatta veriyor.
	{                                      ///k!=NULL kontrol etmesinin sebebi eger eleman yoksa eleman yok uyarisini vermesini sagliyor.
		dugum* gecici = k;

		while (k->sonraki != NULL && k->sonraki->deger != silinecekdeger)
		{
			k = k->sonraki;
			gecici = gecici->sonraki;

		}
		if (gecici->sonraki == NULL && bayrak == 0)  ///Silinmek istenen degerin olmadigi durum icin.
		{
			cout << "Boyle bir deger yoktur" << endl;
			_getch();
			break;
		}
		if (gecici->sonraki == NULL && bayrak == 1)///NULL u gordukten sonra dongunun devam etmesini onlemek icin. 
		{
			break;
		}
		gecici = gecici->sonraki;
		k->sonraki = k->sonraki->sonraki; //Silinicek verinin bagini koparip sonraki veriye baglanma islemi.
		free(gecici);    ///Silinicek veri gecici sayesinde tutulup silinir.
		bayrak = 1;      ///silinme isleminin yapilmis oldugunu tutar.
	}
	if (k == NULL)
	{
		if (bayrak == 0)///hic eleman yoksa ve bunun nedeni ekleme yapilmamis olmasiysa uyari verilir.
		{
			cout << "HIC ELEMAN BULUNMAMAKTADIR LUTFEN ONCE ELEMAN EKLEYINIZ!!" << endl;
			_getch();

		}

	}

}
/**
	@brief:			Bu fonksiyon ile coklu silme sirasinda ilk elemanin silinmesi saglanmaktadir.
	@see main():	Fonksiyonun hangi amacla cagirildigini inceleyiniz.
*/
dugum* IlkdugumSil(struct dugum* kok)
{
	if (kok == NULL)
		return NULL;

	dugum* tutan = kok;
	kok = kok->sonraki;

	delete tutan;

	return kok;
}
/**
	@brief:			Bu fonksiyon ile istenen pozisyondan itibaren coklu silme yapilmaktadir.
	@see main():	Fonksiyonun hangi amacla cagirildigini inceleyiniz.
*/
void CokluSil(dugum* kok, int pozisyon, int sayi)
{
	dugum* suanki = kok, * t;
	int i;
	for (i = 1; i < pozisyon - 1 && suanki != NULL; i++)///kokun silinecek yere kadar ilerlemesini saglar.
		suanki = suanki->sonraki;

	if (suanki == NULL)
		return;

	t = suanki->sonraki;
	for (i = 1; i <= sayi && t != NULL; i++)///Istenilen sayi kadar silinmesini saglar.
	{
		dugum* tutan = t;
		t = t->sonraki;
		free(tutan);
	}

	suanki->sonraki = t;

}
/**
	@brief:			Bu fonksiyon ile liste istenen bagdan ikiye bolunur ve secilen kisim ana liste olur.
	@see main():	Fonksiyonun hangi amacla cagirildigini inceleyiniz.
*/
void Bol(dugum* h)
{
	dugum* tutan = h;
	int n, k;
	cout << "Bolmek istediginiz bagi giriniz: ";
	cin >> n;
	sayac = Sayma(h);
	if (n > 0 && n < sayac)
	{
		cout << "1.liste" << endl;
		dugum* tutan1 = h;
		for (int i = 1; i <= n; i++)///Bolunen ilk kisim tutan1e atanir.
		{
			cout << tutan->deger << " ";
			tutan = tutan->sonraki;
		}
		dugum* tutan2 = tutan;
		cout << endl << "2.liste" << endl;
		for (int i = n + 1; i <= sayac; i++)///Bolunen ikinci kisim tutan2ye atanir.
		{
			cout << tutan->deger << " ";
			tutan = tutan->sonraki;
		}
		cout << endl << "Hangi liste ile devam etmek istiyorsun(1-2): ";
		cin >> k;
		if (k == 1)
		{
			CokluSil(kok, n + 1, sayac - n);///ikinci liste silinir.

		}
		else if (k == 2)
		{
			for (int i = 0; i < n; i++) ///ilk liste silinir.
			{
				if (kok == NULL)
					break;


				dugum* tutan3 = kok;
				kok = kok->sonraki;

				delete tutan3;
			}
		}
	}

}

/**
	@brief:			Bu fonksiyon ile listedeki eleman sayisi sayilir.
	@see main():	Fonksiyonun hangi amacla cagirildigini inceleyiniz.
*/
int  Sayma(dugum* kok)
{
	veriSayisi = 0;
	dugum* tutan = kok;
	while (tutan != NULL)
	{
		tutan = tutan->sonraki;
		veriSayisi++;
	}
	return veriSayisi;

}
