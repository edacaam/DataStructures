#include "BankQueue.h"
BankQueue::BankQueue() ///Baslangicta on ve arka degerleri -1den baslatilmistir.
{
	front = -1;
	rear = -1;
}
BankQueue::~BankQueue() ///Baslangicta on ve arka degerleri -1den baslatilmistir.
{
	
}
/**
@brief:			Bu fonksiyon ile Overflow hatasinin kontrol edilmesi saglanmisitr.
@see main():	Fonksiyonun hangi amacla cagirildigini inceleyiniz.
*/
bool BankQueue::isFull()
{
	if (front == 0 && rear == size - 1)///Dizinin dolu olmasi durumunu kontrol edilmistir.
	{
		return true;
	}
	return false;
}
/**
@brief:			Bu fonksiyon ile Underflow hatasinin kontrol edilmesi saglanmisitr.
@see main():	Fonksiyonun hangi amacla cagirildigini inceleyiniz.
*/
bool BankQueue::isEmpty() {
	if (front == -1)///Dizinin bos olmasi durumu kontrol edilmistir.
		return true;
	else
		return false;
}
/**
@brief:			Bu fonksiyon ile kuyruga musteri eklenmesi saglanmisitr.
@see main():	Fonksiyonun hangi amacla cagirildigini inceleyiniz.
*/
void BankQueue::enQueue(int element) {
	if (isFull())
	{
		cout << endl << "Queue is full" << endl;

	}
	else
	{
		if (front == -1)///Bos bir kuyruga musteri eklenmesi durumu icin bas 0a getirilmistir.

			front = 0;

		if (rear == size - 1)///Dolu olmayan bir kuyrukta arkanin son indekste olmasi durumu icin dairesel dizi kullanilmasi saglanmistir.
		{
			rear = 0;
			items[rear] = element;
			count++;
		}
		else///Normal ekleme yapilmistir.
		{
			items[++rear] = element;
			count++;
		}
	}


}
/**
@brief:			Bu fonksiyon ile kuyruktan musteri silinmesi saglanmisitr.
@see main():	Fonksiyonun hangi amacla cagirildigini inceleyiniz.
*/
void BankQueue::deQueue()
{
	int element;
	if (isEmpty()) {
		cout << "Queue is empty" << endl;
	}
	else {
		element = items[front];
		if (front >= rear)///Tek musteri olmasi durumunda kuyrugun bosaltilmasi saglanmistir.
		{
			front = -1;
			rear = -1;
		}
		else {
			front++;
		}
		count--;
		cout << endl << "Deleted -> " << element << endl;

	}
}
/**
@brief:			Bu fonksiyon ile kuyruktaki musterilerin listelenmesi saglanmisitr.
@see main():	Fonksiyonun hangi amacla cagirildigini inceleyiniz.
*/
void BankQueue::display()
{
	if (!isEmpty())
	{
		for (int i = front; i <= rear; i++)
			cout << items[i] << " ";
		cout << endl;
	}
	else
		cout << "Queue is Empty!" << endl;
}
/**
@brief:			Bu fonksiyon ile kuyruktaki musteri sayisinin hesaplanmasi saglanmisitr.
@see main():	Fonksiyonun hangi amacla cagirildigini inceleyiniz.
*/
void BankQueue::Counter()
{
	cout << count << endl;
}
