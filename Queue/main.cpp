#include<iostream>
#include"BankQueue.h"///Kuyruk veri yapisi fonksiyonlarinin kullanilabilmesi icin ekleme islemi yapilmistir.
using namespace std;
/**
	@author:		Eda CAM --> e-mail: caam.edaa@gmail.com
	@date:			2 Kasim 2019 Cumartesi
	@brief:			Bu kod parcacigi banka simulasyonunda kuyruk foksiyonlarini gerceklemeye yarar.
*/
int main()
{
	BankQueue sira;///Queue classinin kullanilabilmesi icin bu turde sira degiskeni olusturulmustur.

	int secim;

	do ///Menu yapisi olusturulmustur.
	{


		cout << "Siraya musteri eklemek icin \t\t\t\t----> (1)" << endl;
		cout << "Siradan musteri silmek icin \t\t\t\t----> (2)" << endl;
		cout << "Siradaki musterilerin bilgilerini listelemek icin \t----> (3)" << endl;
		cout << "Siradaki musterilerin sayisini gormek icin \t\t----> (4)" << endl;
		cout << "Cikis yapmak icin \t\t\t\t\t----> (0)" << endl;
		cin >> secim;

		if (secim < 0 || secim>5)
		{
			cout << "hatali giris." << endl;
			continue;
		}

		if (secim == 1)
		{
			int no;
			cout << endl << "Ekleme yapilacak musterinin musteri numarasini giriniz" << endl;
			cin >> no;

			cout << endl;
			sira.enQueue(no);

		}
		else if (secim == 2)
		{
			sira.deQueue();
		}
		else if (secim == 3)
		{
			sira.display();

		}
		else if (secim == 4)
		{
			sira.Counter();
		}
	} while (secim != 0);


	system("pause");
}

