#include <iostream>
#include "List.h"

using namespace std;
/**
	@brief:			Bu fonksiyon yapici fonksiyondur..
	@see main():	Fonksiyonun hangi amacla cagirildigini inceleyiniz.
	*/
List::List(void)
{
	head = NULL;
}
/**
	@brief:			Bu fonksiyon listenin bos mu oldugunu kontrol eder.
	@see main():	Fonksiyonun hangi amacla cagirildigini inceleyiniz.
	*/
bool List::isEmpty()
{
	return head == NULL;
}
/**
	@brief:			Bu fonksiyon ile listenin basina veri ekleme yapilir.
	@see main():	Fonksiyonun hangi amacla cagirildigini inceleyiniz.
	*/
void List::insertNode(double data)
{

	Node* newNode = new Node();
	newNode->data = data;
	newNode->nextNode = head;
	head = newNode;
}
/**
	@brief:			Bu fonksiyon ile listenin basinan veri silinir.
	@see main():	Fonksiyonun hangi amacla cagirildigini inceleyiniz.
	*/
void List::deleteNode()
{
	head = head->nextNode;
}
/**
	@brief:			Bu fonksiyon ile liste bosaltilir.
	@see main():	Fonksiyonun hangi amacla cagirildigini inceleyiniz.
	*/
void List::Clear()
{
	head = NULL;
}
/**
	@brief:			Bu fonksiyon ile listedeki veriler goruntulenir ve veri sayisi hesaplanir.
	@see main():	Fonksiyonun hangi amacla cagirildigini inceleyiniz.
	*/
void List::displayList()
{
	Node* curNode = head;
	int nodeCount = 0;
	while (curNode)
	{
		cout << curNode->data << endl;
		curNode = curNode->nextNode;
		nodeCount++;
	}
	cout << "Total " << nodeCount << " node(s)" << endl;
}
