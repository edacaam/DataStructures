#include <iostream>
#include "Stack.h"

using namespace std;
/**
	@brief:			Bu fonksiyon yapici fonksiyondur.
	@see main():	Fonksiyonun hangi amacla cagirildigini inceleyiniz.
	*/
Stack::Stack(void)
{
}
/**
	@brief:			Bu fonksiyon yikici fonksiyondur.
	@see main():	Fonksiyonun hangi amacla cagirildigini inceleyiniz.
	*/
Stack::~Stack(void)
{
}
/**
	@brief:			Bu fonksiyon yiginin basindaki veriyi dondurur.
	@see main():	Fonksiyonun hangi amacla cagirildigini inceleyiniz.
	*/
double Stack::Top()
{
	if (isEmpty())
		cout << "Error: the stack is empty." << endl;
	else
		return head->data;
}
/**
	@brief:			Bu fonksiyon yiginin basina veri eklenmesini saglar.
	@see main():	Fonksiyonun hangi amacla cagirildigini inceleyiniz.
	*/
void Stack::Push(const double data)
{
	insertNode(data);
}
/**
	@brief:			Bu fonksiyon yiginin basindan veri silinmesini saglar.
	@see main():	Fonksiyonun hangi amacla cagirildigini inceleyiniz.
	*/
double Stack::Pop()
{
	if (isEmpty())
		cout << "Error: the stack is empty." << endl;
	else
	{
		double val = head->data;
		deleteNode();
		return val;
	}
}
/**
	@brief:			Bu fonksiyon yigindaki verilerin goruntulenmesini saglar.
	@see main():	Fonksiyonun hangi amacla cagirildigini inceleyiniz.
	*/
void Stack::DisplayStack()
{
	displayList();
}
/**
	@brief:			Bu fonksiyon yiginin bosaltilmasini saglar.
	@see main():	Fonksiyonun hangi amacla cagirildigini inceleyiniz.
	*/
void Stack::Delete()
{
	Clear();
}
