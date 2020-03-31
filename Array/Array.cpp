#include<iostream>
#include<stdlib.h>
#include<time.h>
#include<conio.h>
#include<iomanip>
using namespace std;
/**
*\brief struct Ogrenci
*\detail Ogrenci  bilgilerinin	tutulmasi	icin	bir	struct	tanimladim.
*/
struct Ogrenci
{
	int	no;
	int	puan;
	string	isim;
};
/**
*\brief fn	string	RandomString()
*\detail Rastgele Ogrenci  isimleri	atanmasini	saglayan	fonksiyon.
*/
string	RandomString()
{
	char	alfabe[26] = { 'a','b','c','d','e','f','g',///Ogrenci adlarinda bulunabilecek karakterleri tanimladim.
						 'h','i','j','k','l','m','n',
						 'o','p','q','r','s','t','u',
						 'v','w','x','y','z' };

	string	ras;
	for (int i = 0; i < 5; i++)
		ras = ras + alfabe[rand() % 26];

	return ras;
}
/**
*\brief fn	void Random(struct Ogrenci*	DynArray,int size)
*\detail Random puan ve isim atamak icin fonksiyon.
*/
void Random(Ogrenci* DynArray, int size)
{
	srand(time(NULL));

	for (int i = 0; i < size; i++)
	{
		DynArray[i].puan = rand() % 100;
	}
	for (int i = 0; i < size; i++)
	{
		DynArray[i].isim = RandomString();
	}
	for (int i = 0; i < size; i++)
	{
		DynArray[i].no = 1000 + i;
	}

}
/**
*\brief fn	void m(struct Ogrenci*	DynArray,int size)
*\detail Min max ve ortalama degerlerini hesaplayan	fonksiyon.
*/
void m(struct Ogrenci* DynArray, int	size)
{
	int	min = DynArray[0].puan;///Zaman karmasikligini en aza indirmek icin ic ice dongu yerine if kullandim.
	for (int i = 0; i < size; i++)
	{
		if (DynArray[i].puan < min)
			min = DynArray[i].puan;
	}
	for (int i = 0; i < size; i++)
	{
		if (min == DynArray[i].puan)
			cout << "minmum:" << min << "(" << DynArray[i].no << " numarali " << DynArray[i].isim << " isimli ogrenci)" << endl;
	}
	int max = DynArray[0].puan;
	for (int i = 0; i < size; i++)
	{
		if (DynArray[i].puan > max)
		{
			max = DynArray[i].puan;
		}
	}
	for (int i = 0; i < size; i++)
	{
		if (max == DynArray[i].puan)
		{
			cout << "maximum:" << max << "(" << DynArray[i].no << " numarali " << DynArray[i].isim << " isimli ogrenci)" << endl;
		}
	}

	float ortalama;
	int sum = 0;
	for (int i = 0; i < size; i++)
	{
		sum = sum + DynArray[i].puan;
	}
	ortalama = (float)sum / size;
	cout << "ortalama" << ortalama << endl;
}
/**
*\brief fn	void partition(struct Ogrenci*	DynArray,int baslangic,int son)
*\detail Arrayi pivota gore sag ve sol parcalara ayiran fonksiyon.
*/
int partition(Ogrenci* DynArray, int baslangic, int son)
{
	int pivot = DynArray[son].puan;


	int index = baslangic;
	int i, j, no;
	string isim;

	

	for (i = baslangic; i < son; i++)
	{
		if (DynArray[i].puan >= pivot)//Pivota gore sag ve sol gruplara atanacak sekilde degisim operasyonu uygulandi.
		{

			j = DynArray[i].puan;
			no = DynArray[i].no;
			isim = DynArray[i].isim;
			DynArray[i].puan = DynArray[index].puan;
			DynArray[i].no = DynArray[index].no;
			DynArray[i].isim = DynArray[index].isim;
			DynArray[index].puan = j;
			DynArray[index].no = no;
			DynArray[index].isim = isim;
			index++;
		}
	}
	
	j = DynArray[son].puan;
	no = DynArray[son].no;
	isim = DynArray[son].isim;
	DynArray[son].puan = DynArray[index].puan;
	DynArray[son].no = DynArray[index].no;
	DynArray[son].isim = DynArray[index].isim;
	DynArray[index].puan = j;
	DynArray[index].no = no;
	DynArray[index].isim = isim;

	
	return index;
}
/**
*\brief fn	void Quicksort(struct Ogrenci*	DynArray,int baslangic,int son,int k)
*\detail Ayrilan arrayin quicksort yapilarak azalan siradaki k.elemaninin bulunmasini saglayan fonksiyon.
*/
void Quicksort(Ogrenci* DynArray, int baslangic, int son, int k)//Quick sort kullanarak zaman karmasikligini olabildigince aza indirmeyi hedefledim.
{
	if (baslangic < son)
	{
		int index = partition(DynArray, baslangic, son);
		Quicksort(DynArray, baslangic, index - 1, k);
		Quicksort(DynArray, index + 1, son, k);
	}


}
/**
*\brief fn	void liste(struct Ogrenci*	DynArray,int size)
*\detail Listeleme yapmayi	saglayan fonksiyon.
*/
void liste(Ogrenci* DynArray, int size)
{
	cout << "Ogrenci No" << "\t" << "Isim" << "\t" << "Not" << endl;
	cout << "----------" << "\t" << "----" << "\t" << "---" << endl;
	for (int i = 0; i < size; i++)
	{
		cout << DynArray[i].no << "\t\t";
		cout << DynArray[i].isim << "\t";
		cout << DynArray[i].puan << endl;
	}
}
/**
*\brief fn	void degistir(struct Ogrenci*	DynArray,int size)
*\detail Not degistirilmesini saglayan	fonksiyon.
*/
void degistir(Ogrenci* DynArray, int size)
{
	int no;
	int yeni;
	cout << "Ogrenci no giriniz" << endl;
	cin >> no;
	for (int i = 0; i < size; i++)
	{
		if ((DynArray[i].no == no))//Ogrencinin diger bilgilerine ulasabilmek icin if kullandim.
		{
			cout << DynArray[i].no << "(" << DynArray[i].isim << ") ogrencisi icin yeni notu (" << DynArray[i].puan << ") giriniz.." << endl;
			cin >> yeni;
			DynArray[i].puan = yeni;
		}
	}
}
/**
*\brief fn	void menu(struct Ogrenci*	DynArray,int size)
*\detail Menuyu	olusturan	fonksiyon.
*/
void menu(struct Ogrenci* DynArray, int size)
{
	cout << "\n\n\n\t*********ANA MENU*********\n\n";
	cout << "\n\t [L]	-Listeleme";
	cout << "\n\t [D]	-Degistirme";
	cout << "\n\t [I]	-Istatistik";
	cout << "\n\t [E]	-Cikis";
	cout << "\t\n\n\nIslemi Seciniz: " << endl;
	char secim;
	do
	{
		secim = _getch();
		if (secim == 'L' || secim == 'l') {
			liste(DynArray, size);
		}
		else if (secim == 'D' || secim == 'd') {
			degistir(DynArray, size);
		}
		else if (secim == 'I' || secim == 'i') {
			cout << "\n\t [m] -Min-Max-Ortalama";
			cout << "\n\t [k] -K.en buyuk" << endl;
			secim = _getch();
			if (secim == 'm' || secim == 'M')
				m(DynArray, size);
			else if (secim == 'k' || secim == 'K')
			{
				int k;
				cout << "k degerini giriniz:" << endl;
				cin >> k;

				Quicksort(DynArray, 0, size - 1, k);
				cout << k << ". siradaki en buyuk puan:" << DynArray[k - 1].puan << "(" << DynArray[k - 1].no << " numarali " << DynArray[k - 1].isim << " isimli ogrenci)" << endl;
			}
		}
		else if (secim == 'E' || secim == 'e') {
			exit(0);
		}
	} while (secim != 'E' || secim != 'e');//E harfini cikis olarak kullandim.
}
/**
*\brief	Not	Simulasyonu
*\Author	Eda	Cam	152120171037
*\Date	14.10.19
*/
int main()
{
	int size;
	cout << "Kac cogrenci var?" << endl;
	cin >> size;
	while (cin.fail()) //Eðer kullanýcý sayi girmezse.
	{
		cout << "\tHatali giris" << endl;
		cin.clear();
		cin.ignore();
		cout << "\tLutfen dizinin kac eleman olmasini istiyorsaniz o sayiyi girin" << endl;
		cin >> size;
		system("cls");
	}
	Ogrenci* DynArray;//Struct verilerinin pointer kullanarak arrayda tutulmasýný sagladim.
	DynArray = new (nothrow) Ogrenci[size];//Arrayin dinamik bellekte tutulmasini sagladim.
	Random(DynArray, size);
	menu(DynArray, size);

	system("pause");
}
